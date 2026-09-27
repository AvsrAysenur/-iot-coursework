#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

// --- WiFi credentials ---
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

// --- ThingSpeak credentials ---
unsigned long channelID = 0000000;         // your ThingSpeak channel ID
const char* writeAPIKey = "YOUR_WRITE_API_KEY";

// --- DHT11 setup ---
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// --- Alarm ---
const int ALARM_PIN = D5;
const float HUMIDITY_THRESHOLD = 20.0;

WiFiClient client;

void setup() {
  Serial.begin(115200);

  pinMode(ALARM_PIN, OUTPUT);
  digitalWrite(ALARM_PIN, LOW);

  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected!");

  ThingSpeak.begin(client);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Alarm logic
  if (humidity > HUMIDITY_THRESHOLD) {
    digitalWrite(ALARM_PIN, HIGH);
  } else {
    digitalWrite(ALARM_PIN, LOW);
  }

  // Send to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  int response = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (response == 200) {
    Serial.println("ThingSpeak update successful");
  } else {
    Serial.println("ThingSpeak update failed, error: " + String(response));
  }

  delay(20000); // ThingSpeak free tier requires at least 15s between updates
}
