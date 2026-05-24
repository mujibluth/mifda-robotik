// =========================
// PIN MOTOR KIRI
// =========================
int ENA = 5;
int IN1 = 8;
int IN2 = 9;

// =========================
// PIN MOTOR KANAN
// =========================
int ENB = 6;
int IN3 = 10;
int IN4 = 11;

void setup() {

  Serial.begin(9600);

  // Set pin output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Kecepatan motor
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void loop() {

  // =========================
  // MAJU
  // =========================
  Serial.println("Robot Maju");

  // Motor kiri maju
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor kanan maju
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  delay(5000); // maju 5 detik


  // =========================
  // PUTAR / BALIK ARAH
  // =========================
  Serial.println("Robot Berputar");

  // Motor kiri maju
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor kanan mundur
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  delay(1200); 
  // Durasi putar
  // Sesuaikan nanti:
  // lebih kecil = kurang putar
  // lebih besar = lebih banyak putar


  // =========================
  // STOP SEBENTAR
  // =========================
  Serial.println("Robot Stop");

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(1000);
}