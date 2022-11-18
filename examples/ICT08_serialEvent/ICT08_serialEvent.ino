void setup()
{
  Serial.begin(9600); // initialize serial:
  pinMode(13, OUTPUT);
}
void loop()
{
  Serial.println("Wait for command");
  delay(500);
}
void serialEvent()
{
  while (Serial.available())
  {
    char inChar = (char)Serial.read(); // get the new byte:
    if (inChar == '1')
    { // check received 'enter' (0x0D)
      digitalWrite(13, HIGH);
    }
    else if (inChar == '0')
    {
      digitalWrite(13, LOW);
    }
  }
}
