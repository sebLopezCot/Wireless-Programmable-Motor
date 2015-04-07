#include <StepperMotor.h>

/* WIRELESS PROGRAMMABLE MOTOR FIRMWARE */

int MOTOR_DIRECTION_PIN = 2;
int MOTOR_STEP_PIN = 3;

StepperMotor motor(MOTOR_DIRECTION_PIN, MOTOR_STEP_PIN);

void setup() {
  motor.init();
}

void loop() {
  
  motor.spinForRevs(5); // Spin for 5 revolutions CW
  
  while(true){  // Halt the motor
    delay(1000);
  }
}
