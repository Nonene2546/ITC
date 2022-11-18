// Arduino clock -> 16MHz
// TCCRxA = 0
// TCCRxB |= B00000xxx
//   001 - divide by 1
//   010 - divide by 8
//   011 - divide by 64
//   100 - divide by 256
//   101 - divide by 1024
// TIMSKx |= B00000xxx 
//   1xx -> enable compare match on register B
//   x1x -> enable compare match on register A
//   xx1 -> enable overflow

// OCRxA = value to compare on register A
// OCRxB = value to compare on register B

// TIMERx_COMPA_vect
// TIMERx_COMPB_vect
// TIMER1_OVF_vect
// TCNTx = y -> preset counter


#define ledPin 13
int timer1_counter;
int t1 = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  // initialize timer1
  noInterrupts(); // disable all interrupts
  TCCR1A = 0;     // Set Mode of Timer : Normal Mode
  TCCR1B = 0;
  timer1_counter = 3036;  // preload timer 65536-16MHz/256/1Hz
  TCNT1 = timer1_counter; // preload timer
  TCCR1B |= (1 << CS12);  // 256 prescaler
  TIMSK1 |= (1 << TOIE1); // enable timer overflow interrupt
  interrupts();           // enable all interrupts
}
ISR(TIMER1_OVF_vect) // interrupt service routine
{
  TCNT1 = timer1_counter; // preload timer
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
  Serial.println(t1++);
}
void loop()
{
  // your program here...
}