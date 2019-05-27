// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// version bump

// previous timestamp:
// Fri Nov 24 04:49:08 UTC 2017
// 4735-b0c-07z-   the -07x- is new Nov 19, 2017.
// Fri Nov 24 02:42:54 UTC 2017
// Thu Nov 23 02:01:47 UTC 2017
// Thu Nov 23 00:45:23 UTC 2017
// Wed Nov 22 21:43:39 UTC 2017
// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../flashDict.h"
#include "../../Dictionary.h"
#include "./stack_ops.h"

extern const char sp_str[]; // = " "; // does not belong here

/*******************************************************************************/
/**                          Core Forth Words                                 **/
/*******************************************************************************/

#ifndef STACK_OPS
#define STACK_OPS
#endif

#ifdef STACK_OPS
//const char dupe_str[] = "dup";
// ( x -- x x ) // Duplicate x
void _dupe(void) {
  dStack_push(dStack_peek(0));
}
//const char pick_str[] = "pick";
// ( ni .. n1 n0 i -- ni .. n1 n0 ni ) // pick i-th item ni
void _pick(void) {
  dStack_push(dStack_peek(dStack_pop()));
}

//const char swap_str[] = "swap";
void _swap(void) { // ( x y -- y x )
  cell_t x, y;
  y = dStack_pop();
  x = dStack_pop();
  dStack_push(y);
  dStack_push(x);
}
//const char rot_str[] = "rot";
// ( x1 x2 x3 -- x2 x3 x1)
void _rot(void) {
  cell_t x3 = dStack_pop();
  cell_t x2 = dStack_pop();
  cell_t x1 = dStack_pop();
  dStack_push(x2);
  dStack_push(x3);
  dStack_push(x1);
}
//const char and_str[] = "and";
// ( x1 x2 -- x3 )
// x3 is the bit by bit logical and of x1 with x2
void _and(void) {
  dStack_push(dStack_pop() & dStack_pop());
}
//const char or_str[] = "or";
// ( x1 x2 -- x3 )
// x3 is the bit by bit logical or of x1 with x2
void _or(void) {
  dStack_push(dStack_pop() |  dStack_pop());
}
//const char xor_str[] = "xor";
// ( x1 x2 -- x3 )
// x3 is the bit by bit exclusive or of x1 with x2
void _xor(void) {
  dStack_push(dStack_pop() ^  dStack_pop());
}
//const char dot_str[] = ".";
// ( n -- )
// display n in free field format
void _dot(void) {
  w = dStack_pop();
  displayValue();
}
//const char u_dot_str[] = "u.";
// ( u -- )
// Displau u in free field format
// tested and fixed by Alex Moskovskij
void _u_dot(void) {
  Serial.print((ucell_t) dStack_pop());
  Serial.print(F(" "));
}
/**                          Programming Tools Set                            **/
// #ifdef TOOLS_SET  // YAFFA-ARM organization: TOOLS_SET
//const char dot_s_str[] = ".s";
void _dot_s(void) {
  char i = 0;
  char j = 0;
  char depth = dStack_size();
  j = depth;
  Serial.print("<"); // gforthism 
  Serial.print(j+0); // comment was here
  Serial.print("> ");
  if (depth > 0) {
    for (i = depth; i > 0; i--) { // walk backwards
      j = i - 1; // normalize
      w = dStack_peek(j);
      displayValue();
    }
  }
}
//const char emit_str[] = "emit";
// ( x -- )
// display x as a character
void _emit(void) {
  Serial.print((char) dStack_pop());
}

// repair (or kludge) of the dot_paren word on 22 Nov 2017.

