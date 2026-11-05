
const int motorPins[4][2] = {
  {2, 3},   // Front Left
  {4, 5},   // Front Right
  {6, 7},   // Rear Left
  {8, 9}    // Rear Right
};

const char* motorNames[4] = {
  "Front Left", "Front Right",
  "Rear Left", "Rear Right"
};

void setMotor(int motor, int direction) {
  digitalWrite(motorPins[motor][0],
               direction > 0 ? HIGH : LOW);
  digitalWrite(motorPins[motor][1],
               direction < 0 ? HIGH : LOW);
}

void moveRobot(int fl, int fr, int rl, int rr) {
  int directions[4] = {fl, fr, rl, rr};

  for (int i = 0; i < 4; i++) {
    setMotor(i, directions[i]);
    Serial.print(motorNames[i]);
    Serial.print(": ");
    Serial.println(directions[i] > 0 ? "FORWARD" :
                   directions[i] < 0 ? "REVERSE" :
                   "STOP");
  }
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i][0], OUTPUT);
    pinMode(motorPins[i][1], OUTPUT);
  }

  moveRobot(0, 0, 0, 0);
  Serial.println("Mecanum Robot Ready");
  Serial.println("Commands: forward, backward,");
  Serial.println("left, right, strafeleft,");
  Serial.println("straferight, stop");
}

void loop() {
  if (!Serial.available()) return;

  String cmd = Serial.readStringUntil('\n');
  cmd.trim();
  cmd.toLowerCase();

  if (cmd == "forward")
    moveRobot(1, 1, 1, 1);
  else if (cmd == "backward")
    moveRobot(-1, -1, -1, -1);
  else if (cmd == "left")
    moveRobot(-1, 1, -1, 1);
  else if (cmd == "right")
    moveRobot(1, -1, 1, -1);
  else if (cmd == "strafeleft")
    moveRobot(-1, 1, 1, -1);
  else if (cmd == "straferight")
    moveRobot(1, -1, -1, 1);
  else if (cmd == "stop")
    moveRobot(0, 0, 0, 0);
  else
    Serial.println("Unknown command");
}
