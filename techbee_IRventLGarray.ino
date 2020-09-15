#include <IRremote.h>
#include <Servo.h>
int IR_PIN=5;
int ledR=10;
int ledG=11;
Servo servo;
int angle=90;
IRrecv irrecv(IR_PIN);
decode_results results;
long int aron[]={0x8800347,0x8800448,0x8800549,0x880064A,0x880074B,0x880084C,0x880094D,0x8800A4E,0x8800B4F,0x8800C40,0x8800D41,0x8800E42,0x8800F43};
void setup() 
{
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  servo.attach(9);
  servo.write(angle);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  
}

void loop() {
  
  if(irrecv.decode(&results))
  {Serial.println(results.value,HEX);
  delay(50);
   irrecv.resume();
   for(int i=0;i<13;i++)
   {if(results.value==aron[i])
   {angle=10;
    digitalWrite(ledR, HIGH);
    digitalWrite(ledG,LOW );
    break;
   }
   }
    if(results.value==0x88C0051)
   {
    angle=90;
    digitalWrite(ledR, LOW);
    digitalWrite(ledG,HIGH );
       }
      
   servo.write(angle);
   delay(100);
   
  }
}
  


  
