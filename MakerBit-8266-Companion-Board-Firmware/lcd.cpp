
// need Arduino.h for certain type definitions
#include "Arduino.h"

#include "lcd.h"

int lcdCursorColumn = 0;
int lcdNumberOfColumns = LCD_DEFAULT_COLS;
int lcdCursorRow = 0;
int lcdNumberOfRows = LCD_DEFAULT_ROWS;
int lcdAddress = LCD_DEFAULT_ADDRESS;
boolean lcdCreated = false;
LiquidCrystal_I2C * lcd;


LiquidCrystal_I2C * createLcdObject() {
  lcd = new LiquidCrystal_I2C(lcdAddress, lcdNumberOfColumns, lcdNumberOfRows);
  return lcd;
}
