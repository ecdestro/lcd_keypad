#include <Wire.h>
#include "SparkFun_Qwiic_Keypad_Arduino_Library.h"
#include <LiquidCrystal.h>

KEYPAD keypad1;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup(void)
{
  lcd.begin(16,2);
  Serial.begin(9600);

  if (keypad1.begin() == false)
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
    if (button == '#') lcd.setCursor(0,1);
    else if (button == '*') lcd.setCursor(0,0);
    else lcd.print(button);
  }
  delay(25);
}
