//EEPROM.read(ADDR) อ่านค่า byte ที่เก็บไว้ใน address ที่ต้องการ โดย ADDR ใช้ได้ตั้งแต่ 0-1023 
//EEPROM.write(ADDR,value) เขียนค่า byte ที่เก็บไว้ใน address ที่ต้องการ โดย value มีค่าตั้งแต่ 0-255
//EEPROM.update(ADDR,value) คล้ายกับ write แต่จะตรวจสอบก่อนว่าค่า value ต่างไปหรือไม่ ถ้าเหมือนเดิมก็จะไม่เขียน เพื่อเป็นการรักษารอบการใช้งานเอาไว้

// File -> Examples -> EEPROM

#include <EEPROM.h>
const int buttonPin = 6;
const int ledPin = 13;
int ledState;
int buttonState;
int lastButtonState = LOW;
long debounceTime = 0;
long debounceDelay = 50;
void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  ledState = EEPROM.read(0);
  digitalWrite(ledPin, ledState);
}
void loop()
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState)
  {
    debounceTime = millis();
  }
  if ((millis() - debounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      if (buttonState == LOW)
      {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  EEPROM.update(0, ledState);
  lastButtonState = reading;
}
