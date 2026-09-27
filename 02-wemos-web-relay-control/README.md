# Remote Relay/LED/Buzzer Control – Wemos D1

A WiFi-based control system that lets you switch a relay, LED, and buzzer on
and off from any device on the local network through a simple web page served
by the Wemos D1 itself, developed as part of the Internet of Things course at
Kırıkkale University.

## Overview

The Wemos D1 connects to a local WiFi network, hosts a lightweight HTML control
page, and exposes buttons to toggle a relay (driving a lamp), an LED, and a
buzzer — all controlled remotely over the local network via the device's IP
address, no external cloud service required.

## Hardware

- Wemos D1 (ESP8266-based board)
- Relay module
- LED + resistor
- Buzzer
- Breadboard + jumper wires

## Wiring

| Component | Pin on Wemos D1 |
|-----------|------------------|
| LED (+)   | D9 (via resistor) |
| LED (−)   | GND |
| Relay VCC | 5V |
| Relay GND | GND |
| Relay Signal | D9 (shared control line) |
| Buzzer +  | 5V |
| Buzzer −  | GND |

## Software

- **Language:** Arduino C
- **Board:** Wemos D1 (ESP8266)

## How It Works

1. On boot, the Wemos D1 connects to the configured WiFi network (SSID + password
   set in the sketch).
2. Once connected, the board prints its assigned local IP address to the serial
   monitor.
3. The device runs a small embedded web server that serves an HTML page with
   on/off buttons for the LED, relay, and buzzer.
4. Navigating to the Wemos D1's IP address from any browser on the same network
   loads this control page.
5. Clicking a button sends a request back to the Wemos D1, which sets the
   corresponding GPIO pin HIGH or LOW — turning the relay (and the lamp
   connected to it), LED, or buzzer on or off in real time.

## Demo

📺 [Watch the demo video](https://www.youtube.com/watch?v=dJdQAzB-5ZQ&list=PLXjsxM2i3iYCzByKdMTYUmyw3jgjcteVb)

## Code

Source code to be added — see demo video for full walkthrough of the implementation.
