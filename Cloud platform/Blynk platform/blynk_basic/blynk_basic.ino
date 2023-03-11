#define BLYNK_TEMPLATE_ID "TMPL6eE3liLs"
#define BLYNK_TEMPLATE_NAME "led"
#define BLYNK_AUTH_TOKEN "XNtsA43xSrq-Jpnu8lpgf28agWpokMNo"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "OnePlus 8 Pro";
char pass[] = "hello1411";

BlynkTimer timer;

BLYNK_WRITE(V0)
{

  int value = param.asInt();
  digitalWrite(D0, value);
}
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
}
