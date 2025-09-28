#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Alamat I2C biasanya 0x27 atau 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();       // Inisialisasi LCD
  lcd.backlight();  // Nyalakan lampu latar
}

void loop() {
  // 1. Tampilkan teks statis
  lcd.clear();
  lcd.setCursor(0,0); 
  lcd.print("Halo Dunia!");
  lcd.setCursor(0,1);
  lcd.print("Robotik Seru :)");
  delay(2000);

  // 2. Teks berganti otomatis
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Belajar Arduino");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Belajar LCD");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Belajar Servo");
  delay(1500);

  // 3. Teks berjalan (scroll ke kiri)
  String teks = "   Selamat Datang di Ekstra Robotik!   ";
  for (int i=0; i<teks.length(); i++) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(teks.substring(i, i+16)); // tampilkan 16 karakter saja
    delay(300);
  }

  // 4. Efek blink (berkedip)
  for (int i=0; i<5; i++) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Teks Kedip!");
    delay(400);
    lcd.clear();
    delay(400);
  }

  // Ulang dari awal
}
