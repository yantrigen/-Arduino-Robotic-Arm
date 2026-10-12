/*
 * STEP 2: FULL WORKING CODE (Robotic Arm Main Movement)
 * Yeh code arm ko move karne aur object pick karne ke liye hai.
 * Isey PURI ASSEMBLY hone ke baad upload karein.
 */

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600 
#define SERVO_FREQ 50 

// Pin Mapping for PCA9685
const int basePin     = 0;
const int shoulderPin = 1;
const int elbowPin    = 2;
const int wristPin    = 3;
const int gripperPin  = 4;

void setup() {
  Serial.begin(9600);
  Serial.println("Robotic Arm Started!");

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
  
  homePosition(); // Start hote hi safe position me aao
  delay(2000);
}

void loop() {
  // Demo Movement: Object uthane ki process
  
  // 1. Gripper kholo (Open Gripper)
  moveServo(gripperPin, 130); 
  delay(1000);
  
  // 2. Base ko 45 degree ghumao (Move Right)
  moveServo(basePin, 45);
  delay(1000);
  
  // 3. Shoulder aur Elbow ko neeche jhukao (Reach Down)
  moveServo(shoulderPin, 60);
  moveServo(elbowPin, 120);
  delay(1000);
  
  // 4. Gripper band karo (Pick the Object)
  moveServo(gripperPin, 40); 
  delay(1000);
  
  // 5. Arm ko upar uthao aur Home par aao (Lift & Return)
  homePosition();
  delay(3000); // 3 seconds wait karo wapas repeat karne se pehle
}

//--- Functions ---//

void moveServo(int pin, int angle) {
  // Angle (0-180) ko pulse me convert karke module ko dena
  int pulse = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(pin, 0, pulse);
}

void homePosition() {
  // Sabhi joints ko safe 90-degree position par lana
  moveServo(basePin, 90);
  moveServo(shoulderPin, 90);
  moveServo(elbowPin, 90);
  moveServo(wristPin, 90);
  // Gripper ko slightly close rakhna jab free ho
  moveServo(gripperPin, 90); 
}
