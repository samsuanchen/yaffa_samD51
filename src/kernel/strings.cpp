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
uint8_t outLen;
char strBuf[256];
void displayValue(cell_t w, uint8_t base, uint8_t n, char c) {
  itoa(w, strBuf, base);
  uint8_t len = strlen(strBuf);
  while (len++ < n) outLen += Serial.print(c);
  outLen += Serial.print(strBuf);
}
void displayValue(cell_t w, uint8_t base) {
  displayValue(w, base, 0, 0);
}
void displayValue(cell_t w) {
  displayValue(w, base, 0, 0);
}
void displayValue(cell_t w, uint8_t n, char c) {
  displayValue(w, base, n, c);
}

#endif
