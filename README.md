## Intro

This Fork from MichaelEFlip, forked from Bjoerns-TB, forked from DeuxVis, supports OLED display on the I²C interface on GPIO22 and GPI21.

This is a simple sketch demonstrating the capability of the [TTGO T-Beam](https://www.aliexpress.com/store/product/TTGO-T-Beam-ESP32-433-868-915Mhz-WiFi-wireless-Bluetooth-Module-ESP-32-GPS-NEO-6M/2090076_32875743018.html) as a [TTN Mapper](https://ttnmapper.org/) Node on [The Things Network](https://www.thethingsnetwork.org/) LoraWAN.

Derived from [sbiermann/Lora-TTNMapper-ESP32](https://github.com/sbiermann/Lora-TTNMapper-ESP32) and with some information/inspiration from [cyberman54/ESP32-Paxcounter](https://github.com/cyberman54/ESP32-Paxcounter) and [Edzelf/LoRa](https://github.com/Edzelf/LoRa).

## New features

* GPS scan relaxed and done more "nonblocking"
* more information shown on status screen
* animated GPS-fix-screen with satellite gfx
* selectable data rate and power (button short press)
* selectable transmit interval (button longer press)
* selectable ADR-Mode (button even longer press)
* selectable send-port to enable "on device" switch to experimental mapping (button even loooonger press)
* support for newer HW-revisions (V08 / V0.8, V09 / V0.9, V10 / V1.0, V1.1 with soft-power-button and power management chip) (short press = power-on / dimm-mode; long press = power-off)

![Start screen](images/sc_02.jpg)![GPS fix screen](images/sc_01.jpg)![Status screen](images/sc_03.jpg) 

## Software dependencies

[PlatformIO](https://platformio.org/)

[TinyGPS++](http://arduiniana.org/libraries/tinygpsplus/)

[MCCI Arduino LoRaWAN Library](https://github.com/mcci-catena/arduino-lorawan)

[AXP202X_Library](https://github.com/lewisxhe/AXP202X_Library)

[Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

## Instructions

Program the T-Beam using VS-Code or Atom with [PlatformIO](https://github.com/espressif/arduino-esp32) installed.

On The Things Network side, the settings needed are available [here](https://www.thethingsnetwork.org/docs/applications/ttnmapper/).

Configure the Payload decoder with:
```javascript
function Decoder(bytes, port) {
    var decoded = {};

    decoded.latitude = ((bytes[0]<<16)>>>0) + ((bytes[1]<<8)>>>0) + bytes[2];
    decoded.latitude = (decoded.latitude / 16777215.0 * 180) - 90;
  
    decoded.longitude = ((bytes[3]<<16)>>>0) + ((bytes[4]<<8)>>>0) + bytes[5];
    decoded.longitude = (decoded.longitude / 16777215.0 * 360) - 180;
  
    var altValue = ((bytes[6]<<8)>>>0) + bytes[7];
    var sign = bytes[6] & (1 << 7);
    if(sign)
    {
        decoded.altitude = 0xFFFF0000 | altValue;
    }
    else
    {
        decoded.altitude = altValue;
    }
  
    decoded.hdop = bytes[8] / 10.0;

    return decoded;
}
```
