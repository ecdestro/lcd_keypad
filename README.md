# lcd_keypad
Write digits to [16x2 LCD screen](https://www.sparkfun.com/products/255) with a [Sparkfun 12 button Qwiic Keypad](https://www.sparkfun.com/products/15290)
  
Depends on the [Wire](https://www.arduino.cc/en/reference/wire), [LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal), and [Sparkfun Qwiic Keypad Arduino](https://learn.sparkfun.com/tutorials/qwiic-keypad-hookup-guide/arduino-library) libraries
  
Connect Arduino digital pins to LCD pins in the following configuration:
  
D12 - LCD4  
D11 - LCD6  
D5 - LCD4  
D4 - LCD5  
D3 - LCD6  
D2 - LCD7  
  
Connect Arduino analog and 3.3v pins to the following Qwiic keypad pins:
  
3.3v - Power  
GND - Ground  
A4 - SDA  
A5 - SCL  
  
Pound key advances cursor to the beginning of the second row.  
Star key returns cursor to the beginning of the first row.
