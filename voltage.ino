#include "ZMPT101B.h"
#define FIRMWARE_VERSION "1.0"

const float A_CALIBRATION = 2.35;
const float B_CALIBRATION = -1.90;

ZMPT101B voltageSensor(A0,30);                          // ZMPT101B sensor connected to A0 pin of arduino

void setup(){
  Serial.begin(9600);
  Serial.println("Booting");
  Serial.print("--Firmware Version:");
  Serial.println(FIRMWARE_VERSION);
  

  voltageSensor.set_a_b(A_CALIBRATION, B_CALIBRATION);
}

void loop() {

  float V = voltageSensor.get_ac();
  Serial.println(String("V = ") + V + " V");
  delay(1000);
}
