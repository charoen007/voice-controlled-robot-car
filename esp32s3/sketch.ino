
#include <Arduino.h>

// ESP32-S3 UART transmitter
constexpr int UART_RX = 18;
constexpr int UART_TX = 17;
constexpr uint32_t UART_BAUD = 9600;
constexpr uint32_t USB_BAUD = 115200;
constexpr unsigned long SEND_INTERVAL = 200;

HardwareSerial RobotSerial(1);

char currentCommand = 'S';
unsigned long lastSent = 0;

char parseCommand(String input) {
  input.trim();
  input.toLowerCase();

  if (input == "forward") return 'F';
  if (input == "backward") return 'B';
  if (input == "left") return 'L';
  if (input == "right") return 'R';
  if (input == "strafeleft") return 'Q';
  if (input == "straferight") return 'E';
  if (input == "stop") return 'S';

  return '?';
}

void sendCommand() {
  RobotSerial.write(currentCommand);
  RobotSerial.write('\n');
  lastSent = millis();
}

void setup() {
  Serial.begin(USB_BAUD);

  RobotSerial.begin(
    UART_BAUD, SERIAL_8N1, UART_RX, UART_TX
  );

  Serial.println("Voice Robot - ESP32-S3");
  Serial.println("Commands:");
  Serial.println("forward, backward, left, right");
  Serial.println("strafeleft, straferight, stop");

  sendCommand();
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    char command = parseCommand(input);

    if (command != '?') {
      currentCommand = command;
      sendCommand();

      Serial.print("Active command: ");
      Serial.println(currentCommand);
    } else {
      currentCommand = 'S';
      sendCommand();
      Serial.println("Invalid command - STOP");
    }
  }

  if (millis() - lastSent >= SEND_INTERVAL) {
    sendCommand();
  }
}
