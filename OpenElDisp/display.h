#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "PCD8544.h"

extern int U, I, c, v, P;

// A custom glyph (a smiley)...
static const byte glyph[] = { B00010000, B00110100, B00110000, B00110100, B00010000 };


static PCD8544 lcd(13,11,10,7,8);
  static int counter = 0;


class ElDispDisplay
{
  
  public:
  void SetupDisplay();
  void updateDisplay(void);
  
};

#endif
