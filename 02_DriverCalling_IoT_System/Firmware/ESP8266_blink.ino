/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  NOTE: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6NThklr7b"
#define BLYNK_TEMPLATE_NAME "Driver calling system"
#define BLYNK_AUTH_TOKEN "zR-xx8PURTohG_DfqOyR8rKtJE8ifOYa"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Albert";
char pass[] = "70893398";
int numberOfConfrimed = 0;
#define requestPin D1
#define confirmedPin D2



void setup() {
  // Debug console
  Serial.begin(9600);
  pinMode(requestPin, INPUT);
  pinMode(confirmedPin, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Blynk.virtualWrite(V0, 0);
}

void loop() {
  Blynk.run();
  if (digitalRead(requestPin) == HIGH) {
    Blynk.virtualWrite(V1, 255);
  } else {
    Blynk.virtualWrite(V1, 0);
  }

  if (digitalRead(confirmedPin) == HIGH) {
    Blynk.virtualWrite(V0, numberOfConfrimed++);
    delay(3000);
  }
}
