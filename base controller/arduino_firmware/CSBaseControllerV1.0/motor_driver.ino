/***************************************************************
   Motor driver definitions
   
   Add a "#elif defined" block to this file to include support
   for a particular motor driver.  Then add the appropriate
   #define near the top of the main ROSArduinoBridge.ino file.
   
   *************************************************************/

#ifdef USE_BASE

     #include "config.h"
  /* Include the library */
  #include "MDD10AMotorShieldV1.0.h"

#define LEFT_M1DIR 7
#define LEFT_M1PWM 6

#define RIGHT_M1DIR 4
#define RIGHT_M1PWM 3


  /* Create the motor driver object */
  MDD10AMotorShield drive(LEFT_ENG_DIR,LEFT_ENG_PWM, RIGHT_ENG_DIR,RIGHT_ENG_PWM);
  
  /* Wrap the motor driver initialization */
  void initMotorController() {
    drive.init();
  }

  /* Wrap the drive motor set speed function */
  void setMotorSpeed(int i, int spd) {
    if (i == LEFT) 
		drive.setM1Speed(spd);
    else 
		drive.setM2Speed(spd);
  }

  // A convenience function for setting both motor speeds
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#endif
