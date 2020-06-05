
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(13, 12,11,10, 9, 8);
int digVol = 0;    //represent Volt after using comparator
int digAmp = 0;    //represent Ampere after using comparator
int pie    = 0;    //represent deltaPhase after using XOR Gate
const int Hz = 50;
const int T = (1000/Hz);
const float Pi = 3.14159; 
float P;
float PF = 0<PF<1;
int PFcas;
float duration ;

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);
  lcd.begin(16, 4);
  pinMode(8,OUTPUT);
  // Print a message to the LCD.
  // read the input on analog pin 0:
  int sensorVol = analogRead(A2);

  float voltage = sensorVol;
  if (0<voltage)
  { 
    digVol = HIGH;
  } 
  else 
  { 
    digVol = LOW;
  }
  // print out the value you read:
  int sensorAmp = analogRead(A3);

  float current = sensorAmp ;
  if (0<current)
  { 
    digAmp = HIGH;
  } 
  else 
  { 
    digAmp = LOW;
  }
  // print out the value you read:
  pie = digVol ^ digAmp;
  if (pie==1)
  {
    digitalWrite(8,HIGH);
    duration = pulseIn(pie,HIGH,10);
    P = (duration*2*Pi)/T;
    PF = cos(P); 
  }
  else {
    digitalWrite(8,LOW);
  }
  while (PF<0.8)  
  {
    PFcas = (int)PF*10;
    switch (PFcas)
    {
    case 1:
      //do something when var equals 1
      break;
    case 2:
      //do something when var equals 2
      break;
    case 3:
      //do something when var equals 3
      break;
    case 4:
      //do something when var equals 4
      break;
    case 5:
      //do something when var equals 5
      break;
    case 6:
      //do something when var equals 6
      break;
    case 7:
      //do something when var equals 7
      break;
    case 8:
      //do something when var equals 8
      break;
    case 9:
      //do something when var equals 9
      break;
    }      
  }
  delay(10);        // delay in between reads for stability
}

// the loop routine runs over and over again forever:
void loop() 
{
  int sensorVol = analogRead(A2);

  float voltage = sensorVol ;
  if (0.1<voltage)
  { 
    digVol = HIGH;
  } 
  else 
  { 
    digVol = LOW;
  }
  // print out the value you read:
  int sensorAmp = analogRead(A3);
 
  float current = sensorAmp ;
  if (511.919121991<current)
  { 
    digAmp = HIGH;
  } 
  else 
  { 
    digAmp = LOW;
  }
  // print out the value you read:
  pie = digVol ^ digAmp;
  if (pie==1)
  {
    digitalWrite(8,HIGH);
    duration = pulseIn(pie,HIGH);
    P = (duration*2*Pi)/T;
    PF = cos(P); 
  }
  else {
    digitalWrite(8,LOW);
  }
  Serial.println("current");
  Serial.println(current);
  Serial.println("voltage");
  Serial.println(voltage);
  lcd.setCursor(0,0);
  lcd.print("voltage =");
  lcd.print(voltage);
  lcd.setCursor(0,1);
  lcd.print("current =");
  lcd.print(current);
  lcd.setCursor(0,2);
  lcd.print("PF =");
  lcd.print(PF);
}
