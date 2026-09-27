#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address 0x27, 16 columns, 2 rows (adjust address if yours differs, e.g. 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

bool deviceOn = false;

void setup() {
  Wire.begin(); // SDA -> D2, SCL -> D1 by default on Wemos D1

  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();

  // First row: label, starting one character in
  lcd.setCursor(1, 0);
  lcd.print("odev");

  // Second row: dynamic device status
  lcd.setCursor(0, 1);
  deviceOn = !deviceOn;
  lcd.print(deviceOn ? "Durum: Acik" : "Durum: Kapali");

  delay(3000);
}
