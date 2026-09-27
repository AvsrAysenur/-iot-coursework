# I2C LCD Status Display – Wemos D1

A simple status display system that shows text and device state on a 16x2 I2C
LCD screen, developed as part of the Internet of Things course at Kırıkkale
University.

## Overview

The Wemos D1 drives a 16x2 character LCD over the I2C bus, writing custom text
to specific rows/columns and cycling through a status message loop.

## Hardware

- Wemos D1 (ESP8266-based board)
- 16x2 I2C LCD display module
- Breadboard + jumper wires

## Wiring

| LCD Pin | Wemos D1 Pin |
|---------|--------------|
| GND     | GND |
| VCC     | 5V |
| SDA     | SDA (D2) |
| SCL     | SCL (D1) |

## Software

- **Language:** Arduino C
- **Library:** LiquidCrystal_I2C (or equivalent I2C LCD library)

## How It Works

1. The LCD is initialized over I2C using its address, columns, and rows.
2. On the first row, the script writes a label ("ödev") after positioning the
   cursor with an offset (leading blank space).
3. The second row is used to display a dynamic device status ("açık" / "kapalı"),
   toggling on each loop iteration.
4. The display is cleared and rewritten every few seconds inside `loop()`,
   creating a continuously updating status readout.

## Demo

📺 [Watch the demo video](PASTE_YOUTUBE_LINK_HERE)

## Code

Source code to be added — see demo video for full walkthrough of the implementation.
