#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ubah 0x27 jika perlu

void setup() {
  myServo.attach(9);
  lcd.init();         // Gunakan init() jika pakai FM library
  lcd.backlight();
}

void loop() {
  myServo.write(45);
  tampilkanLCD("lihat : kiri");
  delay(1000);

  myServo.write(135);
  tampilkanLCD("lihat : kanan");
  delay(1000);

  myServo.write(45);
  tampilkanLCD("lihat : kiri");
  delay(1000);
}

void tampilkanLCD(String pesan) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(pesan);
}

// check i2c scanner

// #include <Wire.h>

// void setup() {
//   Wire.begin();
//   Serial.begin(9600);
//   Serial.println("Mencari perangkat I2C...");
// }

// void loop() {
//   byte error, address;
//   int nDevices = 0;

//   for (address = 1; address < 127; address++) {
//     Wire.beginTransmission(address);
//     error = Wire.endTransmission();

//     if (error == 0) {
//       Serial.print("Perangkat I2C ditemukan di alamat 0x");
//       if (address < 16)
//         Serial.print("0");
//       Serial.print(address, HEX);
//       Serial.println(" !");

//       nDevices++;
//     } else if (error == 4) {
//       Serial.print("Kesalahan tak dikenal di alamat 0x");
//       if (address < 16)
//         Serial.print("0");
//       Serial.println(address, HEX);
//     }
//   }

//   if (nDevices == 0)
//     Serial.println("Tidak ada perangkat I2C ditemukan\n");
//   else
//     Serial.println("Selesai\n");

//   delay(5000); // Scan ulang setiap 5 detik
// }
