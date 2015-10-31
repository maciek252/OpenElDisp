#include "parser.h"

  char *o;
  char inData[100];


void EleresParser::ReadSerialAndParseEleres(){
 
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

  
}
