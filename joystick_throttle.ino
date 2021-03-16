#include <Joystick.h>

// Define the TinyStick input pins
#define joyX A0
#define joyY A1
#define joyThrottle A2
#define joyButton1 9
#define joyButton2 8
#define joyButton3 7
#define joyButton4 10

// Create instance of Joystick
// HID id, Type, Button Cnt, hat count, include X, Y, Z, Rx, Ry, Rz, Rudder, Throttle, Accellerator, Brake, Steering
Joystick_ Joystick(0x15, JOYSTICK_TYPE_JOYSTICK, 4, 0, true, true, false, false, false, false, false, true, false, false, false);

// Init send state always
const bool initAutoSendState = true;

// Init joystick axis
int xAxis_ = 0;
int yAxis_ = 0;
int rzAxis_ = 0;
int throttle_ = 0;

// Init buttons and states
int lastBunnon1State = 0;
int lastBunnon2State = 0;
int lastBunnon3State = 0;
int lastBunnon4State = 0;


void setup() {
  // Set pullups on buttons
  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);

  // Start Joystick
  Joystick.begin();

}

void loop() {
  // Start the polling loop for the xAxis
  xAxis_ = analogRead(joyX);
  xAxis_ = map(xAxis_, 0, 1023, 0, 255);
  Joystick.setXAxis(xAxis_);

  // Start the polling loop for the yAxis
  yAxis_ = analogRead(joyY);
  yAxis_ = map(yAxis_, 0, 1023, 0, 255);
  Joystick.setYAxis(yAxis_);

  // Start the polling loop for the throttle
  throttle_ = analogRead(joyThrottle);
  throttle_ = map(throttle_, 0, 1023, 0, 255);
  Joystick.setThrottle(throttle_);

  // Start the polling on button 1 with change on last state variable
  int currentButton1State = !digitalRead(joyButton1);
  if (currentButton1State != lastBunnon1State) {
    Joystick.setButton(0, currentButton1State);
    lastBunnon1State = currentButton1State;
  }

  // Start the polling on button 2 with change on last state variable
  int currentButton2State = !digitalRead(joyButton2);
  if (currentButton2State != lastBunnon2State) {
    Joystick.setButton(1, currentButton2State);
    lastBunnon2State = currentButton2State;
  }

  // Start the polling on button 3 with change on last state variable
  int currentButton3State = !digitalRead(joyButton3);
  if (currentButton3State != lastBunnon3State) {
    Joystick.setButton(2, currentButton3State);
    lastBunnon3State = currentButton3State;
  }

  // Start the polling on button 4 with change on last state variable
  int currentButton4State = !digitalRead(joyButton4);
  if (currentButton4State != lastBunnon4State) {
    Joystick.setButton(3, currentButton4State);
    lastBunnon4State = currentButton4State;
  }
  
  // Delay for ten milliseconds for loop restart
  delay(10);
}