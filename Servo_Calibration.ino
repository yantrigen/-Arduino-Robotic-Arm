/* 
 * STEP 1: CALIBRATION CODE
 * Yeh code sabhi motors ko 90-degree (center) par set karta hai.
 * Isey 3D parts assemble karne se PEHLE use karein.
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 
#define SERVO_FREQ 50 

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating... Setting all servos to 90 degrees.");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);

  // Pin 0 se 4 tak sabhi servos ko 90 degree par lock karna
  for (int pin = 0; pin <= 4; pin++) {
    int pulse = map(90, 0, 180, SERVOMIN, SERVOMAX);
    pwm.setPWM(pin, 0, pulse);
  }
}

void loop() {
  // Calibration me loop me kuch nahi karna hai, motors 90 par lock rahengi.
}
