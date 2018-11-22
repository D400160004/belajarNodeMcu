LM35 using LCD i2c
#define lmPin A0 //LM35 attach to
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); // set the LCD address to 0x3F for a 16 chars and 2 line display
float tem = 0;
long lmVal = 0;
void setup()
{
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight 
}
void loop()
{
  lmVal = analogRead(lmPin);//read the value of A0
  tem = (lmVal * 0.0048828125 * 100);//5/1024=0.0048828125;1000/10=100
  lcd.setCursor(5,0);//place the cursor on 5 column,0 row
  lcd.print("LM35");//print"LM35"
  lcd.setCursor(0,1);//place the cursor on 0 column,1 row
  lcd.print("Tem= ");//print"Tem= "
  lcd.setCursor(5,1);//place the cursor on 5 column,1 row
  lcd.print(tem);//print tem
  lcd.print(char(223));//print the unit" ℃ "
  lcd.print("C");
  delay(200);//delay 200ms
}
