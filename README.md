# Wahoo RGT - Bluetooth Steering Controller (Works with Apple, Windows, and Android)

This project is to create steering buttons for Wahoo RGT using an ESP32 and it is suitable for PC, Android, and Apple (iPad & TV) via Bluetooth. Testing has mostly been done on **Apple** since for PC version I recommend using [RGT Arduino USB Steering Solution](https://github.com/JC-Concepts/RGT-Arduino_USB_Steer). The concept is to make the ESP32 act as a Bluetooth keyboard and send the characters 'a' (left) and 'd' (right) commands.

____

### Apple Device Users  
At the date of release (3/2/2023) Wahoo RGT (for Apple devices) has some odd latency in their code (which RGT did confirm with me). It prevents "trigger happy" button presses. That means if you press too fast, your avatar will not respond and sometimes locks up the steering for a brief moment. In order to click and change multiple lanes, you will need to click, wait for your avatar to commit (start moving) to lane change then click again. Therefore feeling a delay in steering opportunity. 

To overcome this latency issue, I've masked latency by having steering work as a **Press & Hold** instead of individual discrete button presses. This eliminates the guessing work of when you can click again without RGT missing a click or freezing up steering, and therefore saving you seconds (or a fraction of a second). 

**Single Lane Change: Press once to steer**

**Multi-Lane Change: Press & Hold to steer**

To enable **Press & Hold** 
You will need comment out (by adding **//** in front) this line in the main code:
> const unsigned long TIME_INTERVAL = 100;

And uncomment this line in the main code: 
> const unsigned long TIME_INTERVAL = 550;

____

### Windows & Android Device Users  
I would not recommend using the press & hold feature since you can get a much faster steering response using standard method. To make sure you **do not have Press & Hold** enabled, make sure these two changes are in the code.

You will need comment out (by adding **//** in front) this line in the main code:
> const unsigned long TIME_INTERVAL = 550;

And uncomment this line in the main code: 
> const unsigned long TIME_INTERVAL = 100;


## Software Installation Notes:
* This was flashed using Arduino IDE 1.8.19 if you are using Arduino 2.0.x there might be some additional settings you will need to modify in the IDE preferences. 
* Follow the [Espressif documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) on using ESP32 in Arduino IDE. This was built using **Version 1.0.4**
* Will require [CP210x USB driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) for your computer to recognize the ESP32 dev board 
* Will require the [ESP32 BLE Keyboard Library](https://github.com/T-vK/ESP32-BLE-Keyboard). This was built using the [**Unofficial Version 0.3.3**](https://github.com/T-vK/ESP32-BLE-Keyboard/issues/168#issuecomment-1172483419) 
* Will require [NimBLE-Arduino Library](https://github.com/h2zero/NimBLE-Arduino). This was built with **Version 1.4.1**

If you are new to working with ESP32 in Arduino. When compiling & building, the upload might fail because it could not connect to the ESP32. To overcome this, during the firmware upload and it says "connecting" press and hold the **boot** button beside the USB connector. 

<img src="https://user-images.githubusercontent.com/126370788/222343254-f07b5201-430b-4a2b-aacc-c6e9df203103.png" alt="ESP32 Boot Button" title="ESP32 Boot Button">


## Bill of Materials:
* ESP32 Development Board
* Switch qty: 2 (any contact normally open will work, I've used a 5mm x 5mm tactile switch (not waterproof))
* Some wires
* USB A to micro USB cable (if your ESP32 did not come with it for programming and/or power source)
* Power source through Micro USB (phone charger, USB power bank, etc.)



## Schematic:

 
<img src="https://user-images.githubusercontent.com/126370788/222050207-bb4d1ff8-e4bf-4519-8de7-322727e3fb1c.png" alt="Schematic" title="Schematic">


## Other Wahoo RGT Keyboard Command:
* **p**: Push to Talk
* **t**: Opens the Chat box



# Like this Project? 
You can buy me a gel, coffee, or inner tube


[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=RE2GQDK8CD2WW)


## Hardware Installation Notes:
- Sample picture: tactile switch hot glued to a scrap plastic from food packaging
- Switch assembly is held onto the hood using Aelastic 
- Waterproofing the switch, you can use a small plastic bag or food wrap to seal it
- Cheap alternative to waterproof the ESP32 is to put it into a kids food container (easily found at the dollar store)


## Example pictures:

<img src="https://user-images.githubusercontent.com/126370788/221392142-773b0838-bffe-4697-9338-dc0e4f6b5d25.png" alt="Mounted on Hood" title="Mounted on Hood" height="500" width="500" >
<img src="https://user-images.githubusercontent.com/126370788/221392171-1d6f0b53-b0fe-4620-9c53-d61f71be0e96.png" alt="Splash proof Package" title="Splash Proof Container"height="473" width="800" >

