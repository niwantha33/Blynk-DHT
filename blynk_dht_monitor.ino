/* Free to use ( From Algobel TI ) 
* feel free to send feed back 
* Thanks for the community for supporting free libries 
|--------------|
|              |
|   DHT 11           |
|--------------|
  |  |  |  |
  1  2  3  4
  
  1 = VCC
  2 = DATA
  3 = NC ( Not Connected)
  4 = GND 
  
  * Connect 1 pin to 3.3 v supply 
  * pin 1 ---/\/\/\/\/\---- pin2  ( 47K Ohms) 
  * pin 4 connect to ground 
  
*/

#include "DHT.h"
#define DHTPIN 14     // what digital pin we're connected to  D5 = 14;
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "........."; // Wifi SSID
char pass[] = "........"; // Password (WIFI)
char auth[] =  "............" // Blynk Key 

void setup() {
  Serial.begin(115200);
  Serial.println("DHT Connected...");
  dht.begin();
  Blynk.begin(auth, ssid, pass); //
}


// Need to setup virtual pin configuration in Blynk app
BLYNK_READ(V1) {
  float t = dht.readTemperature();
  Blynk.virtualWrite(V1, t);
}

BLYNK_READ(V2) {
 float h = dht.readHumidity();
 Blynk.virtualWrite(V2, h);
}

void loop() {
  Blynk.run(); // Keep looping
 }
