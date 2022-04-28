#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

//Firebase settings
#define FIREBASE_HOST "garrr-d0388-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "lRhhu4lVJvGrnkSSGCZXiSPNAaQqJ9gv5bRk1XsM"

//Wi-Fi settings
#define WIFI_SSID "harshank"
#define WIFI_PASSWORD "10203040"

FirebaseData firebaseData;

const int trigPin1 = 13;
const int echoPin1 = 15;
#define SOUND_VELOCITY1 0.034
long duration1;
float distanceCm1;

const int trigPin = 12;
const int echoPin = 14;
#define SOUND_VELOCITY 0.034
long duration;
float distanceCm;

const int trigPin2 = 0;
const int echoPin2 = 4;
#define SOUND_VELOCITY2 0.034
long duration2;
float distanceCm2;
int val1  ;
int val2 ;
int val3 ;



void setup() {

  Serial.begin(115200);                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input

pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);


}

void loop() {

  
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm = duration * SOUND_VELOCITY/2;


  if( distanceCm <= 10 )
  {
    val1 = 1;
    Serial.println(val1 + "111");
  }
  else
  {
    val1 = 0;
    Serial.println(val2 + "222");
  }

digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distanceCm1 = duration1 * SOUND_VELOCITY1/2;

if( distanceCm1 <= 10 )
  {
    val2 = 1;
    Serial.println(val2 + "333");
  }
  else
  {
    val2 = 0;
    Serial.println(val2 + "44");
  }

  digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distanceCm2 = duration2 * SOUND_VELOCITY2/2;

if( distanceCm2 <= 10 )
  {
    val3 = 1;
    Serial.println(val2 + "555");
  }
  else
  {
    val3 = 0;
    Serial.println(val2 + "666");
  }

  Firebase.setInt(firebaseData, "/slot1", val1 );
Firebase.setInt(firebaseData, "/slot2", val2 );
Firebase.setInt(firebaseData, "/slot3", val3 );


}
