#include <DHT.h>
#include <DHT_U.h>

#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define TRIG_PIN 3
#define ECHO_PIN 5
#define BUTTON 2

#define DHTPIN 7     // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11


DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS = 1000;

int RedPin = 11;
int GreenPin = 10;
int BluePin = 9;


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600); //시리얼모니터

  //소리나는거
  pinMode(8,OUTPUT);
  Serial.begin(9600);
  
  //습도
  Serial.begin(9600);
  // Initialize device.
  dht.begin();

  pinMode(BUTTON, INPUT);

  //led
  pinMode(RedPin,OUTPUT);
  pinMode(GreenPin,OUTPUT);
  pinMode(BluePin,OUTPUT);
}

void loop() {
  // Get humidity event and print its value.
  sensors_event_t event; //_t는 user가 정의한 type
  
  dht.humidity().getEvent(&event);
  

  if(digitalRead(BUTTON)==HIGH){
  if(event.relative_humidity > 70)
  {
    analogWrite(RedPin,255);
    analogWrite(GreenPin,0);
    analogWrite(BluePin,0);
    tone(8,330,500); delay(500); //tone(8,262,지속시간);
    tone(8,294,500); delay(500);
    tone(8,262,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,262,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,330,500); delay(500);
    tone(8,294,500); delay(500);
    tone(8,262,500); delay(500);
    digitalWrite(8, LOW);
  }
  }else 
  {
    noTone(8);
    digitalWrite(8, LOW);
  }
  digitalWrite(RedPin,LOW);
  digitalWrite(GreenPin,LOW);
  digitalWrite(BluePin,LOW);

}
