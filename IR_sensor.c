#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>


const int led = 16;
const int proximity = 23;
const int buzzer = 12;
uint8_t LastStatus = 1;
uint8_t EmergencyStop= 21;


int main(void)
{
  
  
  wiringPiSetupGpio();
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);  
  pullUpDnControl(proximity,PUD_DOWN);
  pullUpDnControl(EmergencyStop,PUD_DOWN);
   
       for(int i=0; i<2; i++)
    {
      digitalWrite(buzzer, HIGH);
      digitalWrite(led, HIGH);
      delay(100);
      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      delay(100);
    } 
   
    while(1)
  {
    
  if(digitalRead(proximity) && LastStatus==0)
  {
    
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
          LastStatus = 1;
  }
    
  
      else if(!digitalRead(proximity) && LastStatus==1)
  {
       
       digitalWrite(led, LOW);
        digitalWrite(buzzer, LOW);
       LastStatus = 0;
        }
           
   
  if(digitalRead(EmergencyStop))
  {
     break;
  }
      
   }// end of while loop
}
 

