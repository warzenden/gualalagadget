
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h> 
#include <time.h>
#include <Ticker.h>


int analogMax = 1023;
bool pin12On = false;
bool pin13On = false;
bool pin14On = false;
int motorPin = 13;

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

void changeMotor() {   
  
  Serial.println("changeMotor"); 
  /*
  String msg = "Num of args rec: ";
  msg += server.args();
  msg += "\n";
  for(int i=0;i<server.args();i++) {

    msg +="Args no." + String(i) + "->"; 
    msg += server.argName(i);
    msg += "values: " + server.arg(i);
    
  }
  */
  String mVal = server.arg(0);
  Serial.println(mVal);

  int sz = mVal.length();
  char buf[sz+1]; 
 
  strcpy(buf, mVal.c_str());
  int mInt = atoi(buf);  

 float conv = (mInt*1024)/100;
   Serial.println(conv);
  analogWrite(motorPin,conv);
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
html ="<html lang=\"en\"> <head> <meta charset=\"utf-8\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\"> <meta name=\"description\" content=\"\"> <meta name=\"author\" content=\"\"> <title>Gualala Gadget Access Point</title> <style type=\"text/css\"> .ggButton { margin-top: 10px; background-color:#ffec64; border:1px solid #ffaa22; display:inline-block; font-family:Arial; font-size:20px; padding:15px 70px; opacity: 0.7; } .ggButton:hover { opacity: 1; } .slidecontainer { width: 90%; } .slider { -webkit-appearance: none; width: 100%; height: 25px; background: #d3d3d3; outline: none; opacity: 0.7; -webkit-transition: .2s; transition: opacity .2s; } .slider:hover { opacity: 1; } .slider::-webkit-slider-thumb { -webkit-appearance: none; appearance: none; width: 35px; height: 45px; background: #4CAF50; cursor: pointer; } .slider::-moz-range-thumb { width: 25px; height: 25px; background: #4CAF50; cursor: pointer; } </style> </head> <body> <center> <button class=\"ggButton\" onClick=\"updatePin2()\" text=\"\">LED Pin 2</button> <br> <br> <button class=\"ggButton\" onClick=\"updatePin12()\" text=\"\">Pin 12</button> <br> <br> <div class=\"slidecontainer\"> <p>Motor Speed:</p> <input type=\"range\" min=\"0\" max=\"100\" value=\"0\" class=\"slider\" id=\"motorSlider\" onchange=\"updateMotor()\"> </div> <br> <br> <button class=\"ggButton\" onClick=\"updatePin14()\" text=\"\">Pin 14</button> <br> <br> <output id=\"switch\" style=\"font-family:Courier; color:Gray; font-size: 20px;\"> no reading on pin 16 </output> </center> <br> <script> function updatePin2(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/2\", true); xhttp.send(); } function updatePin12(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/12\", true); xhttp.send(); } function updateMotor(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"POST\", \"/motor\", true); var motorSpeed = motorSlider.value; xhttp.send(motorSpeed); } function updatePin14(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/14\", true); xhttp.send(); } function motor(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"GET\", \"/motor\", true); xhttp.send(); } function setAlarm(){ var xhttp = new XMLHttpRequest(); xhttp.open(\"POST\", \"/alarm\", true); var timeStamp = alarmHour + \":\" + alarmMinute; xhttp.send(timeStamp); } function formatNumber(i) { if (i < 10) {i = \"0\" + i}; return i; } </script> </body> </html>";


pinMode(2, OUTPUT); 
pinMode(12, OUTPUT); 
pinMode(motorPin, OUTPUT); 
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
server.on("/motor", changeMotor);
server.on("/14", change14);


server.begin();
Serial.println("HTTP server started");
 
}

void loop() { 
  server.handleClient();
   delay(500); 
  

}
