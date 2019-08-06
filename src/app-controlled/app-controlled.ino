#include <IRremote.h>
#include <IRremoteInt.h>

#include<LiquidCrystal.h>
IRrecv irrecv(8);
decode_results results;

LiquidCrystal lcd(7,6,5,4,3,2);


#define zerobulb 9
#define tv 10
#define light 11
#define fan 12

int i=0,j=0,k=0,l=0,m=0;

void setup()
{
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("  Good Night :-) ");
  delay(2000);
  pinMode(zerobulb,OUTPUT);
  pinMode(tv,OUTPUT);
  pinMode(light,OUTPUT);
  pinMode(fan,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(8,INPUT);

  /***********Particle connections***********/
  pinMode(13,INPUT);
  pinMode(14,INPUT);
  pinMode(15,INPUT);
  pinMode(16,INPUT);
  pinMode(17,OUTPUT);

   
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
   if (irrecv.decode(&results))
   {
        digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    if((results.value)== 2049||(results.value)== 1)        // key 1
     {
       if(i%2==0)
       {
        digitalWrite(zerobulb, HIGH);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Zerobulb");
        delay(10);
       }
       else
       {
        digitalWrite(zerobulb, LOW);
          lcd.setCursor(0,0);
          lcd.print("        ");
          delay(100);
       }
       i++;
     }
    
    
    
    if((results.value)== 2050||(results.value)== 2)    //  key 2
     {
      if(j%2==0)
      {
       digitalWrite(tv, HIGH);
       lcd.setCursor(8,0);
       lcd.print("   TV   ");
       delay(10);
      }
      else
      {
        digitalWrite(tv, LOW);
       lcd.setCursor(8,0);
       lcd.print("        ");
       delay(10);
      }
      j++;
     }
  
   
    if((results.value)== 2051||(results.value)== 3)    //  key 3
     {
      if(k%2==0)
      {
       digitalWrite(light, HIGH);
       lcd.setCursor(0,1);
       lcd.print(" Light  ");
       delay(10);
      }
      else
      {
        digitalWrite(light, LOW);
       lcd.setCursor(0,1);
       lcd.print("        ");
       delay(10);
      }
      j++;
     }
  
   
    if((results.value)== 2052||(results.value)== 4)    //  key 4
     {
      if(l%2==0)
      {
       digitalWrite(fan, HIGH);
       lcd.setCursor(8,1);
       lcd.print("  Fan   ");
       delay(10);
      }
      else
      {
        digitalWrite(fan, LOW);
       lcd.setCursor(8,1);
       lcd.print("        ");
       delay(10);
      }
      j++;
     }
     
    irrecv.resume(); 
   }
}
