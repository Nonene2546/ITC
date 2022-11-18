// bitRead(x, n)
// bitRead(5,2) จะ return ค่า บิตที่ 2 นับจากขวาสุดของ 00000101 นั่นก็คือ 1
// เทียบเท่ากับ ((5) >> (2)) & 0x01

int number; // number to display
int bitPattern = ‘B11111100’ const byte numPins = 8;
const int segmentPins[8] = {7, 12, 11, 5, 6, 8, 9, 10};
void setup()
{
  Serial.begin(19200);
  for (int i = 0; i < numPins; i++)
    pinMode(segmentPins[i], OUTPUT);
}
void loop()
{
  boolean isBitSet;
  for (int segment = 0; segment < 8; segment++)
  {
    isBitSet = bitRead(bitPattern, segment);
    digitalWrite(segmentPins[segment], isBitSet);
  }
}
