#include<ThingSpeak.h>
//include wifi lib
#if defined(ESP32)
#include<WiFi.h>
#elif defined(ESP8266)
#include<ESP8266WiFi.h>
#endif

int pot=A0;

char ssid[] = "OPPO F21 Pro";
char pass[]= "Dhanu2030";

WiFiClient client;

int channelnumber =2036955;
int fieldnumber=1;
char *apikey="ITDW7AYJS1XGZZZD";



void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
ThingSpeak.begin(client);
if(WiFi.status()!=WL_CONNECTED){
  Serial.print("trying to connect to");
  Serial.println(ssid);
  while(WiFi.status()!=WL_CONNECTED){
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(500);
  }
  Serial.print("\n connected");
}
}

void loop() {
  // put your main code here, to run repeatedly:

int potstate;
potstate =analogRead(pot);
Serial.print("pot value = ");
Serial.println(potstate);
delay(100);
ThingSpeak.writeField(channelnumber,fieldnumber,potstate,apikey);
delay(100);
}
