# Cloud Temperature/Humidity Monitoring with Alarm – ESP8266 + DHT11 + ThingSpeak

A cloud-connected environmental monitoring system that streams live temperature
and humidity data to ThingSpeak and triggers a visual alarm when a threshold is
exceeded, developed as part of the Internet of Things course at Kırıkkale
University.

## Overview

An ESP8266-based board reads temperature and humidity from a DHT11 sensor and
pushes the readings to a ThingSpeak channel over WiFi. When the humidity value
crosses a configured threshold, an alarm indicator (warning light) is triggered.

## Hardware

- ESP8266 (Wemos D1 / NodeMCU)
- DHT11 temperature & humidity sensor
- LED (alarm indicator)

## Wiring

| DHT11 Pin | ESP8266 Pin |
|-----------|-------------|
| VCC       | 3.3V/5V |
| GND       | GND |
| Data      | D4 |

## Software

- **Language:** Arduino C
- **Libraries:** DHT sensor library (DHT11), ThingSpeak library
- **Cloud platform:** ThingSpeak

## How It Works

1. A ThingSpeak channel ("My Channel") is created with fields for temperature
   and humidity.
2. The board connects to WiFi and authenticates with ThingSpeak using the
   channel ID and Write API key.
3. On each loop iteration, the DHT11 sensor is read, and the values are
   uploaded to the ThingSpeak channel, where they appear as live graphs.
4. A threshold check (e.g. humidity above a set value) triggers a warning
   indicator, turning it on when the condition is met and off otherwise.

## Demo

📺 [Watch the demo video](PASTE_YOUTUBE_LINK_HERE)

## Code

Source code to be added — see demo video for full walkthrough of the implementation.
