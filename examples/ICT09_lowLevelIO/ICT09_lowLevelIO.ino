// • DDRx (Data Direction Register) เก็บทิศทางของ Port ว่าเป็น Input หรือ
// Output (0=Input, 1=Output)
// • PORTx (Port Register)
// – ถ้า Pin เดียวกันใน DDR เป็น 0 : (Input) จะใช้ก าหนดว่าจะใช้ Internal Pull-Up
// Register หรือไม่ (0 = ไม่ใช่, 1 = ใช้)
// – ถ้า Pin เดียวกันใน DDR เป็น 1 : (Output) : จะใช้ในการก าหนด Logic ของ Pin
// • PINx เก็บค่าปัจจุบันของ Pin นั้นๆ เพื่อให้อ่านค่าออกไปได้

// DDRD -> 0-7
// DDRB -> 8-13
// DDRC -> A0-A5 + RESET

int main()
{
  DDRB = B00100000;
  while (1)
  {
    PORTB = B00100000; // Turn on LED
    _delay_ms(1000);
    PORTB = B00000000; // Turn off LED
    _delay_ms(1000);
  }
}
