/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 
int trigPin = 8;    // Trigger
int echoPin = 9;    // Echo
int pin = 13; 
long duration, cm, inches;
 
void setup() {
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pin, OUTPUT);
}
 
void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135

  // Inverse relationship sound
 
  // if (inches < 5){
  //   noTone(pin);
  // }else if (inches >= 5 && inches < 10) {
  //   tone(pin,  4);
  // }else if (inches >= 10 && inches < 15){
  //   tone(pin,  2);
  // }else if (inches >= 15 && inches < 20){
  //   tone(pin,  3);
  // }else if (inches >= 15 && inches < 20){
  //   tone(pin,  1);
  // }else{
  //   tone(pin,  10);
  // }

if (inches < 5){
  noTone(pin);
}else if (inches >= 5 && inches < 10) {
  tone(pin,  2);
}else if (inches >= 10 && inches < 15){
  tone(pin,  4);
}else if (inches >= 15 && inches < 20){
  tone(pin,  1);
}else if (inches >= 15 && inches < 20){
  tone(pin,  3);
}else{
   tone(pin, 10);
}

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}