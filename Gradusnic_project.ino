
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"


Adafruit_AM2320 am2320 = Adafruit_AM2320();

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void setup() {
 Serial.begin(9600);
  while (!Serial) {
    delay(10); 
  }

  Serial.println("Adafruit AM2320 Basic Test");
  am2320.begin();
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
pinMode(LED_BUILTIN, OUTPUT);
 
}

void loop() {
   // turn the LED on (HIGH is the voltage level)
  display.clearDisplay();
  // text display tests
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(2,5);
  display.print("T:");
  display.println(am2320.readTemperature());
  display.display(); 
  delay(5000);
  
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(2,5);
  display.print("B:");
  display.println(am2320.readHumidity());
  display.display();
  delay(5000);
}
