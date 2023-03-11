
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include<DHT.h>

#define FIREBASE_HOST "https://fir-basic-iot-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "JAfEnHVXHDBPPpjrqLVooavj1twDA0DDBXBHiHCm"
#define WIFI_SSID "OnePlus 8 Pro"
#define WIFI_PASSWORD "hello1411"
#define DHTPIN 0 //d3 connect 0gpio //connect data pin of dht to d3
int light =D5 ; // connect d5 to led
//int fan = D0;
//int motor =D8;
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE); 
FirebaseData firebaseData ;
FirebaseData lightData;
FirebaseJson json;
void setup ()
{
  Serial.begin(9600);
  dht.begin();
 
  pinMode(light,OUTPUT);
  WiFi.begin (WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connected to wifi ");
  while (WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.println("connected to ip: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}
void sensorUpdate(){
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  float f=dht.readTemperature(true);//fahrenheit
  if (isnan(h) || isnan(t) || isnan(f)){
    Serial.println(F(" Failed to read from dht sensor"));//check if any reads failed and exit early to try again
    return;
  }
  Serial.print(F("Humidity: ")); //F-float value to be received
  Serial.print(h);
  Serial.print(F("% Temperature : "));
  Serial.print(t);
  Serial.print(F("C , "));
  Serial.print(f);
  Serial.print(F("F "));
  if(Firebase.setFloat(firebaseData,"/FirebaseIOT/temperature",t)) //user defined //default condition
{
  Serial.print("PASSED");
  Serial.println("PATH: " +firebaseData.dataPath()); //compulsory condition
  Serial.println("TYPE: " +firebaseData.dataPath());
  Serial.println("ETag: " +firebaseData.ETag());
  Serial.println("-----------------------------------");
  Serial.println();
}
else 
{
  Serial.println("FAILED");
  Serial.println("REASON: " +firebaseData.errorReason());
  Serial.println("-----------------------------------");
  Serial.println();
}
 if(Firebase.setFloat(firebaseData,"/FirebaseIOT/humidity",h))
{
  Serial.print("PASSED");
  Serial.println("PATH: " +firebaseData.dataPath());
  Serial.println("TYPE: " +firebaseData.dataType());
  Serial.println("ETag: " +firebaseData.ETag());
  Serial.println("-----------------------------------");
  Serial.println();
}
else 
{
  Serial.println("FAILED");
  Serial.println("REASON: " +firebaseData.errorReason());
  Serial.println("-----------------------------------");
  Serial.println();
} 
}
void loop(){ //additional
  sensorUpdate();
 
    if(Firebase.getString(lightData,"/FirebaseIOT/light")){
      
    Serial.println(lightData.stringData());
    if(lightData.stringData() =="1"){ // 1- user defined 
      digitalWrite(light,LOW);
  }
  if(lightData.stringData()=="0"){
    digitalWrite(light,HIGH);
  }
  
  }
  
  delay(1000);
}
