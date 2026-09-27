# Distance Sensing with Mobile Dashboard – Wemos D1 + Ultrasonic Sensor + Blynk

A distance-monitoring system with dual control from both a web dashboard and a
mobile app, developed as part of the Internet of Things course at Kırıkkale
University.

## Overview

The Wemos D1 reads distance from an ultrasonic (HC-SR04) sensor and streams the
value to the Blynk cloud platform in real time. A relay-controlled lamp can be
switched on/off from either the Blynk web dashboard or the Blynk mobile app,
alongside live distance readings.

## Hardware

- Wemos D1 (ESP8266-based board)
- HC-SR04 ultrasonic distance sensor
- Relay module (controlling a lamp)

## Wiring

| Sensor Pin | Wemos D1 Pin |
|------------|--------------|
| VCC        | 5V |
| GND        | GND |
| Trig       | D3 |
| Echo       | D4 |

## Software

- **Language:** Arduino C
- **Platform:** Blynk (with auto-generated WiFi/auth credentials via Blynk's Secret tab)

## How It Works

1. A Blynk template is set up with two datastreams: "distance" (read-only) and
   "relay" (read/write).
2. The board connects to WiFi using credentials stored in Blynk's auto-generated
   secrets file.
3. The HC-SR04 measures distance via its Trig/Echo pins in a loop, and the value
   is pushed to the "distance" datastream.
4. The "relay" datastream is bound to a toggle widget, allowing the connected
   lamp to be switched on/off from the Blynk web dashboard.
5. The same dashboard is also accessible from the Blynk mobile app, so distance
   readings update and the relay can be toggled from a phone in real time.
