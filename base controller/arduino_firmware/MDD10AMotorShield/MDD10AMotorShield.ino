#include <Encoder.h>

#include "MDD10AMotorShieldV1.0.h"

#define LEFT_ENG_DIR 8
#define LEFT_ENG_PWM 9 

#define RIGHT_ENG_DIR 12
#define RIGHT_ENG_PWM 11


 #define LEFT_ENC_PIN_A PD2  //pin 2
 #define LEFT_ENC_PIN_B PD4  //pin 3
  
 //below can be changed, but should be PORTC pins
 #define RIGHT_ENC_PIN_A PC3  //pin A4
 #define RIGHT_ENC_PIN_B PC5   //pin A5

  
MDD10AMotorShield drive(LEFT_ENG_DIR,LEFT_ENG_PWM, RIGHT_ENG_DIR,RIGHT_ENG_PWM);

Encoder left_enc (LEFT_ENC_PIN_A, LEFT_ENC_PIN_B);
Encoder right_enc (RIGHT_ENC_PIN_A, RIGHT_ENC_PIN_B);


void stopIfFault()
{
  if (drive.getFault())
  {
    Serial.println("fault");
    while(1);
  }
}

void setup()
{
  //Serial.begin(115200);
  Serial.begin(9600);
  Serial.println("MDD10AMotorShield");
  drive.init();
}

void loop()
{
  for (int i = 0; i <= 400; i++)
  {
    drive.setM1Speed(i);
    stopIfFault();
    
    Serial.print("ENC1 1: ");
    Serial.println(left_enc.read());
 
//    if (abs(i)%200 == 100)
//    {
//      Serial.print("M1 current: ");
//      Serial.println(md.getM1CurrentMilliamps());
//    }
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    drive.setM1Speed(i);
    stopIfFault();

     Serial.print("ENC1 1: ");
    Serial.println(left_enc.read());
//    if (abs(i)%200 == 100)
//    {
//      Serial.print("M1 current: ");
//      Serial.println(md.getM1CurrentMilliamps());
//    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    drive.setM1Speed(i);
    stopIfFault();

     Serial.print("ENC1 1: ");
    Serial.println(left_enc.read());
//    if (abs(i)%200 == 100)
//    {
//      Serial.print("M1 current: ");
//      Serial.println(md.getM1CurrentMilliamps());
//    }
    delay(2);
  }

  for (int i = 0; i <= 400; i++)
  {
    drive.setM2Speed(i);
    stopIfFault();

     Serial.print("ENC1 2: ");
    Serial.println(right_enc.read());
//    if (abs(i)%200 == 100)
//    {
//      Serial.print("M2 current: ");
//      Serial.println(md.getM2CurrentMilliamps());
//    }
    delay(2);
  }
  
  for (int i = 400; i >= -400; i--)
  {
    drive.setM2Speed(i);
    stopIfFault();

     Serial.print("ENC1 2: ");
    Serial.println(right_enc.read());
//    if (abs(i)%200 == 100)
//    {
//      Serial.print("M2 current: ");
//      Serial.println(md.getM2CurrentMilliamps());
//    }
    delay(2);
  }
  
  for (int i = -400; i <= 0; i++)
  {
    drive.setM2Speed(i);
    stopIfFault();

         Serial.print("ENC1 2: ");
    Serial.println(right_enc.read());
//    if (abs(i)%200 == 100)
//    {
//      Serial.print("M2 current: ");
//      Serial.println(md.getM2CurrentMilliamps());
//    }
    delay(2);
  }
}
