// Pin Motor Kiri
int ENA = 5;
int IN1 = 8;
int IN2 = 9;

// Pin Motor Kanan
int ENB = 6;
int IN3 = 10;
int IN4 = 11;

void setup() {

  // Memulai Serial Monitor
  Serial.begin(9600);

  // Set pin sebagai output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Kecepatan motor
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  // Motor kiri maju
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor kanan maju
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  Serial.println("Robot Bergerak Maju");
}

void loop() {

  // Tampilkan status tiap 1 detik
  Serial.println("Bergerak Maju");

  delay(1000);
}