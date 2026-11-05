
#include <Arduino.h>

// Four simulated Mecanum wheel motors
// Each motor uses two LEDs:
// Green = Forward, Red = Reverse

const byte motorPins[4][2] = {
  {2, 3},  // Front Left  (FL)
  {4, 5},  // Front Right (FR)
  {6, 7},  // Rear Left   (RL)
  {8, 9}   // Rear Right  (RR)
};

const char* motorNames[4] = {
  "FL", "FR", "RL", "RR"
};

void setMotor(byte motor, int direction) {
  digitalWrite(
    motorPins[motor][0],
    direction > 0 ? HIGH : LOW
  );

  digitalWrite(
    motorPins[motor][1],
    direction < 0 ? HIGH : LOW
  );
}

void setWheels(int fl, int fr, int rl, int rr) {
  setMotor(0, fl);
  setMotor(1, fr);
  setMotor(2, rl);
  setMotor(3, rr);

  int states[4] = {fl, fr, rl, rr};

  for (int i = 0; i < 4; i++) {
    Serial.print(motorNames[i]);
    Serial.print(": ");

    if (states[i] > 0) {
      Serial.print("FORWARD");
    } else if (states[i] < 0) {
      Serial.print("REVERSE");
    } else {
      Serial.print("STOP");
    }

    Serial.print("  ");
  }

  Serial.println();
}

void executeCommand(String command) {
  command.trim();
  command.toLowerCase();

  Serial.print("Command: ");
  Serial.println(command);

  if (command == "forward" || command == "f") {
    setWheels(1, 1, 1, 1);
  }
  else if (command == "backward" || command == "b") {
    setWheels(-1, -1, -1, -1);
  }
  else if (command == "left" || command == "l") {
    setWheels(-1, 1, -1, 1);
  }
  else if (command == "right" || command == "r") {
    setWheels(1, -1, 1, -1);
  }
  else if (command == "strafeleft" || command == "q") {
    setWheels(-1, 1, 1, -1);
  }
  else if (command == "straferight" || command == "e") {
    setWheels(1, -1, -1, 1);
  }
  else if (command == "stop" || command == "s") {
    setWheels(0, 0, 0, 0);
  }
  else {
    Serial.println("Unknown command - STOP");
    setWheels(0, 0, 0, 0);
  }
}

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(50);

  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i][0], OUTPUT);
    pinMode(motorPins[i][1], OUTPUT);
  }

  setWheels(0, 0, 0, 0);

  Serial.println();
  Serial.println("=== Mecanum Robot Simulation ===");
  Serial.println("Arduino UNO - 4 Motors / 8 LEDs");
  Serial.println("Commands:");
  Serial.println("forward, backward, left, right");
  Serial.println("strafeleft, straferight, stop");
  Serial.println("Or use: f b l r q e s");
  Serial.println("================================");
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    executeCommand(command);
  }
}
