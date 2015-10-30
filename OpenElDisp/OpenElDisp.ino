
#include "PCD8544.h"
#include "OneButton.h"

int a = 0;
int i = 0;
float pos_lat, pos_long;

  char inData[100];
  byte index = 0;
  int P = 1;
  int I = 0;
  int U = 0;
  int v = 0;
  
  char *o;
  int c = 0;

// A custom glyph (a smiley)...
static const byte glyph[] = { B00010000, B00110100, B00110000, B00110100, B00010000 };

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
static PCD8544 lcd(13,11,10,7,8);


void setup() {
    pinMode(9, OUTPUT);
  // Setup the Serial port. see http://arduino.cc/en/Serial/IfSerial
//  Serial.begin(9600);
Serial.begin(57600);
      digitalWrite(9, LOW);
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
  
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

  // Just to show the program is alive...
  static int counter = 0;

  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");

  // Write the counter on the second line...
  lcd.setCursor(0, 1);
  lcd.print(counter, DEC);
  lcd.write(' ');
  lcd.write(0);  // write the smiley

  // Use a potentiometer to set the LCD contrast...
  // short level = map(analogRead(A0), 0, 1023, 0, 127);
  // lcd.setContrast(level);



//  char positions[20];
#if 1
  if(inData[0] == 'P' && 
  inData[1] == 'o' && inData[2] == 's'){
    P = 9;   
  }else{
//  http://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
// Read each command pair 
// http://forum.arduino.cc/index.php?topic=41215.0
//   if(inData[0] == 't')
//     P = 10;

      char* command = strtok(inData, " ");
while (command != 0)
{
      o = command;
  
    // Split the command in two values
    char* separator = strchr(command, '=');

    if (separator != 0)
    {
        // Actually split the string in 2: replace ':' with 0
        *separator = 0;
 //       o = command;
        

          
//        int servoId = atoi(command);
        ++separator;
        int position = atoi(separator);

      if(command[0] == 'c')
          c = position;
        else if(command[0] == 'v')
          v = position;
        else if(command[0] == 'I')
          I = position;
        else if(command[0] == 'U')
          U = position;
                else if(command[0] == 't')
          P = 10;  
        else if(command[0] == 'R'
                && command[1] == 'S')
          P = 12;


        // Do something with servoId and position
        
    }
    
    // Find the next command in input string
    command = strtok(NULL, " ");
}
      
//      while(spacja = strchr(p, " ") != 0){
//      }
//      o = strtok(p, " ");
    // while ((o = strtok_r(p, " ", &p)) != NULL){ // delimiter is the semicolon                     
//       if( strchr
//        P=2;
//        if(o[0] == 'P' && o[1] == '='){
  //          P = atoi(o+2);
  //      }
//     }
    
  }
#endif    

  i++;

  if(i > 10){
    i = 0;
//        LcdClear();
        char buffo[60];

//        gotoXY(3,1);
   sprintf(buffo, "c%iU%iI%iv%i", c, U, I, v);
  lcd.setCursor(2, 3);
  lcd.print(buffo);

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
  }  


//  delay(200);
  counter++;
}

// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
void click1() {
  Serial.println("Button 1 click.");
  U = U + 1;
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
    U = U + 2;
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");
    U = U + 5;
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
  U = U -1;
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


