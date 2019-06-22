// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_SUBROUTINE
#include "subroutine.h"
extern cell_t rStack_peek(uint8_t);
extern void printStr(char*);
extern void printHex(cell_t);
//const char subroutine_str[] = "subroutine";
void _subroutine(void) {
  extern cell_t* ip;
  extern cell_t* ip_begin;
  *pLastUserEntry->cfa = (cell_t) ip;
  *(pLastUserEntry->cfa+1) = (cell_t) ip_begin;
  printStr("\r\nrStack_peek(0) $"), printHex(rStack_peek(0));
  printStr("rStack_peek(1) $"), printHex(rStack_peek(1));
  _exit();
  printStr("\r\nafter _exit()\r\nrStack_peek(0) $"), printHex(rStack_peek(0));
  printStr("rStack_peek(1) $"), printHex(rStack_peek(1));
}

#endif
