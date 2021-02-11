#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int pirPin = 14;
int relayPin = 12;
int pirValue;

char auth[] = "d16a1dbf5a8640f688017bfd8b969aac";
char ssid[] = "ASUS";
char pass[] = "asus123asus";

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void pirSensor()
{
  pirValue = digitalRead(pirPin);
  Blynk.virtualWrite(V0, pirValue);
}

void loop()
{
  Blynk.run();
  pirSensor();
  if (pirValue == HIGH)
  {
    digitalWrite(relayPin, LOW);
  }
  
  else
  digitalWrite(relayPin, HIGH); 
}
