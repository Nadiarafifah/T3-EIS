// Deklarasi pin
const int sensorPin = A0; // Pin analog sensor tanah terhubung

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
}

void loop() {
  // Membaca nilai analog dari sensor
  int sensorValue = analogRead(sensorPin);

  // Mengonversi nilai analog ke kelembaban tanah dalam persen
  int moisturePercentage = map(sensorValue, 0, 1023, 100, 0);

  // Menampilkan kelembaban tanah pada Serial Monitor
  Serial.print("Kelembaban Tanah: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  delay(500); // Delay 1 detik
}