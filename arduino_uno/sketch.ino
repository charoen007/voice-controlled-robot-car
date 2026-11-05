
#include <Arduino.h>
#include <SoftwareSerial.h>

// UART from ESP32-S3
constexpr int UART_RX = 10;
constexpr int UART_TX = 11;
constexpr unsigned long TIMEOUT_MS = 1000;

// Motor direction outputs
// Each pair represents IN1 and IN2
const uint8_t motorPins[4][2] = {
  {2, 3},  // Front Left
  {4, 5},  // Front Right
  {6, 7},  // Rear Left
  {8, 9}   // Rear Right
};

SoftwareSerial robotSerial(UART_RX, UART_TX);

unsigned long lastReceived = 0;
char activeCommand = 'S';

void setMotor(uint8_t index, int direction) {
  digitalWrite(
    motorPins[index][0],
    direction > 0 ? HIGH : LOW
  );

  digitalWrite(
    motorPins[index][1],
    direction < 0 ? HIGH : LOW
  );
}

void setWheels(int fl, int fr, int rl, int rr) {
  setMotor(0, fl);
  setMotor(1, fr);
  setMotor(2, rl);
  setMotor(3, rr);
}

void executeCommand(char command) {
  switch (command) {
    case 'F':
      setWheels(1, 1, 1, 1);
      break;

    case 'B':
      setWheels(-1, -1, -1, -1);
      break;

    case 'L':
      setWheels(-1, 1, -1, 1);
      break;

    case 'R':
      setWheels(1, -1, 1, -1);
      break;

    case 'Q':
      setWheels(-1, 1, 1, -1);
      break;

    case 'E':
      setWheels(1, -1, -1, 1);
      break;

    default:
      setWheels(0, 0, 0, 0);
      break;
  }
}

bool isValidCommand(char command) {
  return command == 'F' ||
         command == 'B' ||
         command == 'L' ||
         command == 'R' ||
         command == 'Q' ||
         command == 'E' ||
         command == 'S';
}

void setup() {
  Serial.begin(115200);
  robotSerial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i][0], OUTPUT);
    pinMode(motorPins[i][1], OUTPUT);
  }

  executeCommand('S');

  Serial.println("Arduino Motor Controller Ready");
}

void loop() {
  while (robotSerial.available()) {
    char incoming = robotSerial.read();

    if (isValidCommand(incoming)) {
      activeCommand = incoming;
      lastReceived = millis();

      executeCommand(activeCommand);
    }
  }

  if (millis() - lastReceived > TIMEOUT_MS) {
    if (activeCommand != 'S') {
      activeCommand = 'S';
      executeCommand('S');
      Serial.println("UART timeout - motors stopped");
    }
  }
}
