// Mon Jan 15 19:19:47 UTC 2018
// 4737-a0d-05d-

// previous timestamp:
// Wed Aug  2 01:22:51 UTC 2017
// 4735-b0c-03-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_SIGN_ON
#include "signon.h"
void setEscPrint(char* str){ Serial.print("\033["); Serial.print(str); Serial.print("m"); }
void _setEscPrint(){
	if(! getToken()) { dStack_push(-16); _throw(); }
	setEscPrint(cTokenBuffer);
}
void _fgBlack(){ setEscPrint("30"); }
void _fgRed(){ setEscPrint("31"); }
void _fgGreen(){ setEscPrint("32"); }
void _fgYellow(){ setEscPrint("33"); }
void _fgBlue(){ setEscPrint("34"); }
void _fgMagenta(){ setEscPrint("35"); }
void _fgCyan(){ setEscPrint("36"); }
void _fgWhite(){ setEscPrint("37"); }
void _fgBrightBlack(){ setEscPrint("30;1"); }
void _fgBrightRed(){ setEscPrint("31;1"); }
void _fgBrightGreen(){ setEscPrint("32;1"); }
void _fgBrightYellow(){ setEscPrint("33;1"); }
void _fgBrightBlue(){ setEscPrint("34;1"); }
void _fgBrightMagenta(){ setEscPrint("35;1"); }
void _fgBrightCyan(){ setEscPrint("36;1"); }
void _fgBrightWhite(){ setEscPrint("37;1"); }
void _bgBlack(){ setEscPrint("40"); }
void _bgRed(){ setEscPrint("41"); }
void _bgGreen(){ setEscPrint("42"); }
void _bgYellow(){ setEscPrint("43"); }
void _bgBlue(){ setEscPrint("44"); }
void _bgMagenta(){ setEscPrint("45"); }
void _bgCyan(){ setEscPrint("46"); }
void _bgWhite(){ setEscPrint("47"); }
void _bgBrightBlack(){ setEscPrint("100"); }
void _bgBrightRed(){ setEscPrint("101"); }
void _bgBrightGreen(){ setEscPrint("102"); }
void _bgBrightYellow(){ setEscPrint("103"); }
void _bgBrightBlue(){ setEscPrint("104"); }
void _bgBrightMagenta(){ setEscPrint("105"); }
void _bgBrightCyan(){ setEscPrint("106"); }
void _bgBrightWhite(){ setEscPrint("107"); }
/******************************************************************************/
/** signOn - say Hello to the user interface via USB serial port             **/
/******************************************************************************/
void signOn(void) {
  // Serial.begin(19200);     // Open serial communications:

  // Serial.print("\n warm boot message - early bird."); // instant confirmation

  // delay(9 * 100);

  // colours - entirely optional

  // Serial.print("\n YAFFA - Yet Another Forth For Arduino, ");

//  Serial.print("Version ");
//  Serial.print(YAFFA_MAJOR,DEC);
//  Serial.print(".");
//  Serial.println(YAFFA_MINOR,DEC);
//  Serial.print("\033\133\064\060m"); // ESC [40m - black bg // for the stanza
    Serial.print("\r\n\r\n "); // leading black space on the wa1tnr line
    _bgBlue();
//  Serial.print("\033\133\064\064m"); // ESC [44m - blue bg // for the stanza
    Serial.print(" YAFFA samd51Forth (");
    nFlashEntry = 0; while (flashDict[nFlashEntry++].name); Serial.print(--nFlashEntry);
    pLimitFlashEntry = (flashEntry_t*) &flashDict[nFlashEntry];
    Serial.print(" romWords) - 201905 - samsuanchen@gmail.com ");
	_bgBlack(); _fgWhite();
//  Serial.print("\033\133\064\060m"); // ESC [40m - black bg // for the stanza
    Serial.print(" \r\n ok\r\n");  // leading black space on the wa1tnr line
//  Serial.print("  \r\n  YAFFA - Yet Another Forth For Arduino, \r\n");
//  Serial.print("         Copyright (C) 2012 Stuart Wood\r\n");

//  Serial.print(" This program comes with ABSOLUTELY NO WARRANTY.\r\n");
//  Serial.print(" This is free software, and you are welcome to\r\n");
//  Serial.println(" redistribute it under certain conditions.\r\n");
  
//  Serial.print(" Processor is a ");
//  Serial.println(PROC_STR);
//  Serial.print(" Terminal Echo is ");
//  Serial.print(flags & ECHO_ON ? "On\r\n" : "Off\r\n");
//  Serial.print(" Pre-Defined Words : ");


//  Serial.println("\r\n Environment Parameters: ");
//  Serial.print(" Counted String Length: \t");
//  Serial.print(BUFFER_SIZE);
//  Serial.println(" Bytes");
//  Serial.print(" Pict. Num. Output Length: \t");
//  Serial.print(HOLD_SIZE);
//  Serial.println(" Bytes");
//  Serial.print(" Scratch Pad size: \t\t");
//  Serial.print(PAD_SIZE);
//  Serial.println(" Bytes");
//  Serial.print(" Address Size: \t\t\t");
//  Serial.print(sizeof(void*) * 8);
//  Serial.println(" Bits");
//  Serial.print(" Core Word set: \t\t");
//  Serial.println(CORE ? "TRUE" : "FALSE");
//  Serial.print(" Ext. Core Word set: \t\t");
//  Serial.println(CORE_EXT ? "TRUE" : "FALSE");
//  Serial.print(" Floored Division: \t\t");
//  Serial.println(FLOORED ? "TRUE" : "FALSE");
//  Serial.print(" Max. Char Value: \t\t");
//  Serial.print(MAX_CHAR);
//  Serial.println(" Dec.");
#ifdef DOUBLE
//  Serial.print(" Max. Signed Double: \t\t");
//  Serial.print(MAX_OF(dcell_t));
//  Serial.println(" Dec.");
#endif
//  Serial.print(" Max. Singed Integer: \t\t");
//  Serial.print(MAX_OF(cell_t));
//  Serial.println(" Dec.");
//  Serial.print(" Max. unsigned Integer: \t");
//  Serial.print(MAX_OF(ucell_t));
//  Serial.println(" Dec.");
//  Serial.print(" Max. Return Stack Size: \t");
//  Serial.print(RSTACK_SIZE);
//  Serial.println(" Cells");
//  Serial.print(" Max. Data Stack Size: \t\t");
//  Serial.print(STACK_SIZE);
//  Serial.println(" Cells");

//  Serial.print("\r\n Input Buffer: Size ");
//  Serial.print(BUFFER_SIZE);
//  Serial.print(" Bytes, Starts at $");
//  Serial.print((size_t)cInputBuffer[0], HEX);
//  Serial.print(", Ends at $");
//  Serial.println((size_t)cInputBuffer[BUFFER_SIZE] - 1, HEX);

//  Serial.print(" Token Buffer: Size ");
//  Serial.print(WORD_SIZE);
//  Serial.print(" Bytes, Starts at $");
//  Serial.print((size_t)&cTokenBuffer[0], HEX);
//  Serial.print(", Ends at $");
//  Serial.println((size_t)&cTokenBuffer[WORD_SIZE] - 1, HEX);

//  Serial.print(" Forth Space: Size ");
//  Serial.print(FORTH_SIZE);
//  Serial.print(" Cells, Starts at $");
//  Serial.print((size_t)&forthSpace[0], HEX);
//  Serial.print(", Ends at $");
//  Serial.println((size_t)&forthSpace[FORTH_SIZE] - 1, HEX);

// Serial.print(prompt_str);
}

#endif
