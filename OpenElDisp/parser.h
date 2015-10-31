#ifndef _PARSER_H_
#define _PARSER_H_

#include "PCD8544.h" // for includes

extern int U, I, c, v, P;

class EleresParser
{
 
 public: 
  void ReadSerialAndParseEleres();
  
};

#endif
