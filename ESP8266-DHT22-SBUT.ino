#include <SBut.h>
#include <DHT.h>
#define ss 14 //D5
SButSDK sdk;
DHT dht(ss, DHT22);
const int nodes = 0;
const int sensors = 2;
unsigned long value = 0;
const char *ssid = "TP-Link_6A1C"; 
const char *pass = "46522801";
const char *token = "kPJdJ5AElgKeqSs54b3WZ4dRUtXWM8dGMdv2oYwfhsnlZiWygS";

void setup(){
  Serial.begin(115200);
  sdk.begin(ssid, pass, token, nodes, sensors);
  dht.begin();
}
void loop(){
  sdk.loop();
  float hum = dht.readHumidity();
  float tem = dht.readTemperature();
  if(((unsigned long)(millis()- value)) > 5000){
    sdk.setSensor(0, hum); 
    sdk.setSensor(1, tem);
    value = millis();
  }
}
