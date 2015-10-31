
#include "display.h"
#include "PCD8544.h"
#include "OneButton.h"
#include "parser.h"
  int I = 0; 
  int U = 0;
  int v = 0;
  int P = 0;
  int c = 0;




static ElDispDisplay disp;
static EleresParser parser;


int screen = 0;

// Setup a new OneButton on pin A1.  
OneButton button1(3, true);
// Setup a new OneButton on pin A2.  
OneButton button2(6, true);


/*
 PCD8544(unsigned char sclk  = 3,    clock       (display pin 2) 
                unsigned char sdin  = 4,    data-in     (display pin 3) 
                unsigned char dc    = 5,    data select (display pin 4) 
                unsigned char reset = 6,    reset       (display pin 8) 
                unsigned char sce   = 7);   enable      (display pin 5) 
*/



void setup() {
    pinMode(9, OUTPUT);
  // Setup the Serial port. see http://arduino.cc/en/Serial/IfSerial
//  Serial.begin(9600);
Serial.begin(57600);
      digitalWrite(9, LOW);
      disp.SetupDisplay();
  // PCD8544-compatible displays may have a different resolution...
    
  // link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);
  
  
  // link the button 2 functions.
  button2.attachClick(click2);
  button2.attachDoubleClick(doubleclick2);
  button2.attachLongPressStart(longPressStart2);
  button2.attachLongPressStop(longPressStop2);
  button2.attachDuringLongPress(longPress2);
}


void loop() {
    button1.tick();
  button2.tick();

  parser.ReadSerialAndParseEleres();
  disp.updateDisplay();

  // Just to show the program is alive...


  // Write a piece of text on the first line...
  

  // Use a potentiometer to set the LCD contrast...
  // short level = map(analogRead(A0), 0, 1023, 0, 127);
  // lcd.setContrast(level);




//        LcdClear();

//          dtostrf(U, 5, 1, buffo);
  //        buffo[5] = 0;
//    sprintf(buffo, "c%iU%iI%iv%i", c, U, I, v);
//    LcdString(buffo);
//LcdString("rrr");
//drawLine();
//gotoXY(3,1);
//LcdCharacter('r');

/*    
    gotoXY(2,1);

//    LcdString(inData);      
//    LcdString(o);      
//      String s = String(pos_long);
    gotoXY(1,5);
    pos_long = 2.34;
    char buf[20];
    int j = 146;
    //http://forum.arduino.cc/index.php?topic=44262.0
    //http://stackoverflow.com/questions/27651012/arduino-sprintf-float-not-formatting
    
    //sprintf(buf, "miau%ibobo", j);
    //sprintf(buf, "miau%fbobo", j);
    dtostrf(P, 5, 2, buf);
    LcdString(buf);      */


//  delay(200);
  counter++;
}

// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
void click1() {
  Serial.println("Button 1 click.");

} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");

} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");

} // longPressStart1


// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
  Serial.println("Button 1 longPress...");
} // longPress1


// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
} // longPressStop1


// ... and the same for button 2:

void click2() {
  Serial.println("Button 2 click.");

  screen += 1;
  if(screen > 4)
    screen = 0;
} // click2


void doubleclick2() {
  Serial.println("Button 2 doubleclick.");
} // doubleclick2


void longPressStart2() {
  Serial.println("Button 2 longPress start");
} // longPressStart2


void longPress2() {
  Serial.println("Button 2 longPress...");
} // longPress2

void longPressStop2() {
  Serial.println("Button 2 longPress stop");
} // longPressStop2


