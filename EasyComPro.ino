#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h> 
#include <EEPROM.h>

String APSSID="Robotics Camp";
String APPSK="12345678";

ESP8266WebServer server(80);


String readStringFromEEPROM(int addrOffset)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];

  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
    Serial.println(data[i]);
  }
  data[newStrLen] = '\0';

  return String(data);
}



String subS(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}



String command;
int out1=14,out2=12,out3=13,out4=15,out5=5,out6=4,out7=0,out8=2;
//String content;
//int statusCode;
//int milisInterval = 2000;
//int count = 0;


void handleRoot() {

}






//void launchWeb() {
//  Serial.println("");
//  Serial.print("SoftAP IP: ");
//  Serial.println(WiFi.softAPIP());
//  server.begin();
//  Serial.println("Server started"); 
//}

void setup() {

    Serial.begin(9600);
     pinMode(16, OUTPUT);
     pinMode(out1, OUTPUT);
     pinMode(out2, OUTPUT);
     pinMode(out3, OUTPUT);
     pinMode(out4, OUTPUT);
     pinMode(out5, OUTPUT);
     pinMode(out6, OUTPUT);
     pinMode(out7, OUTPUT);
     pinMode(out8, OUTPUT);
     digitalWrite(out1,0);
     digitalWrite(out2,0);
     digitalWrite(out3,0);
     digitalWrite(out4,0);
     digitalWrite(out5,0);
     digitalWrite(out6,0);
     digitalWrite(out7,0);
     digitalWrite(out8,0);
    delay(1000);
//    Serial.println();
//    Serial.print("Configuring access point...");


  EEPROM.begin(500);
  //writeStringToEEPROM(0, "RoboRobo?11223344");
  
  String rs = readStringFromEEPROM(0);

if(!digitalRead(D6)){
  APSSID=subS(rs,'!',0);
APPSK=subS(rs,'!',1);
}


  Serial.print("ID: ");
  Serial.println(subS(rs,'!',0));
    Serial.print("Pass: ");
  Serial.println(subS(rs,'!',1));

    WiFi.softAP(APSSID, APPSK);

  IPAddress myIP = WiFi.softAPIP();
//  Serial.print("AP IP address: ");
//  Serial.println(myIP);
  server.on("/monitor", handleRoot);
  server.begin();
//  Serial.println("HTTP server started");
  server.onNotFound([](){
  command=server.uri();
  server.send(200,"text/plain",command);
});
//  EEPROM.begin(512);
//  delay(10);
//  Serial.println();
//  Serial.println();
//  Serial.println("System Online");
//  Serial.println("Reading ssid");
//        String esid;
//        for (int i = 0; i < 32; ++i)
//          {
//            esid += char(EEPROM.read(i));
//          }
//        Serial.print("SSID: ");
//        Serial.println(esid);
//        Serial.println("Reading  password");
//        String epass = "";
//        for (int i = 32; i < 96; ++i)
//          {
//            epass += char(EEPROM.read(i));
//          }
//        Serial.print("PASS: ");
//        Serial.println(epass);
          
server.begin();
}







void loop() {
  server.handleClient();
    if(command.equals("/30")){
      digitalWrite(16,HIGH);
      }
    else if(command.equals("/40")){
      digitalWrite(16,LOW);
      }



    else if(command.equals("/1")){
      digitalWrite(out1,LOW);
      }
    else if(command.equals("/11")){
      digitalWrite(out1,HIGH);
      }

    else if(command.equals("/2")){
      digitalWrite(out2,LOW);
      }
    else if(command.equals("/12")){
      digitalWrite(out2,HIGH);
      }

    else if(command.equals("/3")){
      digitalWrite(out3,LOW);
      }
    else if(command.equals("/13")){
      digitalWrite(out3,HIGH);
      }

    else if(command.equals("/4")){
      digitalWrite(out4,LOW);
      }
    else if(command.equals("/14")){
      digitalWrite(out4,HIGH);
      }


      
    else if(command.equals("/5")){
      digitalWrite(out5,LOW);
      }
    else if(command.equals("/15")){
      digitalWrite(out5,HIGH);
      }
    else if(command.equals("/6")){
      digitalWrite(out6,LOW);
      }
    else if(command.equals("/16")){
      digitalWrite(out6,HIGH);
      }
    else if(command.equals("/7")){
      digitalWrite(out7,LOW);
      }
    else if(command.equals("/17")){
      digitalWrite(out7,HIGH);
      }
    else if(command.equals("/8")){
      digitalWrite(out8,LOW);
      }
    else if(command.equals("/18")){
      digitalWrite(out8,HIGH);
      }



   else if(command.equals("/21")){ //Front
      digitalWrite(out1,1);
      digitalWrite(out2,0);
      digitalWrite(out3,1);
      digitalWrite(out4,0);
     }

     else if(command.equals("/22")){ //Back
      digitalWrite(out1,0);
      digitalWrite(out2,1);
      digitalWrite(out3,0);
      digitalWrite(out4,1);
     }

     else if(command.equals("/23")){ //Left
      digitalWrite(out1,0);
      digitalWrite(out2,1);
      digitalWrite(out3,1);
      digitalWrite(out4,0);
     }

     else if(command.equals("/24")){ //Right
      digitalWrite(out1,1);
      digitalWrite(out2,0);
      digitalWrite(out3,0);
      digitalWrite(out4,1);
     }

     else if(command.equals("/25")){ //Stop
      digitalWrite(out1,0);
      digitalWrite(out2,0);
      digitalWrite(out3,0);
      digitalWrite(out4,0);
     }

     else if(command.equals("/50")){ //All Stop
      digitalWrite(out1,0);
      digitalWrite(out2,0);
      digitalWrite(out3,0);
      digitalWrite(out4,0);
      digitalWrite(out5,0);
      digitalWrite(out6,0);
      digitalWrite(out7,0);
      digitalWrite(out8,0);
     }

     else if(command.indexOf("!")!=-1){
      String com=subS(command,'/',1);
      Serial.println(com);
        int len = com.length();
  EEPROM.write(0, len);
  
 EEPROM.commit();
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(i+1, com[i]);
     EEPROM.commit();
//  }
     }
     ESP.restart();
     }
}
