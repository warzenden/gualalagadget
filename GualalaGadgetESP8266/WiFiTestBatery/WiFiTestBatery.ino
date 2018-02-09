
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h> 
#include <time.h>
#include <Ticker.h>


int analogMax = 1023;
bool pin12On = false;
bool pin13On = false;
bool pin14On = false;
//Set these to your desired credentials.
const char *ssid = "Gualala Gadget Test";
const char *password = "";
String html = "";
ESP8266WebServer server(80);
//////////////////
/* Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
 
void handleRoot() {
Serial.println("handleRoot");
server.send(200, "text/html", html);
}

void getData() {   
  
  Serial.println("getData");
  int LEDStatus =  digitalRead(2);
  if(LEDStatus == 0) {
    LEDStatus = 255;
  } else {
     LEDStatus = 0;
  }
   digitalWrite(2, LEDStatus); 
  server.send(200, "text/html", html);  
}

void change2() {   
  
  Serial.println("change2"); 
  int LEDStatus =  digitalRead(2);
  if(LEDStatus == LOW) {
    digitalWrite(2, HIGH); 
  } else {
    digitalWrite(2, LOW); 
  }
  server.send(200, "text/html", html);
}

void change12() {   
  
  Serial.println("change12"); 
  //int LEDStatus =  digitalRead(12);
  
  pin12On = !pin12On;
  digitalWrite(12,pin12On);
  server.send(200, "text/html", html);
}

void change13() {   
  
  Serial.println("change13"); 
  //int LEDStatus =  digitalRead(13);
  
  pin13On = !pin13On;
  digitalWrite(13,pin13On);
  server.send(200, "text/html", html);
}

void change14() {   
  
  Serial.println("change14"); 
  int LEDStatus =  digitalRead(14);
  if(LEDStatus == LOW) {
    digitalWrite(14, HIGH); 
  } else {
    digitalWrite(14, LOW); 
  }
  server.send(200, "text/html", html);
}



void displayServerArgs() {

  String msg = "Num of args rec: ";
  msg += server.args();
  msg += "\n";
  for(int i=0;i<server.args();i++) {

    msg +="Args no." + String(i) + "->"; 
    msg += server.argName(i);
    msg += "values: " + server.arg(i);
    
  }
 Serial.println(msg);
  
}


void setup() {
Serial.begin(115200);
Serial.println("In Setup");
WiFi.persistent(false);
html ="<html lang=\"en\"> <head> <meta charset=\"utf-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\"> <meta name=\"description\" content=\"\"> <meta name=\"author\" content=\"\"> <title>Tommy's BirthDay Clock</title> <style type=\"text/css\"> .button { background-color: #4CAF50; /* Green */ border: none; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; height: 50px; } </style> </head> <body> <center> <input type=\"button\" class=\"button\" onClick=\"updatePin2()\" value=\"LED Pin 2\"> <br> <br> <input type=\"button\" class=\"button\" onClick=\"updatePin12()\" value=\"Pin 12\"> <br> <br> <input type=\"button\" class=\"button\" onClick=\"updatePin13()\" value=\"Pin 13\"> <br> <br> <input type=\"button\" class=\"button\" onClick=\"updatePin14()\" value=\"Pin 14\"> <br> <br> <output id=\"switch\" style=\"font-family:Courier; color:Gray; font-size: 20px;\"> no reading on pin 16 </output> </center> <br> <script> function updatePin2(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/2\", true); xhttp.send(); } function updatePin12(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/12\", true); xhttp.send(); } function updatePin13(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/13\", true); xhttp.send(); } function updatePin14(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/14\", true); xhttp.send(); } //example of using a word function motor(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/motor\", true); xhttp.send(); } //example of using POST function setAlarm(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"POST\", \"/alarm\", true); var timeStamp = alarmHour + \":\" + alarmMinute; xhttp.send(timeStamp); } //handy function formatNumber(i) { if (i < 10) {i = \"0\" + i}; return i; } </script> </body> </html>";

pinMode(2, OUTPUT); 
pinMode(12, OUTPUT); 
pinMode(13, OUTPUT); 
pinMode(14, OUTPUT); 
delay(1000);
Serial.print("Configuring access point...");
/* You can remove the password parameter if you want the AP to be open. */
WiFi.softAP(ssid, password);

IPAddress myIP = WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(myIP);

server.on("/", handleRoot);
server.on("/2", change2);
server.on("/12", change12);
server.on("/13", change13);
server.on("/14", change14);


server.begin();
Serial.println("HTTP server started");
 
}

void loop() { 
  server.handleClient();
   delay(500); 
  

}
