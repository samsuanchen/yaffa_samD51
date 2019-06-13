// Sun Jul  2 20:55:24 UTC 2017
// 4735-b0a-07-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_STRINGS
#include "strings.h"

// const char sp_str[] = " ";
//const char hexidecimal_str[] = "$";
//const char octal_str[] = "0";
//const char binary_str[] = "%";

/******************************************************************************/
/** String and Serial Functions                                              **/
/******************************************************************************/
#define OUTLMT 80
uint8_t outLen;
char strBuf[256];
void displayValue(cell_t w) {
  itoa(w, strBuf, base);
  outLen += Serial.print(strBuf);
  outLen += Serial.print(sp_str);
}

#endif
