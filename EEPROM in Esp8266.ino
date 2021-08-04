
#include <EEPROM.h>

int i=-99;

void setup() {
  Serial.begin(9600);
  EEPROM.begin(10);
  delay(1000);
  Serial.print("******************** EEP content after reset*****************");
  i=EEPROM.read(0);
  if(i>100 || i<0)
    i=0;
  Serial.println(String(EEPROM.read(0)));
  Serial.println("******************** EEP content in loop*****************");
}

void loop() {
    EEPROM.write(0,i++);
    if(i>100)
      i=0;
      EEPROM.commit();
    Serial.println(String(EEPROM.read(0)));
      delay(500);
}
