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
"Id","Designator","Footprint","Quantity","Designation","Supplier_and_ref"
1,"U1","ESP32-WROOM-32",1,"ESP32-WROOM-32 SMD Module","Drot RO: https://www.drot.ro/platforma-arduino/2062-modul-esp-wroom-32-wifi-wlan-si-bluetooth.html"
2,"R2,R1","R_0805_2012Metric",2,"10k","Optimus Digital: https://www.optimusdigital.ro/ro/componente-electronice-rezistoare/638-set-de-rezistoare-smd-0805.html"
3,"C2","CP_Elec_5x5.4",1,"10uF","TME RO: https://www.tme.eu/ro/details/sc1h106m6l005vr/condensatoare-electrolitice-smd/samwha/"
4,"U3","SOT-223-3_TabPin2",1,"AMS1117-3.3","Sigmanortec: https://sigmanortec.ro/Modul-coborator-tensiune-AMS1117-3-3V-p134573098"
5,"SW1","RotaryEncoder_Alps_EC11E",1,"RotaryEncoder_Switch","Sigmanortec: https://sigmanortec.ro/Encoder-rotativ-cu-click-20mm-EC11-p128736611"
6,"P1","USB_C_Receptacle_HRO_TYPE-C-31-M-12",1,"USB_C_Plug_USB2.0","eMAG RO: https://www.emag.ro/conector-usb-tip-c-montare-pcb-smd-16-pin-tht-k684-um/pd/DNLXNRMBM/"
7,"C3,C1","C_0805_2012Metric",2,"100nF","TME RO: https://www.tme.eu/ro/details/cl21b104kacnnnc/condensatoare-mlcc-smd/samsung/"
8,"U2","CR2013-MI2120",1,"ILI9341_TFT","Optimus Digital: https://www.optimusdigital.ro/ro/optoelectronice-lcd-uri/3531-modul-lcd-de-24-cu-spi-i-controller-ili9341-240x320-px.html"
