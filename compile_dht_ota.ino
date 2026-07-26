#include <DHT.h>

#define DHTPIN 11
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Sensor Mulai");

  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembapan = dht.readHumidity();

  // cek apakah gagal membaca sensor
  if (isnan(Temperature) || isnan(Humidity)) {
    Serial.println("Gagal membaca sensor DHT22");
    delay(2000);
    return;
  }

  // tampilkan data ke Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(Temperature);
  Serial.print(" °C");

  Serial.print(" | Kelembaban: ");
  Serial.print(Humidity);
  Serial.println(" %");

  delay(2000);
}
