#include "DHT.h"
#include "AntaresESP8266HTTP.h"
//IO Define
#define DHTTYPE DHT11
#define SENSOR_DHT D0
//ANTARES & Wifi Data
#define ACCESSKEY "4398d61fc70bddcf:deccd923f2241613" //AccesKey
#define WIFISSID "UMS Wifi" //nama Wifi
#define PASSWORD "ums.wifi" //pass WiFi
String projectName = "cobalah1"; //nama aplikasi
String deviceName = "temperatur"; //nama device
DHT dht(SENSOR_DHT, DHTTYPE);
AntaresESP8266HTTP antares(ACCESSKEY);
float getTemperature()
{
float t = dht.readTemperature();
if (isnan(t)) return 0;
return t;
}
float getHumidity()
{
float h = dht.readHumidity();
if (isnan(h)) return 0;
return h;
}
void setup() {
Serial.begin(115200);
dht.begin();
antares.setDebug(true);
antares.wifiConnection(WIFISSID,PASSWORD);
}
void loop() {
Serial.println("Temperature : " + (String)getTemperature()+" *C");
Serial.println("Humidity : " + (String)getHumidity()+" %");
int sizeData = 2;
String dataName[sizeData],dataValue[sizeData];
dataName[0]= "Temperature";
dataName[1]= "Humidity";
dataValue[0]= (String)getTemperature();
dataValue[1]= (String)getHumidity();
Serial.println(antares.storeData(projectName, deviceName, dataName, dataValue,sizeData));
delay(10000);
}
