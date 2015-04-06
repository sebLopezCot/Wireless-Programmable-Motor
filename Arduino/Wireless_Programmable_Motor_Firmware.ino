/* WIRELESS PROGRAMMABLE MOTOR FIRMWARE */

int MOTOR_DIRECTION_PIN = 2;
int MOTOR_STEP_PIN = 3;

void setup() {
  // Setup the digital outputs for the stepper motor
  pinMode(MOTOR_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR_STEP_PIN, OUTPUT);
}

void loop() {
  
  int i;

  digitalWrite(MOTOR_DIRECTION_PIN, LOW);     // Set the direction.
  delay(100);


  for (i = 0; i<400; i++)       // Iterate for 4000 microsteps.
  {
    digitalWrite(MOTOR_STEP_PIN, LOW);  // This LOW to HIGH change is what creates the
    digitalWrite(MOTOR_STEP_PIN, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    delayMicroseconds(1000);      // This delay time is close to top speed for this
  }                              // particular motor. Any faster the motor stalls.

  //digitalWrite(MOTOR_DIRECTION_PIN, HIGH);    // Change direction.
  delay(100);


  //for (i = 0; i<400; i++)       // Iterate for 4000 microsteps
  //{
    //digitalWrite(MOTOR_STEP_PIN, LOW);  // This LOW to HIGH change is what creates the
    //digitalWrite(MOTOR_STEP_PIN, HIGH); // "Rising Edge" so the easydriver knows to when to step.
    //delayMicroseconds(1000);      // This delay time is close to top speed for this
  //}                              // particular motor. Any faster the motor stalls.

}
