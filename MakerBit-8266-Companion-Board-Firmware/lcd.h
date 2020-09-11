



// install the LCD library from
// https://github.com/johnrickman/LiquidCrystal_I2C
// then #include it
#include <LiquidCrystal_I2C.h>


#define LCD_DEFAULT_ROWS 2
#define LCD_DEFAULT_COLS 16
#define LCD_DEFAULT_ADDRESS 0x27


// prototypes
LiquidCrystal_I2C * createLcdObject();

// defined in this module, made public here
extern LiquidCrystal_I2C * lcd;
extern int lcdCursorColumn;
extern int lcdNumberOfColumns;
extern int lcdCursorRow;
extern int lcdNumberOfRows;
extern int lcdAddress;
extern boolean lcdCreated;
