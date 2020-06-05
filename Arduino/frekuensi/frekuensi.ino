#include <FreqCounter.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int frq;
int cnt;

 
void setup() {
lcd.begin(16, 2);
lcd.print("Frequency Counter");
lcd.clear ();
 
}
 
void loop() {
 
FreqCounter::f_comp=10; // Cal Value / Calibrate with professional Freq Counter
FreqCounter::start(1000); // 100 ms Gate Time
 
while (FreqCounter::f_ready == 0)
 
frq=FreqCounter::f_freq;
lcd.setCursor (0,1);
lcd.print(cnt++);
lcd.setCursor (0,0);
lcd.print(" Freq: ");
lcd.setCursor (8,0);
lcd.print(frq);
delay(500);
}
