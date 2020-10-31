#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "Yhttps://nodemcu-led-b3637.firebaseio.com/" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "bk1ScvsVBNfLitAt4pZO3EqEtM6SfC2cLn7MJAcb"
#define WIFI_SSID "Anonymous"
#define WIFI_PASSWORD "batman123"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;

FirebaseJson json;


/*/ defines pins numbers
const int trigPin1 = D0; // for First UDM Sensor
const int echoPin1 = D1;

const int trigPin2 = D2; // For Second UDM Sensor
const int echoPin2 = D3;

// defines variables
long duration;
int distance;

long Sensor1,Sensor2;*/

const String path = "/Floor 1";


/*void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}*/

void setup() {
  Serial.begin(115200); // Starts the serial communication
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");


  
/*pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
*/

pinMode(D0,INPUT_PULLUP);
pinMode(D1,INPUT_PULLUP);
pinMode(D2,INPUT_PULLUP);
pinMode(D3,INPUT_PULLUP);


}



void loop() {
// Clears the trigPin
/*digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

SonarSensor(trigPin1, echoPin1);
Sensor1 = distance;
SonarSensor(trigPin2, echoPin2);
Sensor2 = distance;


Serial.print(Sensor1);
Serial.print(" \t ");
Serial.print(Sensor2);
Serial.println();

if(Sensor1<10)
{
  Firebase.setInt(firebaseData, path + "/Parking1", 1);
  }
  else
  {
    Firebase.setInt(firebaseData, path + "/Parking1", 0);
    }

if(Sensor2<10)
{
  Firebase.setInt(firebaseData, path + "/Parking2", 1);
  }
  else
  {
    Firebase.setInt(firebaseData, path + "/Parking2", 0);
    }
delay(100);*/

int x=digitalRead(D1);
int y=digitalRead(D2);
int z=digitalRead(D3);
int w=digitalRead(D4);
if(x==LOW)
{
  Firebase.setInt(firebaseData, path + "/Parking1", 1);
  }
  else
  {
    Firebase.setInt(firebaseData, path + "/Parking1", 0);
    }

if(y==LOW)
{
  Firebase.setInt(firebaseData, path + "/Parking2", 1);
  }
  else
  {
    Firebase.setInt(firebaseData, path + "/Parking2", 0);
    }


if(z==LOW)
{
  Firebase.setInt(firebaseData, path + "/Parking3", 1);
  }
  else
  {
    Firebase.setInt(firebaseData, path + "/Parking3", 0);
    }

if(w==LOW)
{
  Firebase.setInt(firebaseData, path + "/Parking4", 1);
  }
  else
  {
    Firebase.setInt(firebaseData, path + "/Parking4", 0);
    }    
delay(100);


}
