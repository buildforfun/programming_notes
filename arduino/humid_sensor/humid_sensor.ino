#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11 (you can also use DHT22 or DHT21)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Print CSV header
  Serial.println("Timestamp,Humidity,Temperature_C,Temperature_F,HeatIndex_C,HeatIndex_F");
}

void loop() {
  delay(10000);

  unsigned long timestamp = millis();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  // Print data in CSV format
  Serial.print(timestamp);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.print(f);
  Serial.print(",");
  Serial.print(hic);
  Serial.print(",");
  Serial.println(hif);
}