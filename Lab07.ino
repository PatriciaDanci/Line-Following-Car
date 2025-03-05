// Motor control pins
#define IN1 27  // Left motor forward
#define IN2 26  // Left motor backward
#define IN3 13  // Right motor forward
#define IN4 12  // Right motor backward

// IR sensor pins
#define IR_LEFT 33  // Left IR sensor
#define IR_RIGHT 32 // Right IR sensor

void setup() {
  // Initialize motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize IR sensor pins as inputs
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  Serial.begin(115200);
  Serial.println("Line Following Car with 180-Degree Turn Ready!");
}

void loop() {
  // Read IR sensor values
  int leftSensor = digitalRead(IR_LEFT);   // LOW = Black line, HIGH = White
  int rightSensor = digitalRead(IR_RIGHT); // LOW = Black line, HIGH = White

  // Debugging: Print sensor values
  Serial.print("Left Sensor: ");
  Serial.print(leftSensor);
  Serial.print(" | Right Sensor: ");
  Serial.println(rightSensor);

  // Movement logic
  if (leftSensor == LOW && rightSensor == LOW) {
    // Both sensors detect black: Move forward
    moveForward();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    // Left sensor detects black, right sensor does not: Turn left
    turnLeft();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    // Right sensor detects black, left sensor does not: Turn right
    turnRight();
  } else {
    // Both sensors do not detect black: Turn 180 degrees
    turnBack();
  }

  delay(50);  // Short delay for stability
}

// Function to move forward
void moveForward() {
  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, LOW);   // Left motor backward off
  digitalWrite(IN3, HIGH);  // Right motor forward
  digitalWrite(IN4, LOW);   // Right motor backward off
  Serial.println("Moving Forward...");
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);   // Stop left motor
  digitalWrite(IN2, LOW);   // Left motor off
  digitalWrite(IN3, HIGH);  // Right motor forward
  digitalWrite(IN4, LOW);   // Right motor backward off
  Serial.println("Turning Left...");
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);  // Left motor forward
  digitalWrite(IN2, LOW);   // Left motor backward off
  digitalWrite(IN3, LOW);   // Stop right motor
  digitalWrite(IN4, LOW);   // Right motor off
  Serial.println("Turning Right...");
}

// Function to stop motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  Serial.println("Stopping...");
}

// Function to turn back (180 degrees)
void turnBack() {
  // Left motor backward, right motor forward to rotate in place
  digitalWrite(IN1, LOW);   // Left motor forward off
  digitalWrite(IN2, HIGH);  // Left motor backward
  digitalWrite(IN3, HIGH);  // Right motor forward
  digitalWrite(IN4, LOW);   // Right motor backward off

  Serial.println("Turning Back (180 Degrees)...");
  delay(1500);  // Adjust this value for a full 180-degree turn

  stopMotors(); // Stop after turning
}
