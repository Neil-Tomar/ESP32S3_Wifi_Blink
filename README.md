<p align="center">
    <img src="https://neilmaverick.com/logo.svg" align="center" width="30%">
</p>
<p align="center">
  <h1 align="center">ESP32S3_WIFI_BLINK</h1>
</p>
<p align="center">
  <em><code>❯ Web-controlled LED with ESP32-S3</code></em>
</p>
<p align="center">
  <img src="https://img.shields.io/github/license/Neil-Tomar/ESP32S3_Wifi_Blink?style=default&logo=opensourceinitiative&logoColor=white&color=0080ff" alt="license">
  <img src="https://img.shields.io/github/last-commit/Neil-Tomar/ESP32S3_Wifi_Blink?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
  <img src="https://img.shields.io/github/languages/top/Neil-Tomar/ESP32S3_Wifi_Blink?style=default&color=0080ff" alt="repo-top-language">
</p>

---

# ESP32S3_Wifi_Blink

A simple ESP32-S3 project that connects to Wi-Fi and serves a minimal webpage to control the onboard LED using buttons rendered in HTML/CSS/JS.

---

## 📋 Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Circuit Diagram](#circuit-diagram)
- [Web Interface Preview](#web-interface-preview)
- [Real Project Setup](#real-project-setup)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Author](#author)

---

## About

This ESP32-S3 project creates a Wi-Fi access point and serves a styled HTML page with LED control buttons. The LED is toggled based on the buttons using HTTP endpoints: `/on` and `/off`.

The page is mobile-friendly, visually appealing, and sends HTTP requests to toggle the onboard LED state.

---

## Features

- Connects to Wi-Fi
- Serves an HTML page with buttons to toggle the LED
- Handles `/on` and `/off` HTTP requests
- Displays LED control UI with styled animations
- Prints logs over Serial

---

## Requirements

- **Hardware**: ESP32-S3 dev board (e.g. Seeed Studio XIAO ESP32S3)
- **Software**:
  - [VS Code](https://code.visualstudio.com/)
  - [PlatformIO extension](https://platformio.org/install/ide?install=vscode)

---

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Neil-Tomar/ESP32S3_Wifi_Blink.git
   cd ESP32S3_Wifi_Blink
   ```

2. **Open the folder in VS Code (PlatformIO)**

3. **Update Wi-Fi Credentials**
   In `src/main.cpp`, update:
   ```cpp
   const char* ssid     = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```

4. **Build and Upload the code**
   - Use the PlatformIO upload button (→)

5. **Open the Serial Monitor**
   - Use the PlatformIO monitor button (🔌)
   - Baud rate: `115200`

---

## Usage

- Once connected to Wi-Fi, the Serial Monitor shows the ESP32's IP address.
- Visit `http://<ESP32_IP>` in a browser on the same network.
- The webpage will load with a button interface.
- Clicking the button sends `/on` or `/off` request to the ESP32.
- The LED turns ON or OFF based on the button click.

---

## 🧩 Circuit Diagram

![Circuit Diagram](images/circuit_diagram.jpg)

Example (if LED is connected externally):
- GPIO 2 → 220Ω resistor → LED anode
- LED cathode → GND

For onboard LED, GPIO 2 is typically already wired.

---

## 🖥️ Web Interface Preview

![Web App](images/web_app.jpg)

This is what the control UI looks like when accessed via browser.

---

## 🛠️ Real Project Setup

![Real Setup](images/project_photo.jpg)

This is an actual photo of the working setup.

---

## ⚙️ How It Works

- The ESP32 connects to your Wi-Fi using credentials.
- It starts a web server on port 80.
- The browser interface sends HTTP GET requests when buttons are clicked.
  - `GET /on` → Turns LED ON
  - `GET /off` → Turns LED OFF
- The ESP32 responds with an HTML page styled with embedded CSS and animated button graphics.

Everything (HTML, CSS, JS) is included directly inside the C++ code as a raw string.

---

## Project Structure

```
ESP32S3_Wifi_Blink/
├── src/
│   └── main.cpp        # Main source code (serves webpage + handles LED)
├── images/             # Add circuit_diagram.jpg, web_app.jpg, project_photo.jpg
├── platformio.ini      # PlatformIO config
└── README.md           # This file
```

---

## 👨‍💻 Author

Made by **Neil Tomar**.

This is a personal Wi-Fi-controlled LED web interface project using ESP32-S3. Everything in this repo is made from scratch.

