Smart Street Light 💡
An Arduino-based intelligent street lighting system that uses an LDR module to detect ambient light and dual IR sensors to detect vehicle movement. The system improves energy efficiency by controlling street LEDs based on environmental conditions and motion.

Features
Ambient light detection using LDR
Dual IR-based vehicle detection
Automatic LED control
Serial monitoring for debugging

Working Logic
During bright conditions, LDR allows normal LED operation
During dark conditions, LEDs respond to IR vehicle detection
IR sensors are active LOW
Serial monitor shows real-time sensor status

| Component         | Arduino Pin |
| ----------------- | ----------- |
| IR Sensor 1 (OUT) | 3           |
| IR Sensor 2 (OUT) | 4           |
| LDR Module (DO)   | 9           |
| LED (IR1)         | 5           |
| LED (IR2)         | 6           |
| LED (LDR1)        | 7           |
| LED (LDR2)        | 8           |

IR sensors are active LOW, meaning:
Object detected → LOW
No object → HIGH
That’s why your logic checks:
ir1State == LOW

