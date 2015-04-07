/* WIRELESS PROGRAMMABLE MOTOR FIRMWARE */

#include <SoftwareSerial.h>
#include <StepperMotor.h>

int MOTOR_DIRECTION_PIN = 2;
int MOTOR_STEP_PIN = 3;
int BLUETOOTH_TX_PIN = 4;
int BLUETOOTH_RX_PIN = 5;

StepperMotor motor(MOTOR_DIRECTION_PIN, MOTOR_STEP_PIN);
SoftwareSerial bluetooth(BLUETOOTH_TX_PIN, BLUETOOTH_RX_PIN);

void setup() {
  // Setup the stepper motor
  motor.init();
  
  // Setup the serial connection for debugging
  Serial.begin(9600);
  
  // Setup the bluetooth module
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600); // Start bluetooth serial at 9600
}

void loop() {
  if(bluetooth.available())  // If the bluetooth master sent any characters
  {
    char c = (char)bluetooth.read();
    
    // Send any characters the bluetooth prints to the serial monitor for debugging
    Serial.print(c);  
    
    // Process the incoming commands and map them to motor outputs
    if(c == 'l'){
      Serial.println();
      Serial.println("SPINNING LEFT");
      motor.spinForRevs(-1.0);
      Serial.println("DONE.");
    } else if (c == 'r'){
      Serial.println();
      Serial.println("SPINNING RIGHT");
      motor.spinForRevs(1.0);
      Serial.println("DONE.");
    }
  }
}
