# ESP32 Spotify Remote Controller

A custom ESP32-based hardware controller featuring an ILI9341 TFT display and a rotary encoder to wirelessly control Spotify playback over Wi-Fi.

![Project Image](pcb_image.png)

## Quick start
1. Clone this repository and open the file in the `firmware` folder using Arduino IDE.
2. Install the required libraries (`TFT_eSPI`, `ESP32Encoder`, `SpotifyEsp32`).
3. Update your Wi-Fi credentials (`ssid`, `password`) and Spotify API credentials (`clientId`, `clientSecret`) in the code.
4. Upload the code to your ESP32 board and connect power via USB-C.

![Project Image](pcb.png)

## Features
* **Spotify Integration:** Uses `SpotifyEsp32` to control playback (Next/Previous track, Play/Pause).
* **Rotary Encoder Controls:** Turn the knob (GPIO 25, 26) to skip tracks and press the button (GPIO 27) for play/pause.
* **TFT Display:** ILI9341 320x240 screen driven by `TFT_eSPI` for status and track updates.
* **Hardware:** Custom PCB with an ESP32-WROOM-32 module, USB-C interface, and onboard AMS1117 3.3V power regulation.

## How it works
The project runs on an ESP32-WROOM-32 microcontroller. Upon boot, it connects to Wi-Fi and initializes the ILI9341 display. The `ESP32Encoder` library handles the rotary encoder inputs to trigger Spotify API calls (`spotify.nextTrack()`, `spotify.previousTrack()`) over a secure Wi-Fi client (`WiFiClientSecure`).

![Project Image](schematic.png)

## 💰 Bill of Materials (BOM)
"Id";"Designator";"Footprint";"Quantity";"Designation";"Supplier and ref";
1;"U1";"ESP32-WROOM-32";1;"ESP32-WROOM-32";"Sigmanortec (ESP32-WROOM-32 DevKit1): https://sigmanortec.ro/en/esp32-development-board-esp-wroom-32-wifi-and-bluetooth-ble-devkit1";
2;"R2,R1";"R_0805_2012Metric";2;"10k";"Electronic Mag (Set Rezistoare SMD 0805 10k): https://electronic-mag.ro/p/65385-set-rezistoare-smd-0805-5-10o-1mo-0o-nrval-121";
3;"C2";"CP_Elec_5x5.4";1;"10uF";"Ardushop (Condensator SMD 10uF): https://ardushop.ro";
4;"U3";"SOT-223-3_TabPin2";1;"AMS1117-3.3";"Sigmanortec (AMS1117 3.3V Step-down): https://sigmanortec.ro/en/ams1117-33v-step-down-module";
5;"SW1";"RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm_CircularMountingHoles";1;"RotaryEncoder_Switch";"Sigmanortec (EC11 Rotary Encoder 20mm): https://sigmanortec.ro/en/rotary-encoder-with-click-20mm-ec11";
6;"P1";"USB_C_Receptacle_HRO_TYPE-C-31-M-12";1;"USB_C_Plug_USB2.0";"Mouser RO (GCT USB4731-GF-A Type-C 16-pin): https://ro.mouser.com/ProductDetail/GCT/USB4731-GF-A";
7;"C3,C1";"C_0805_2012Metric";2;"100nF";"Lampatronics (SMD Ceramic Capacitor 0805 100nF): https://lampatronics.com/product/smd-multilayer-ceramic-capacitor-0805-2012-104-100nf-50v-1pcs-2";
8;"U2";"CR2013-MI2120";1;"CR2013-MI2120";"Drot RO (Ecran Tactil 2.4 SPI TFT ILI9341): https://www.drot.ro/platforma-arduino/909-ecran-tactil-2-4-240x320-spi-tft-ili9341.html";

