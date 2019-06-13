// Wed Jun 21 20:55:05 UTC 2017
// 4735-a0p-03-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_XTTONAME
#include "xttoname.h"
/******************************************************************************/
/** Functions for decompiling words                                          **/
/**   Used by _see and _toName                                               **/
/******************************************************************************/
char* to_name(cell_t xt) {
  char* name = 0;
  if (xt <= nFlashEntry) name = (char*) flashDict[xt-1].name;
  else {
  	cell_t* p = (cell_t*) xt - 1;
  	int n=9; while( n-- ) if(*(--p)==xt ) break;
  	if(*p == xt) name = (char*) p + 5;
  }
  return name;
}
extern uint8_t outLen;
char* dot_name(cell_t xt) {
  char* name = to_name(xt);
  if(name) outLen += Serial.print(name);
  return name;
}
//const char dot_name_str[] = ".name";
void _dot_name(){
	dot_name( dStack_pop() );
}
#endif

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**  Version 0.7.0                                                           **/
/**                                                                          **/
/**  File: YAFFA.ino                                                         **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/******************************************************************************/
