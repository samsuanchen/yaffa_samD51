// Sun Jun 11 23:00:12 UTC 2017
// 4735-a0g

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

// #ifdef EXT_KERN_WARM // no internal so this is unnecessary
#include "warm.h"
const char warm_str[] = "warm";
void _warm(void) {
  dStack_clear();                        // Clear the data stack.
  rStack_clear();                        // Clear the return stack.
  cpToIn = cpSourceEnd+1;
  pLastUserEntry = 0;
  pHere = forthSpace;
  state = FALSE;
  _quit();
//NVIC_SystemReset();      // processor software reset 
}

// #endif
