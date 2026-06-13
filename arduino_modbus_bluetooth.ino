#include <SoftwareSerial.h>
#include <ModbusMaster.h>

#define MAX485_RE_DE 2
#define MAX485_RO 10
#define MAX485_DI 11
#define SLAVE_ID 0x16

#define BT_RX 4   // Arduino RX <- HC-05 TXD
#define BT_TX 5   // Arduino TX -> HC-05 RXD

SoftwareSerial rs485Serial(MAX485_RO, MAX485_DI);
SoftwareSerial btSerial(BT_RX, BT_TX);

ModbusMaster node;

void preTransmission() {
  digitalWrite(MAX485_RE_DE, HIGH);
}

void postTransmission() {
  digitalWrite(MAX485_RE_DE, LOW);
}

void setup() {
  pinMode(MAX485_RE_DE, OUTPUT);
  digitalWrite(MAX485_RE_DE, LOW);
  
  Serial.begin(115200);      // USB调试
  rs485Serial.begin(9600);   // RS485传感器
  btSerial.begin(9600);      // HC-06 默认一般是9600

  node.begin(SLAVE_ID, rs485Serial);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
  
  Serial.println("System start...");
  btSerial.println("Bluetooth ready");
}

void loop() {
  // 先让RS485串口成为当前监听口
  rs485Serial.listen();

  uint8_t result = node.readHoldingRegisters(0x0001, 1);

  if (result == node.ku8MBSuccess) {
    uint16_t distance_mm = node.getResponseBuffer(0);
    Serial.println(distance_mm);
    btSerial.println(distance_mm);
  } else {
    Serial.print("ERR:");
    Serial.println(result);

    btSerial.print("ERR:");
    btSerial.println(result);
  }

}
