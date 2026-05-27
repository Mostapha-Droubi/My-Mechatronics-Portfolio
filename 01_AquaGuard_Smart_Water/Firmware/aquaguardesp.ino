#define BLYNK_TEMPLATE_ID "TMPL6wrt4oy6z"
#define BLYNK_TEMPLATE_NAME "aquaguard"
#define BLYNK_AUTH_TOKEN "e9f4XoSg7bzybrx0IpCJfCAhCG6yUMJn"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

char ssid[] = "AliNet(03426440)";
char pass[] = "123456789";

SoftwareSerial arduinoSerial(2, 0); // RX = D4, TX = D3

#define RELAY_PIN D1
#define LED_PIN D5

int groundTankLevel = 0;
int turbidityValue = 0;
float phValue = 0;
int roofTankLevel = 0;
int relayState = 0;
bool turbidityNotified = false;
bool phNotified = false;

BLYNK_WRITE(V2) {
  roofTankLevel = param.asInt();
}

void setup() {
  Serial.begin(9600);
  arduinoSerial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.println("ESP8266 Connected to Blynk!");
}

void loop() {
  Blynk.run();
  Blynk.syncVirtual(V2); // Keep tank level updated

  if (arduinoSerial.available()) {
    String message = arduinoSerial.readStringUntil('\n');
    message.trim();

    if (message.startsWith("WATER:")) {
      groundTankLevel = message.substring(6).toInt();
      Blynk.virtualWrite(V1, groundTankLevel);
      Serial.println("Water Level: " + String(groundTankLevel));
    } 
    
    else if (message.startsWith("TURB:")) {
      turbidityValue = message.substring(5).toInt();
      Blynk.virtualWrite(V5, turbidityValue);
      Serial.println("Turbidity: " + String(turbidityValue));

      if (turbidityValue > 1100 && !turbidityNotified) {
        Blynk.logEvent("turbidity_alert", "⚠️ Water is Dirty (Turbidity > 1100 NTU)");
        turbidityNotified = true;
      } else if (turbidityValue <= 1100) {
        turbidityNotified = false;
      }
    }

    else if (message.startsWith("PH:")) {
      phValue = message.substring(3).toFloat();
      Blynk.virtualWrite(V6, phValue);
      Serial.println("pH Value: " + String(phValue));

      // pH alert logic
      if ((phValue < 6.5 || phValue > 7.9) && !phNotified) {
        Blynk.logEvent("ph_alert", "⚠️ pH out of safe range! Current pH: " + String(phValue));
        phNotified = true;
      } else if (phValue >= 6.5 && phValue <= 7.9) {
        phNotified = false;
      }
    }

    // Relay control logic
    if (groundTankLevel > 10 && (roofTankLevel >= 70 && roofTankLevel <= 90)) {
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(LED_PIN, HIGH);
      relayState = 1;
      Serial.println("Motor ON");
    } else {
      digitalWrite(RELAY_PIN, LOW);
      digitalWrite(LED_PIN, LOW);
      relayState = 0;
      Serial.println("Motor OFF");
    }

    Blynk.virtualWrite(V3, relayState);
  }
}
