#ifndef StepperMotor_h
#define StepperMotor_h

#include "Arduino.h"

class StepperMotor{
public:
	StepperMotor(int directionPin, int stepPin);
	
	void init();

	void setMotorDelayIncrement(int delay);

	void spinForDegrees(double degrees);
	void spinForRadians(double rads);
	void spinForRevs(double revs);
	void spinForSteps(int steps);

	void spinCW();
	void spinCCW();

private:
	int MOTOR_DIRECTION_PIN;
	int MOTOR_STEP_PIN;
	int MOTOR_DELAY_INCREMENT;

	static const int CW = 0;
	static const int CCW = 1;

	static const int TOP_SPEED_DELAY_TIME = 200; // milliseconds
	static const int STEPS_PER_REV = 400;
	static const int MICROSTEPS_PER_STEP = 8;	// In default 1/8th microstep mode
	static const int MICROSTEPS_PER_REV = STEPS_PER_REV * MICROSTEPS_PER_STEP;

	void setDirection(int direction);
};

#endif