// In a four-byte field, the first character of a counted string
// appears to be right-aligned in that field.  To compensate,
// the address is now incremented by three, so that it now points
// to the first character in the counted string.
//const char paren_str[] = "(";
// ( "ccc<paren>" -- )
// ignore ccc delimitied by ) (right parenthesis). ( is an immediate word.
void _paren(void) { 
  dStack_push(')'); _word(); dStack_pop();
}
//const char dot_paren_str[] = ".(";
// ( "ccc<paren>" -- )
// Parse and display ccc delimitied by ) (right parenthesis). .( is an immediate word.
void _dot_paren(void) { 
  dStack_push(')');
  _word();
  _count(); // has the fixes (below) appended
  // _swap();
  // uint8_t* addr = (uint8_t*)dStack_pop();
  // *addr++;  *addr++;  *addr++;
  // dStack_push((size_t)addr);
  // _swap();
  _type();
}
//const char cr_str[] = "cr"; // ( -- ) Carriage Return
void _cr(void) {
  Serial.println();
}
//const char space_str[] = "space";
// ( -- )
// Display one space
void _space(void) {
  Serial.print(sp_str);
}
//const char spaces_str[] = "spaces";
// ( n -- )
// if n is greater than zero, display n space
void _spaces(void) {
  char n = (char) dStack_pop();
  while (n > 0) {
    Serial.print(sp_str);
    n--;
  }
}
//const char hex_str[] = "hex";
// ( -- )
// Set BASE to 16
void _hex(void) { // value --
  base = HEX;
}
//const char decimal_str[] = "decimal";
// ( -- )
// Set BASE to 10
void _decimal(void) { // value --
  base = DECIMAL;
}
//const char romEntry_str[] = "romEntry";
// ( w -- romEntryAddr )
// get romEntryAddr
void _romEntry(void) { // value --
  dStack_push((cell_t)&flashDict[dStack_pop()-1]);
}
//const char ramFirst_str[] = "ramFirst";
// ( -- ramFirstAddr ) // get ramFirstAddr
void _ramFirst(void) { // value --
  dStack_push((cell_t)pFirstUserEntry);
}
//const char ramLast_str[] = "ramLast";
// ( -- ramLastAddr ) // get ramLastAddr
void _ramLast(void) { // value --
  dStack_push((cell_t)pLastUserEntry);
}
int isRamEntry(cell_t* adr, userEntry_t* pUserEntry){
	if( adr > (cell_t*)pLastUserEntry ) return 1;
	if( *adr != (cell_t) pUserEntry ) return false;
	userEntry_t* nextEntry = (userEntry_t*) adr;
	extern void printHex(cell_t);
	int a = (int) adr + 9;
	a += (int) strlen( (char*) a ) + 4;
	a &= -4;
	int flag=0; if((int) nextEntry->cfa == a) flag=-1;
	return flag;
}
/*
: isRamEntry ( entry adr -- entry adr flag ) \ flag: -1 true, 0 false, 1 no more
  dup here <
  if 2dup @ = ( entry adr flag )
    if ( entry adr )
      dup entry>cfa ( entry entry' cfa' )
      over 9 + ( entry entry' cfa' name' )
      dup strlen + 4 + -4 and = ( entry entry' flag )
    else 0 \ adr is not next entry
    then
  else 1 \ adr >= here, means no more
  then ;
*/
//const char isRamEntry_str[] = "isRamEntry";
void _isRamEntry(){ // ( entry adr -- entry adr flag ) \ flag: -1 true, 0 false, 1 no more
	cell_t* adr = (cell_t*) dStack_pop();
	userEntry_t* entry = (userEntry_t*) dStack_pop();
	dStack_push( (cell_t) entry );
	dStack_push( (cell_t) adr );
	dStack_push( (cell_t) isRamEntry( adr, entry ) );
}
userEntry_t* nextRamEntry(userEntry_t* pUserEntry){ ////////////////////////
	if(pUserEntry >= pLastUserEntry) return 0;
	cell_t *cfa = pUserEntry->cfa, *adr = cfa; adr++; int flag;
	while ( ! ( flag = isRamEntry(adr, pUserEntry) ) ) adr++;
	if( flag == 1 ) adr = 0;
	return (userEntry_t*) adr;
}
/*
: nextRamEntry ( entry -- entry' true | false )
  dup entry>cfa ( entry cfa )
  begin cell+ isRamEntry ?dup
  until 0 <
  if nip -1
  else 2drop 0
  then ;
*/
//const char nextRamEntry_str[] = "nextRamEntry";
void _nextRamEntry(){ // ( entry -- entry' | 0 )
	userEntry_t* entry = (userEntry_t*) dStack_pop();
	userEntry_t* adr = nextRamEntry(entry);
	dStack_push( (cell_t) adr );
}

#define OUTLMT 70
uint8_t outLen;
void println(){ Serial.println(); outLen = 0; }
void queryPrintName(char*name, uint8_t flags, uint8_t n, char*sub, uint8_t outLmt){
	if (outLen > outLmt) println();
	if(n==0 || strstr(name, sub)) {
	  if(flags & COMP_ONLY) _bgBlue();
	  if(flags & IMMEDIATE) _fgRed();
	  outLen += Serial.print(name);
	  if(flags & IMMEDIATE) _fgWhite();
	  if(flags & COMP_ONLY) _bgBlack();
	  outLen += Serial.print(" ");
    }
}
//const char words_str[] = "words";
void _words(void) { // ( <substr> -- )
  println();
  uint8_t n=getToken();
  // search flash rom entry
  uint8_t index = 0, flags;
  char* name = (char*) flashDict[index].name;
  while ( name ) { // entry name != 0
  	queryPrintName( name, flashDict[index].flags, n, cTokenBuffer, OUTLMT );
  	name = (char*) flashDict[++index].name;
  }
  // search user ram entry
  pUserEntry = (userEntry_t*) pFirstUserEntry;
  while ( pUserEntry ) {
  	queryPrintName( pUserEntry->name, pUserEntry->flags, n, cTokenBuffer, OUTLMT );
  	pUserEntry = nextRamEntry(pUserEntry); // ascending order samsuanchen@gmail.com 20190516
  }
  println();
}
//const char zero_equal_str[] = "0=";
// ( n -- flag )
// flag is true if and only if n is equal to zero.
void _zero_equal(void) {
  dStack_top(dStack_top()==0 ? TRUE : FALSE);
}
//const char delay_str[] = "delay";
void _delay(void) {
  delay(dStack_pop());
}
#endif


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
