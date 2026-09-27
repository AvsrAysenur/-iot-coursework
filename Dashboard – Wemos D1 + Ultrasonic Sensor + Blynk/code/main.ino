#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "IoT Distance Monitor"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// --- WiFi credentials ---
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// --- Pin definitions ---
const int TRIG_PIN = D3;
const int ECHO_PIN = D4;
const int RELAY_PIN = D5;

// --- Blynk virtual pins ---
#define VPIN_DISTANCE V0
#define VPIN_RELAY V1

BlynkTimer timer;

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  if (duration == 0) return -1; // no echo received

  float distance = duration * 0.0343 / 2.0; // speed of sound = 343 m/s
  return distance;
}

void sendSensorData() {
  float distance = readDistanceCM();
  if (distance >= 0) {
    Blynk.virtualWrite(VPIN_DISTANCE, distance);
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}

// Called whenever the relay toggle widget changes in the Blynk app/dashboard
BLYNK_WRITE(VPIN_RELAY) {
  int value = param.asInt();
  digitalWrite(RELAY_PIN, value ? HIGH : LOW);
}

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000L, sendSensorData); // read + push every 1 second
}

void loop() {
  Blynk.run();
  timer.run();
}
