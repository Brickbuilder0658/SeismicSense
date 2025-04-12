/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */

// initializes the pins
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 7;
const int echoPin2 = 8;
const int trigPin3 = 2;
const int echoPin3 = 4;

const int vibrate1 = 3;
const int vibrate2 = 5;
const int vibrate3 = 6;

float duration1, distance1, amplitude1, duration2, distance2, amplitude2, duration3, distance3, amplitude3;

int val = 0;  
void setup() {
  // sets the pins for their options
  pinMode(vibrate1, OUTPUT);
  pinMode(vibrate2, OUTPUT);
  pinMode(vibrate3, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
   
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 * .0343)/2;

  Serial.print("Distance1: ");
  Serial.println(distance1);


  if(distance1 < 200){
    amplitude1 = (255.0 - (255.0/log(201)) * log(distance1 + 1));
    analogWrite(vibrate1, amplitude1);
  }
  else{
    digitalWrite(vibrate1, LOW);
  }


  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 * .0343)/2;

  Serial.print("Distance2: ");
  Serial.println(distance2);

  if(distance2<200){
    amplitude2 = (255.0-(255.0/log(201)) * log(distance2 + 1));
    analogWrite(vibrate2, amplitude2);
  }
  else{
    digitalWrite(vibrate2, LOW);
  }

  // 3rd sensor
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3 * .0343)/2;

  Serial.print("Distance3: ");
  Serial.println(distance3);

  if(distance3<200){
    amplitude3 = (255.0-(255.0/log(201))*log(distance3 + 1));
    analogWrite(vibrate3, amplitude3);
  }
  else{
    digitalWrite(vibrate3, LOW);
  }
  
  delay(10);
}