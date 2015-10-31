#include "display.h"

int a = 0;
int i = 0;
extern int screen;
float pos_lat, pos_long;



  byte index = 0;

  

void ElDispDisplay::SetupDisplay(){
   lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
 
}
void ElDispDisplay::updateDisplay(){
  
    lcd.setCursor(0, 0);
  lcd.print("Hello, World!");

  // Write the counter on the second line...
  lcd.setCursor(0, 1);
  lcd.print(counter, DEC);
  lcd.write(' ');
  lcd.write(0);  // write the smiley

  lcd.setCursor(3, 1);
  lcd.print(screen, DEC);

  
  counter ++;
  
          char buffo[60];

//        gotoXY(3,1);
   sprintf(buffo, "c%iU%iI%iv%i", c, U, I, v);
  lcd.setCursor(2, 3);
  lcd.print(buffo);

}
