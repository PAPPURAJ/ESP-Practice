#include <EEPROM.h>

void writeStringToEEPROM(int addrOffset, String strToWrite)
{
  int len = strToWrite.length();
  EEPROM.write(addrOffset, len);
  
 EEPROM.commit();
  for (int i = 0; i < len; i++)
  {
    EEPROM.write(i+addrOffset+1, strToWrite[i]);
     EEPROM.commit();
  }
}

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

void setup() {
  Serial.begin(9600);
  
  EEPROM.begin(500);

  writeStringToEEPROM(0, "Arduino");
  
  String retrievedString = readStringFromEEPROM(0);

  Serial.print("The String we read from EEPROM: ");
  Serial.println(retrievedString);
}

void loop() {}
