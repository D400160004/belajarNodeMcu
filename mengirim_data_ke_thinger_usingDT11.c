#include <ESP8266WiFi.h>      // Library ESP8266
#include <DHT.h>              // Library DHT
#include <ThingerESP8266.h>   // library Thinger.io
 
#define USERNAME "User Name"  //Username thinger.io
#define DEVICE_ID "Device id" //Device Id thinger.io
#define DEVICE_CREDENTIAL "code credential" //Code Cridential dari Device Id thinger.io
 
#define SSID "Nama Wifi" //Hotspot yang kita pakai
#define SSID_PASSWORD "Password Wifi"//pass wifi
 
#define DHTPIN D0 //Pin data dari DHT terhubung ke pin D7 NodeMCU
#define DHTTYPE DHT11// deklarasi menggunakan dht 11
 
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
 
DHT dht(DHTPIN, DHTTYPE);
 
float hum,temp;
 
void setup() {
  Serial.begin(9600); //baudrate
  Serial.println("Baca DHT11");
 
  dht.begin();
 
  thing.add_wifi(SSID, SSID_PASSWORD);
 
  thing["dht11"] >> [](pson& out){
    out["humidity"] = hum;
    out["celsius"] = temp;
  };
}
 
void loop() 
{  
  thing.handle(); 
  //sensor membutuhkan waktu 250 ms ketika membaca suhu dan kelembaban 
  float h = dht.readHumidity(); //Membaca kelembaban
  float t = dht.readTemperature(); //Membaca suhu dalam satuan Celcius
  float f = dht.readTemperature(true); //Membaca suhu dalam satuan Fahrenheit
 
  hum = h;
  temp = t;
}
