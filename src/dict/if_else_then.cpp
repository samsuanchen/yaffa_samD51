// Tue Jun 27 21:19:58 UTC 2017
// 4735-a0s-00-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

// #ifdef EXT_IF_ELSE_THEN
#include "if_else_then.h"
/******************************************************************************/
/** if ... then                                                              **/
/** if ... else ... then                                                     **/
/******************************************************************************/
//const char if_str[] = "if";
// Compilation: (C: -- if-sys)
// Run-Time: ( flag -- )
void _if(void) {
  *pHere++ = ZJUMP_IDX;
  dStack_push(IF_SYS);
  dStack_push((size_t)pHere); // store the address of else or then 
  *pHere++ = 0;
}

//const char else_str[] = "else";
// Interpretation: undefined
// Compilation: (C: if-sys -- else-sys )
// Run-Time: ( -- )
void _else(void) {
  cell_t* jump_addr = (cell_t*) dStack_pop();
  if ( dStack_pop() != IF_SYS) {
    _throw(-22); return;
  }
  *pHere++ = JUMP_IDX;
  dStack_push(ELSE_SYS);
  dStack_push((size_t) pHere);
  *pHere++ = 0;
  * jump_addr = (cell_t) pHere;
}

//const char then_str[] = "then";
// Interpretation: undefined
// Compilation: (C: if-sys | else-sys -- )
// Run-Time: ( -- )
void _then(void) {
  cell_t* jump_addr = (cell_t*) dStack_pop();
  cell_t flag = dStack_pop();
  if ( (flag != IF_SYS) && (flag != ELSE_SYS) ) {
    _throw(-22); return;
  }
  * jump_addr = (cell_t) pHere;
}

// #endif

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
