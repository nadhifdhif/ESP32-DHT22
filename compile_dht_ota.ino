#include <DHT.h

#define DHTPIN 9
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Sensor Mulai");

  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity()

  // cek apakah gagal membaca sensor
  if (isnan(suhu) || isnan(kelembapan)) {
    Serial.println("Gagal membaca sensor DHT22");
    delay(2000);
    return;
  }

  // tampilkan data ke Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C");

  Serial.print(" | Kelembaban: ");
  Serial.print(kelembapan);
  Serial.println(" %");

  delay(2000);
}
