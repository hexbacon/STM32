/* 
    Liquid Crystal
*/

#ifndef LiquidCrystal_h
#define LiquidCrystal_h

// Instructions
#define LCD_CLEAR_DISPLAY 0x01
#define LCD_RETURN_HOME 0x02
#define LCD_ENTRY_MODE_SET 0x04
#define LCD_DISPLAY_CONTROL 0x08
#define LCD_CURSOR_SHIFT 0x10
#define LCD_FUNCTION_SET 0x20
#define LCD_SET_CGRAM_ADDR 0x40
#define LCD_SET_DDRAM_ADDR 0x80

// Flags for entry mode
#define LCD_ENTRY_INCREMENT_DECREMENT  0X00
#define LCD_ENTY_INCREMENT_INCREMENT  0X01
#define LCD_ENTRY_SHIFT_RIGHT 0x00
#define LCD_ENTRY_SHIFT_LEFT 0x02

// Flags for Display control
#define LCD_CURSOR_BLINK_OFF 0x00
#define LCD_CURSOR_BLINK_ON 0x01
#define LCD_CURSOR_DISPLAY_OFF 0x00
#define LCD_CURSOR_DISPLAY_ON 0x02
#define LCD_DIPLAY_OFF 0x00
#define LCD_DIPLAY_ON 0x04

// Flags for Cursor or Display Shift S/C S/R
#define LCD_SHIFT_RIGHT 0x04
#define LCD_SHIFT_LEFT 0x00
#define LCD_SHIFT_DISPLAY 0x08
#define LCD_MOVE_CUROSOR 0x00

// Flags for Function Set
#define LCD_SET_FONT_5_BY_10 0x04
#define LCD_SET_FONT_5_BY_8 0x00
#define LCD_SET_2_LINE_MODE 0x08
#define LCD_SET_1_LINE_MODE 0x00
#define LCD_SET_8_BIT_MODE 0x10
#define LCD_SET_4_BIT_MODE 0x00

// initializers
void LiquidCrystal(GPIO_TypeDef *gpioport, uint16_t rs, uint16_t rw, uint16_t enable,
  uint16_t d0, uint16_t d1, uint16_t d2, uint16_t d3);

#endif