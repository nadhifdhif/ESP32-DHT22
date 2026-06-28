#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT22 Sensor Start");

  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();

  // cek apakah gagal membaca sensor
  if (isnan(suhu) || isnan(kelembaban)) {
    Serial.println("Gagal membaca sensor DHT22");
    delay(2000);
    return;
  }

  // tampilkan data ke Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C");

  Serial.print(" | Kelembaban: ");
  Serial.print(kelembaban);
  Serial.println(" %");

  delay(2000);
}
