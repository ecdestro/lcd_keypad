#include <Wire.h>                                   // Needed to communicate with I2C interface
#include "SparkFun_Qwiic_Keypad_Arduino_Library.h"  // Local library specific to Qwiic-brand keypad interface from https://www.sparkfun.com/products/15290
#include <LiquidCrystal.h>                          // Library containing code for talking to LCD interfaces

KEYPAD keypad1;                                             // Instantiate the Qwiic keypad as a variable, keypad1
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                  // Set up reset pin, enable pin, and four data pins. We'll be using 4-bit data on the LCD

void setup(void)
{
  lcd.begin(16,2);
  Serial.begin(9600);

  if (keypad1.begin() == false)   // Detect if the keypad is not connected
  {
    lcd.print("No Keypad");
    while (1);
  }
}

void loop(void)
{
  keypad1.updateFIFO(); 
  char button = keypad1.getButton();

  if (button == -1)
  {
    delay(1000);
  }

  else if (button != 0)
  {
    if (button == '#') lcd.setCursor(0,1);        // Set the cursor to the beginning of line 2 if the POUND button is pressed
    else if (button == '*') lcd.setCursor(0,0);   // Set the cursor to the beginning of line 1 if the STAR button is pressed
    else lcd.print(button);
  }
  delay(25);                                      // Delay 25ms for serial polling
}
