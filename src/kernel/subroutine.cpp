// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
// #include "Error_Codes.h"

#ifdef EXT_KERN_SUBROUTINE
#include "subroutine.h"
const char subroutine_str[] = "subroutine";
void _subroutine(void) {
  extern userEntry_t* pDefining;
//Serial.print("\r\n_subroutine() pDefining: 0x"),Serial.print((cell_t)pDefining->name,16);
//Serial.print("\r\npLastUserEntry->cfa 0x"),Serial.print((cell_t)pLastUserEntry->cfa,16);
//Serial.print("\r\npNewDoes 0x"),Serial.print((cell_t) pNewDoes,16);
  *pLastUserEntry->cfa = (cell_t) pNewDoes;
  extern cell_t* pHere;
  *(pHere-2) = (cell_t) pDefining->name;
  _exit(); /* samsuanchen@gmail.com 20190521
  *pDoes = (cell_t)*ip++; */
}

#endif
