# -Arduino-Robotic-Arm
5-Degrees of Freedom 3D Printed Robotic Arm with rack &amp; pinion mechanism. Developed using Arduino, C++, and a 16-channel PCA9685 driver for smooth automation.
# 🤖 5-DOF 3D Printed Arduino Robotic Arm

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)](#)

A 5-Degrees of Freedom (DOF) 3D-printed robotic arm project developed for precise mechanical automation and payload handling. The arm utilizes a rack-and-pinion gripper mechanism and is controlled via an Arduino Uno interfaced with a PCA9685 16-channel PWM driver for smooth, multi-servo synchronized movements.

---

## ✨ Key Features
*   **5-Axis Articulation:** Base pan, shoulder pitch, elbow pitch, wrist roll/pitch, and gripper actuation.
*   **High-Torque Joints:** Utilizes MG996R metal-gear servos for the primary load-bearing joints (Base, Shoulder, Elbow) to ensure stability and payload capacity.
*   **Precision Gripping:** Rack-and-pinion end-effector powered by an SG90 micro-servo.
*   **Dedicated PWM Control:** Offloads PWM signal generation to the I2C-based PCA9685 module, preventing Arduino overload and jitter.

---

## 🛠️ Hardware Bill of Materials (BOM)
| Component | Quantity | Description |
| :--- | :---: | :--- |
| **Arduino Uno R3** | 1 | Main microcontroller unit |
| **PCA9685 Module** | 1 | 16-Channel 12-bit PWM Servo Driver |
| **MG996R Servo** | 3 | High-torque servos for Base, Shoulder, Elbow |
| **SG90 Micro Servo** | 2 | Lightweight servos for Wrist and Gripper |
| **5V Power Supply** | 1 | 5V, 3A or 5A External DC Power Adapter |
| **3D Printed Parts** | 1 Set | Base, Links, Brackets, and Rack-Pinion Gripper (PLA/PETG) |

---

## 🔌 Circuit & Wiring Guide

**⚠️ CRITICAL WARNING:** Never power all 5 servos directly from the Arduino's 5V pin. It will burn the Arduino. Always use an external power supply connected directly to the PCA9685 module and ensure the ground (GND) is shared.

### PCA9685 to Arduino Connections
| PCA9685 Pin | Arduino Uno Pin | Function |
| :---: | :---: | :--- |
| **VCC** | 5V | Powers the logic circuit of the module |
| **GND** | GND | Common Ground (Must connect to Arduino AND External Power GND) |
| **SDA** | A4 | I2C Data Line |
| **SCL** | A5 | I2C Clock Line |
| **V+ (Terminal)** | External 5V (+) | Dedicated power for Servos |
| **GND (Terminal)**| External 5V (-) | Dedicated ground for Servos |

### Servo Mapping on PCA9685
*   `Pin 0` - Base Rotation
*   `Pin 1` - Shoulder Joint
*   `Pin 2` - Elbow Joint
*   `Pin 3` - Wrist Joint
*   `Pin 4` - Gripper (Open/Close)

---

## 💻 Software Setup & Installation

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/yantrigen/Arduino-Robotic-Arm.git](https://github.com/yantrigen/Arduino-Robotic-Arm.git)
