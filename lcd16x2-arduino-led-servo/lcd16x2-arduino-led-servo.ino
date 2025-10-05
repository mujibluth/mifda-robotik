#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C (alamat 0x27 umum untuk LCD I2C 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Inisialisasi Servo
Servo palangServo;

// Pin untuk input traffic light (dari modul)
const int RED_PIN = 2;
const int YELLOW_PIN = 3;
const int GREEN_PIN = 4;

// Pin untuk Servo
const int SERVO_PIN = 9;

// Posisi Servo (asumsi: 0 = tutup, 90 = buka penuh)
const int SERVO_TUTUP = 0;
const int SERVO_BUKA = 90;

void setup() {
  // Inisialisasi pin
  pinMode(RED_PIN, INPUT);
  pinMode(YELLOW_PIN, INPUT);
  pinMode(GREEN_PIN, INPUT);

  // Mulai komunikasi dengan LCD
  lcd.begin();
  lcd.backlight();

  // Attach servo ke pin
  palangServo.attach(SERVO_PIN);

  // Set default posisi palang tertutup
  palangServo.write(SERVO_TUTUP);
  lcd.setCursor(0, 0);
  lcd.print("Status: Menutup");
}

void loop() {
  bool merah = digitalRead(RED_PIN);
  bool kuning = digitalRead(YELLOW_PIN);
  bool hijau = digitalRead(GREEN_PIN);

  if (merah) {
    // Lampu merah nyala → palang turun
    palangServo.write(SERVO_TUTUP);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampu: MERAH");
    lcd.setCursor(0, 1);
    lcd.print("Palang Menutup");
  } 
  else if (kuning) {
    // Lampu kuning → proses buka pelan
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampu: KUNING");
    lcd.setCursor(0, 1);
    lcd.print("Buka Palang...");

    // Servo naik pelan
    for (int pos = SERVO_TUTUP; pos <= SERVO_BUKA; pos++) {
      palangServo.write(pos);
      delay(30); // Delay agar gerakan halus
    }
  } 
  else if (hijau) {
    // Lampu hijau → palang sudah terbuka
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lampu: HIJAU");
    lcd.setCursor(0, 1);
    lcd.print("Palang Terbuka");

    // Pastikan palang sudah di posisi buka
    palangServo.write(SERVO_BUKA);
  }

  delay(200); // Delay siklus loop
}
