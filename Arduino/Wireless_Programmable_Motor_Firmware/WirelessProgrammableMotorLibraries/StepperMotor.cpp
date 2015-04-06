#include "StepperMotor.h"

StepperMotor::StepperMotor(int directionPin, int stepPin){
	MOTOR_DIRECTION_PIN = directionPin;
	MOTOR_STEP_PIN = stepPin;
	MOTOR_DELAY_INCREMENT = TOP_SPEED_DELAY_TIME;

	// Setup the digital outputs for the stepper motor
  	pinMode(MOTOR_DIRECTION_PIN, OUTPUT);
  	pinMode(MOTOR_STEP_PIN, OUTPUT);
}

void StepperMotor::setMotorDelayIncrement(int delay){
	if(delay >= TOP_SPEED_DELAY_TIME){
		MOTOR_DELAY_INCREMENT = delay;
	}
}

void StepperMotor::setDirection(int direction){
	if(direction == CW){
		digitalWrite(MOTOR_DIRECTION_PIN, LOW);
	} else if (direction == CCW){
		digitalWrite(MOTOR_DIRECTION_PIN, HIGH);
	}
}

void StepperMotor::spinForDegrees(double degrees){
	int stepsNeeded = (int)(STEPS_PER_REV * degrees / 360.0);
	spinForSteps(stepsNeeded);
}

void StepperMotor::spinForRadians(double rads){
	double PI = 3.1415926;
	int stepsNeeded = (int)(STEPS_PER_REV * rads / (2 * PI));
	spinForSteps(stepsNeeded);
}

void StepperMotor::spinForRevs(double revs){
	int stepsNeeded = (int)(STEPS_PER_REV * revs);
	spinForSteps(stepsNeeded);
}

void StepperMotor::spinForSteps(int steps){
	// Set the direction of motion
	if(steps > 0){
		setDirection(CW);
	} else {
		setDirection(CCW);
	}

	// Move for certain number of steps
	int i=0;
	for(i=0; i < steps; i++){
		digitalWrite(MOTOR_STEP_PIN, LOW);  // This LOW to HIGH change is what creates the
    	digitalWrite(MOTOR_STEP_PIN, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    	delayMicroseconds(MOTOR_DELAY_INCREMENT);
	}
}

void StepperMotor::spinCW(){
	spinForSteps(1); // Performs a single step that is meant to be continuously called
}

void StepperMotor::spinCCW(){
	spinForSteps(-1); // Performs a single step that is meant to be continuously called
}
