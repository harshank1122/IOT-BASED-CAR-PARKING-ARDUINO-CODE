#include <LiquidCrystal_I2C.h>
#include <Servo.h> //includes the servo library
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo1;
Servo myservo2;
const int trigPin = 12;
const int echoPin = 14;
#define SOUND_VELOCITY 0.034
long duration;
float distanceCm;
const int trigPin1 = 13;
const int echoPin1 = 15;
#define SOUND_VELOCITY1 0.034
long duration1;
float distanceCm1;

int Total = 3;
int Space;

int flag1 = 0;
int flag2 = 0;

void setup() {
 Serial.begin(115200);
 Wire.begin(D2, D1);
lcd.begin();
lcd.home();
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input


myservo1.attach(0);
myservo2.attach(3);
myservo1.write(100);
myservo2.write(100);

lcd.setCursor (0,0);
lcd.print("  Car  Parking  ");
lcd.setCursor (0,1);
lcd.print("     System     ");
delay (1000);
lcd.clear();  

Space = Total;
}

void loop(){ 

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm = duration * SOUND_VELOCITY/2;

digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distanceCm1 = duration1 * SOUND_VELOCITY1/2;

delay(1150);


if( distanceCm <= 10 && flag1==0){
if(Space>0){

  myservo1.write(0);
  delay(2000);
  myservo1.write(100);
  Space = Space-1;
}else{
lcd.setCursor (0,0);
lcd.print(" Sorry not Space ");  
lcd.setCursor (0,1);
lcd.print("    Available    "); 
delay (1000);
lcd.clear(); 
}
}


digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distanceCm1 = duration1 * SOUND_VELOCITY1/2;


if(distanceCm1 <= 10){
  
  myservo2.write(0);
  delay(2000);
  myservo2.write(100);
  Space = Space+1;
 
}



lcd.setCursor (0,0);
lcd.print("Total Space: ");
lcd.print(Total);

lcd.setCursor (0,1);
lcd.print("Have  Space: ");
lcd.print(Space);
}
