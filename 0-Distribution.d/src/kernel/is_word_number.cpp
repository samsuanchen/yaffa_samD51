// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_IS_WORD_NUMBER
#include "is_word_number.h"
/******************************************************************************/
/** check given string if it's flashDict wordname or user defined wordname   **/
/** return 0 or xt (the execution token).                                    **/
/**   the execution token is flashWord index+1 or userWord cfa.              **/
/** also set register w = xt and set register wordFlags                      **/
/******************************************************************************/

#define MWORDS 1024 // number of words defined at most
uint8_t nameLEN[MWORDS];
uint8_t nWord = 0;
uint8_t iWord;

uint8_t nameLen( char* name ) { uint8_t len;
if ( iWord == nWord ) { len = strlen( name ); nameLEN[nWord++] = len; }
  else len = nameLEN[iWord];
  return len;
}

uint32_t isWord( char* str, uint8_t n ) { // samsuanchen@gmail.com 20190521
  Serial.print( "\r\ncalling isWord(\"" ), Serial.print( str ); // debug //
  Serial.print( "\", " ), Serial.print( n ); // debug //
  Serial.print( ") nWord=" ), Serial.print( nWord ); // debug //
  char* name;  iWord = w = 0;
  // First Search flash Dictionary
  while ( name = (char*) flashDict[iWord].name ) {
    if ( n == nameLen( name ) && strncmp( str, name, n ) == 0 ) {
      w = iWord + 1, wordFlags = flashDict[iWord].flags;
      break;
    }
    iWord++;
  }
  // Second search user dictionary
  if( ! w ) {
    pUserEntry = pLastUserEntry;
    while ( pUserEntry ) {
      name = pUserEntry->name;
      if ( n == nameLen( name ) && strncmp( name, str, n ) == 0 ) {
        w = (size_t) pUserEntry->cfa, wordFlags = pUserEntry->flags;
        break;
      }
      pUserEntry = (userEntry_t*) pUserEntry->prevEntry, iWord++;
    }
  }
  Serial.print(" return w = $"), Serial.print(w, 16); // debug //
  Serial.print(" iWord = $"), Serial.print(iWord, 16); // debug //
  Serial.print(" wordFlags = 0x"), Serial.print(wordFlags, 16), Serial.print("  "); // debug //
  return w;
}

uint32_t isWord( char* addr ) { // samsuanchen@gmail.com 20190522
//	return isWord( addr, strlen(addr) ); /*
  // debug // Serial.print( "\r\nisWord(\"" ), Serial.print( addr );
  // debug // Serial.print( "\") is calling " );
  char* name; iWord = w = 0;
  // First Search through the flash Dictionary
  while ( name = (char*) flashDict[iWord].name ) {
    if ( strcmp( addr, name ) == 0 ) {
      w = iWord + 1;
      wordFlags = flashDict[iWord].flags;
      break; // samsuanchen@gmail.com 20190502
    }
    iWord++;
  }
  // Second search through the user dictionary
  if ( ! w ) {
    pUserEntry = pLastUserEntry;
    while ( pUserEntry ) {
    	name = pUserEntry->name;
      if ( strcmp( name, addr ) == 0 ) {
        wordFlags = pUserEntry->flags;
        w = (size_t) pUserEntry->cfa; // samsuanchen@gmail.com 20190502
        break; // samsuanchen@gmail.com 20190502
      }
      pUserEntry = (userEntry_t*)pUserEntry->prevEntry;
    }
  }
  // debug // Serial.print(" return w = 0x" ), Serial.print( w, 16 ), Serial.print( "  " );
  return w; //*/
}
void _isWord(void){
	dStack_push( isWord( (char*) dStack_pop(), dStack_pop() ) );
}

/******************************************************************************/
/** Attempt to interpret token as a number.  If it looks like a number, push **/
/** it on the stack and return 1.  Otherwise, push nothing and return 0.     **/
/**                                                                          **/
/** Numbers without a prefix are assumed to be decimal.  Decimal numbers may **/
/** have a negative sign in front which does a 2's complement conversion at  **/
/** the end.  Prefixes are # for decimal, $ for hexadecimal, and % for       **/
/** binary.                                                                  **/
/******************************************************************************/
uint8_t isNumber(char* subString) {
  unsigned char negate = 0;                  // flag if number is negative
  cell_t tempBase = base;
  cell_t number = 0;
  wordFlags = 0;
  // Look at the initial character, handling either '-', '$', or '%'
  switch (*subString) {
    case '$':  base = HEXIDECIMAL;  goto SKIP;
    case '%':  base = BINARY;   goto SKIP;
    case '#':  base = DECIMAL;  goto SKIP;
    case '-':  negate = 1;
SKIP:                // common code to skip initial character
    subString++;
    break;
  }
  // Iterate over rest of token, and if rest of digits are in
  // the valid set of characters, accumulate them.  If any
  // invalid characters found, abort and return 0.
  while (*subString) {
    char* pos = strchr(charset, (int)tolower(*subString));
    cell_t offset = pos - charset;
    if ((offset < base) && (offset > -1))
      number = (number * base) + (pos - charset);
    else {
      base = tempBase;
      return 0;           // exit, signalling subString isn't a number
    }
    subString++;
  }
  if (negate) number = ~number + 1;     // apply sign, if necessary
  dStack_push(number);
  base = tempBase;
  return 1;
}

#endif
