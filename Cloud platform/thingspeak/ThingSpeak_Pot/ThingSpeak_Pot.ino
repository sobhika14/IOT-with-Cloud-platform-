#include <ThingSpeak.h>

// Include WiFi library
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif

int pot=A0;

char ssid[] = "OnePlus 8 Pro";
char pass[] = "hello1411";

WiFiClient client;

int channelnumber=2036955;
int fieldnumber=1;
char *apikey="ITDW7AYJS1XGZZZD";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ThingSpeak.begin(client);

  if (WiFi.status() != WL_CONNECTED){
    Serial.print("trying to connect to ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid,pass);
      Serial.print(".");
      delay(5000);
      }
    Serial.print("\n Connected");  
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  int potState;
  potState = analogRead(pot);
  Serial.print("pot value = ");
  Serial.println(potState);
  delay(1000);
  ThingSpeak.writeField(channelnumber, fieldnumber, potState, apikey);
  delay(1000);
}
