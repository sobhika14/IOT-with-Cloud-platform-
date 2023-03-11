#define BLYNK_TEMPLATE_ID "TMPLOqIJBXzD"
#define BLYNK_TEMPLATE_NAME "analog"
#define BLYNK_AUTH_TOKEN "DM8feHC_xa6kUIn5ErWYR0R49lD1WURQ"
#define BLYNK_PRINT Serial


#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

char auth[]=BLYNK_AUTH_TOKEN;
char ssid[]="OnePlus 8 Pro";
char pass[] = "hello1411";

void setup()
{
  pinMode(A0,INPUT);
  Serial.begin(115200);
  Blynk.begin(auth,ssid,pass);
}

void loop()
{
  Blynk.run();
    BLYNK_WRITE(A0);
    delay(200);
    }
