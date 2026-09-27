# Weather Station – Raspberry Pi + Sense HAT

A real-time weather monitoring system built on Raspberry Pi, developed as part of
the Internet of Things course at Kırıkkale University.

## Overview

The system reads live temperature, humidity, and pressure data from a Sense HAT
sensor board mounted on a Raspberry Pi, displays it on the board's onboard 8x8 LED
matrix, logs it to a local file, and sends it via automated email alerts.

## Hardware

- Raspberry Pi (Model B)
- Sense HAT add-on board (temperature, humidity, pressure sensors + 8x8 RGB LED matrix)
- 32 GB SD card

## Setup

- Installed Raspberry Pi OS via NOOBS (official Raspberry Pi installer) on the SD card.
- Mounted the Sense HAT directly onto the Raspberry Pi's GPIO header.

## Software

- **Language:** Python
- **Libraries:** Sense HAT Python library, `smtplib` (for email)

## How It Works

1. Python script continuously reads temperature, humidity, and pressure from the
   Sense HAT sensors in a loop.
2. Readings are converted to a formatted string and scrolled across the onboard
   8x8 LED matrix in real time.
3. Each reading is timestamped and appended to a local log file (`weather.txt`),
   building a running history of sensor data.
4. A separate routine periodically sends the current sensor readings to a
   specified email address via SMTP.

## Demo

📺 [Watch the demo video](https://www.youtube.com/watch?v=dJdQAzB-5ZQ&list=PLXjsxM2i3iYCzByKdMTYUmyw3jgjcteVb&index=5)

## Code

Source code to be added — see demo video for full walkthrough of the implementation.
