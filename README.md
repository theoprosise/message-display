# Message Display Documentation


![Example Image](IMG_2843.jpg)
## Introduction

This repository provides directions and code necessary to create an ESP-32 powered E-Ink text display that can be updated from a web browser located anywhere on the globe.

## Table of Contents

- [Materials Required](#materials-required)
- [Setting Up Supabase](#setting-up-supabase)
- [Hardware Assembly](#hardware-assembly)
- [Software Setup](#software-setup)
- [Alter the Code](#alter-the-code)
- [How to Use](#how-to-use)


## Materials Required

- ESP32 - [Amazon](https://www.amazon.com/ESP-WROOM-32-Development-Microcontroller-Integrated-Compatible/dp/B08D5ZD528/ref=sr_1_3?crid=1ZSS5VPA1SGZ6&keywords=esp32&qid=1706592041&sprefix=esp3%2Caps%2C87&sr=8-3)
- E-Ink Display - [Amazon](https://www.amazon.com/4-2inch-Module-Communicating-Resolution-Controller/dp/B074NR1SW2/ref=sr_1_8?crid=38LZB4T9AFOHX&keywords=e+ink+display&qid=1706592061&sprefix=e+i%2Caps%2C81&sr=8-8)
- Supabase Account - [Supabase](https://supabase.com/)

## Setting Up Supabase

1. **Create a Supabase account**

2. **Create a free Supabase database** 

3. **Note your API url and key** 


## Hardware Assembly

1. **Connect your esp32 to the e-ink display using the attached cables** 
   - The exact connections will depend on your model - use included pinout guide

2. **Plug your esp32 into your computer**

## Software Setup

1. **Install Arduino IDE** 


2. **Connect your esp32 to Arduino IDE** 
   - Configure your IDE with the right settings for your version of the microcontroller

2. **Install dependencies located on lines 3-9 of messageMain.ino** 

## Alter the Code

1. **Add your variables**
   - Add the appropriate values for lines 14-17 in messageMain.ino

2. **Upload this code to your esp32**

## How to Use

1. **Using the supabase table editor, alter the value of the first cell to any string** 

2. **After the message is received by the esp32, the e-ink display will update** 
   - This may take a moment due to the nature of the display and the code testing points of failure









