//Modules servo
#include <ESP32Servo.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>
#include <Arduino.h>
//moduole wifi
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti wifiMulti;

Servo monServo; // on crée l'objet monServo

int etatBouton; //variable qui vérifie si le bouton est appuyé ou non
int valeurCapteur;//valeur du photorésistor
int cm;
int luminosite_max; //valeur de test de la luminosité maximum au démarrage

void setup()
{

 Serial.begin(115200);
WiFi.begin("SSID", "password");
 while ( WiFi.status() != WL_CONNECTED) { //loading pour la connection wifi
Serial.print(".");
delay(100);
}
Serial.println("Connected");
 luminosite_max = analogRead(A0)/4;

for (int i = 0 ; i <= 1000 ; ++i) {
Serial.print(".");
if ( analogRead(A0)/4 > luminosite_max) {
luminosite_max = analogRead(A0)/4;
}
}


pinMode(A0, INPUT);//valeur du photoresistor sur entrée A0
pinMode(14, OUTPUT); //valeur du triggerPin sur entrée 14
pinMode(35, INPUT);//valeur du echoPin sur entrée A7
 monServo.attach(33); // on définit le Pin utilisé par le servomoteur
monServo.write(180);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
pinMode(triggerPin, OUTPUT); // Clear the trigger
digitalWrite(triggerPin, LOW);
delay(2);
digitalWrite(triggerPin, HIGH);
delay(10);
digitalWrite(triggerPin, LOW);
pinMode(echoPin, INPUT);
return (0.01723 * pulseIn(echoPin, HIGH));
}
/* -------------------------- Message to slack --------------- */
void handler(int cm) {
if( cm < 6 ) {
HTTPClient http;
Serial.print("[HTTP] begin...\n");
// configure traged server and url
http.begin("http://maker.ifttt.com/trigger/user_win/with/key/{{your_token}}"); //HTTP
 Serial.print("[HTTP] GET...\n");
// start connection and send HTTP header
int httpCode = http.GET();
 // httpCode will be negative on error
if(httpCode > 0) {
// HTTP header has been send and Server response header has been handled
Serial.printf("[HTTP] GET... code: %d\n", httpCode);
 // file found at server
if(httpCode == HTTP_CODE_OK) {
String payload = http.getString();
Serial.println(payload);
}
} else {
Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
}
http.end();
}
delay(1000); // on attend 1s pour eviter de renvoyer plusieurs fois le meme message
}

void readPhotoresistor(){
valeurCapteur = analogRead(A0)/4;//on calcul la valeur du photoresistor (pour avoir 255 max)
Serial.println(valeurCapteur);

if (valeurCapteur > luminosite_max/2) {//si luminosité est forte on ferme
monServo.write(0);
}
if (valeurCapteur < luminosite_max/2) {//si luminosité est basse on ouvre
monServo.write(180);
}
}

void loop()
{
readPhotoresistor();
cm = readUltrasonicDistance(14, 35);
Serial.print(cm);
Serial.println("cm");
handler(cm);

}