#include <Servo.h>

#define trigPin 10
#define echoPin 13

float duration, distance;
Servo s1;
int value = analogRead(A0);
int soilMoist = analogRead(A1);

void setup() {
  s1.attach(3);
  s1.write(45);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);
  soilMoist = analogRead(A1);
  int soilPerc = map(soilMoist, 592, 248, 0, 100);
  Serial.print("LDR value : ");
  Serial.println(value);
  Serial.print("Moist value: ");
  Serial.println(soilPerc);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int capacity = 1000; //size of water container
  duration = pulseIn(echoPin, HIGH);
  distance = duration/2 * 0.0340;
  if (distance < 1000 && distance > 2) {
    Serial.print("Water level: ");
    Serial.println(capacity - distance);
  }
  if (soilPerc < 15) {
    s1.write(90);
    delay(1000);}
   else {
    s1.write(45);
    delay(250);}
  
  delay(1000);
}
