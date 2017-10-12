#include <CurieBLE.h>

BLEPeripheral blePeripheral;
BLEService bleService("03B80E5A-EDE8-4B33-A751-6CE34EC4C700");
BLECharacteristic bleCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLEWrite | BLEWriteWithoutResponse | BLENotify | BLERead, 5);

uint8_t data[] = {0, 0, 0, 0, 0};

void setup() {
  Serial.begin(9600);

  // set advertised local name and service UUID:
  blePeripheral.setLocalName("RSSI");
  blePeripheral.setDeviceName("RSSI");
  blePeripheral.setAdvertisedServiceUuid(bleService.uuid());

  // add service and characteristic:
  blePeripheral.addAttribute(bleService);
  blePeripheral.addAttribute(bleCharacteristic);

  blePeripheral.setEventHandler(BLEConnected, bleDeviceConnectHandler);
  blePeripheral.setEventHandler(BLEDisconnected, bleDeviceDisconnectHandler);
  
  bleCharacteristic.setEventHandler(BLEWritten, bleCharacteristicWritten);
  bleCharacteristic.setValue(data, 5);

  // begin advertising BLE service:
  blePeripheral.begin();
}

void loop() {
  delay(200);
}

void bleDeviceConnectHandler(BLECentral& central) {
  // central connected event handler
  Serial.print("Connected event, central: ");
  Serial.println(central.address());
}

void bleDeviceDisconnectHandler(BLECentral& central) {
  // central disconnected event handler
  Serial.print("Disconnected event, central: ");
  Serial.println(central.address());
}

void bleCharacteristicWritten(BLECentral& central, BLECharacteristic& characteristic) {
  // central wrote new value to characteristic, update LED
  Serial.write((const char *) characteristic.value());
  Serial.println();
}



