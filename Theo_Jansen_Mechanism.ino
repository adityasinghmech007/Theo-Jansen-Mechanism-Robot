#include <AccelStepper.h>

// Define pins for buttons
int buttonpin1 = 11;
int buttonpin2 = 10;

// Create stepper motor objects
AccelStepper stepper1(1, 3, 2); // Motor 1 (Typeof driver: with 2 pins, STEP, DIR)
AccelStepper stepper2(1, 5, 4); // Motor 2 (Typeof driver: with 2 pins, STEP, DIR)

int j = 0;

void setup() {
  Serial.begin(19200);

  // Configure button pins as input
  pinMode(buttonpin1, INPUT);
  pinMode(buttonpin2, INPUT);

  // Configure stepper motors
  stepper1.setMaxSpeed(1000);
  stepper1.setAcceleration(1000);

  stepper2.setMaxSpeed(1000);
  stepper2.setAcceleration(1000);
}

/**
 * Moves motor1 faster than motor2.
 * @param steps Base steps for motor2. Motor1 will be 2x faster.
 */
void moveMotor1Faster(int steps) {
  stepper1.setMaxSpeed(1500); // Motor1 faster speed
  stepper2.setMaxSpeed(500);  // Motor2 slower speed

  stepper1.move(2 * steps);
  stepper2.move(steps);

  runMotorsToPosition();
}

/**
 * Moves motor2 faster than motor1.
 * @param steps Base steps for motor1. Motor2 will be 2x faster.
 */
void moveMotor2Faster(int steps) {
  stepper1.setMaxSpeed(500);  // Motor1 slower speed
  stepper2.setMaxSpeed(1500); // Motor2 faster speed

  stepper1.move(steps);
  stepper2.move(2 * steps);

  runMotorsToPosition();
}

/**
 * Moves both motors at the same speed.
 * @param steps Steps for both motors to move.
 */
void moveBothMotorsSameSpeed(int steps) {
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);

  stepper1.move(steps);
  stepper2.move(steps);

  runMotorsToPosition();
}

/**
 * Runs both motors to their target position.
 */
void runMotorsToPosition() {
  while (stepper1.isRunning() || stepper2.isRunning()) {
    stepper1.run();
    stepper2.run();
  }
}

void loop() {
  moveMotor1Faster(1000);
  moveMotor2Faster(1000);
  moveBothMotorsSameSpeed(3000);

}


