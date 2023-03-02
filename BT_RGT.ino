/*
Bluetooth Steering Controls for Wahoo RGT

Works with Apple iPad, Apple TV, Android, & PC

This uses ESP32 to act as a Bluetooth HID Keyboard and sends commands to Wahoo RGT to control the steering of the avatar
  - Pressing the Left Switch (Pin 18) will send the 'a' keyboard value, 
  - Pressing Right Switch (Pin 19) will send the 'd' keyboard value 

BOM: 
  - ESP32 x 1 
  - Momentary Tactile switches (normally open) x 2

Pairing: 
Perform a Bluetooth Search and look for "RGT_Steer" to pair
 
 */
 


#define USE_NIMBLE
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("RGT_Steer","JC Concept",100);


const int buttonLeftPin = 18;  
const int buttonRightPin = 19;  
const int ONBOARD_LED = 2;  

//const unsigned long TIME_INTERVAL = 90;  //Ideal delay to catch any debounce from the switch, *** Comment this line on Apple devices, keep this for all other devices
const unsigned long TIME_INTERVAL = 550;  //Added delay for RGT on Apple devices (Press and Hold), *** Uncomment this line for Apple Devices, leave it commented out for all other devices  
unsigned long previousMillis;


void setup() {
  pinMode(buttonLeftPin, INPUT_PULLUP);
  pinMode(buttonRightPin, INPUT_PULLUP);
  
  pinMode(ONBOARD_LED,OUTPUT);
  digitalWrite(ONBOARD_LED,LOW);
  
  bleKeyboard.setDelay(10);
  bleKeyboard.begin();
  bleKeyboard.releaseAll();
  
  previousMillis = millis();
}

void loop() {
  if(bleKeyboard.isConnected()) {

    digitalWrite(ONBOARD_LED,HIGH);

    if (millis() - previousMillis >= TIME_INTERVAL){
          if(digitalRead(buttonLeftPin)!= HIGH){
          bleKeyboard.write('a');
        }
          else if (digitalRead(buttonRightPin)!= HIGH){
            bleKeyboard.write('d');
        }
        bleKeyboard.releaseAll();
        previousMillis = millis();
    }

    //delay(50);


  }
  else{
    delay(500);
    digitalWrite(ONBOARD_LED,HIGH);
    delay(100);
    digitalWrite(ONBOARD_LED,LOW);
  }

}
