// a_yaffa_samd51.cpp samsuanchen@gmail.com 20190601
// "a_" is good for loading first

// Sun Nov  4 01:50:28 UTC 2018
// 4737-a3c-00d- // ainsuForth-gen-exp-m4
// On branch testing-gg-

#include <Arduino.h>
#include "yaffa.h"
#include "error_codes.h"

#include "a_yaffa_samd51.h"

#include "src/kernel/getline.h"
//#include "src/periph/neo_pixel.h"
#include "src/dict/cblink.h"

#ifdef HAS_QSPI_FLASHROM_LIB
  #include "src/periph/qspi/flashrom.h"
#endif // #ifdef HAS_QSPI_FLASHROM_LIB

/******************************************************************************/
/**  The Arduino M0 pro has 0x4000 as bootloader offset                      **/
/**  seen or misremembered: M4 also at 0x4000                                **/
/******************************************************************************/

/******************************************************************************/
/** Major and minor revision numbers                                         **/
/******************************************************************************/
#define YAFFA_MAJOR 0
#define YAFFA_MINOR 7
#define MAKESTR(a) #a
#define MAKEVER(a, b) MAKESTR(a*256+b)
asm(" .section .version\n"
    "yaffa_version: .word " MAKEVER(YAFFA_MAJOR, YAFFA_MINOR) "\n"
    " .section .text\n");


/******************************************************************************/
/** Common Strings & Terminal Constants                                      **/
/******************************************************************************/
const char prompt_str[] = "";                // const char prompt_str[] = ">> ";
const char compile_prompt_str[] = "\r\n"; // ainsu: gforthism.
                                             // const char compile_prompt_str[] = "|  ";
// const char sp_str[] = " ";
// const char tab_str[] = "\t";
// const char hexidecimal_str[] = "$";
// const char octal_str[] = "0";
// const char binary_str[] = "%";
// const char zero_str[] = "0";

/******************************************************************************/
/** Global Variables                                                         **/
/******************************************************************************/

/******************************************************************************/
/**  Text Buffers and Associated Registers                                   **/
/******************************************************************************/
char* cpSource;                 // Pointer to the string location that we will
                                // evaluate. This could be the input buffer or
                                // some other location in memory
char* cpSourceEnd;              // Points to the end of the source string
char* cpToIn;                   // Points to a position in the source string
                                // that was the last character to be parsed
char cDelimiter = ' ';          // The parsers delimiter
char cInputBuffer[BUFFER_SIZE]; // Input Buffer that gets parsed
char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

/******************************************************************************/
/**  Stacks and Associated Registers                                         **/
/**                                                                          **/
/**  Control Flow Stack is virtual right now. But it may be but onto the     **/
/**  data stack. Error checking should be done to make sure the data stack   **/
/**  is not corrupted, i.e. the same number of items are on the stack as     **/
/**  at the end of the colon-sys as before it is started.                    **/
/******************************************************************************/
// stack_t dStack;
// stack_t rStack;
/******************************************************************************/
/**  Flash Dictionary Structure                                              **/
/******************************************************************************/
const flashEntry_t* pFlashEntry = flashDict;   // Pointer into the flash Dictionary
uint16_t nFlashEntry;
flashEntry_t* pLimitFlashEntry;

const flashEntry_t* pDLFlashEntry = DLflashDict; // Pointer into the DL vocab flash Dictionary

/******************************************************************************/
/**  User Dictionary is stored in name space.                                **/
/******************************************************************************/
userEntry_t* pFirstUserEntry;
userEntry_t* pLastUserEntry;
userEntry_t* pUserEntry;
userEntry_t* pNewUserEntry;

cell_t* pLastVoc;
cell_t* context[] = {0, 0, 0, 0, 0, 0, 0, 0};
uint8_t nContext;
int8_t iContext;
cell_t* current;

/******************************************************************************/
/**  Flags - Internal State and Word                                         **/
/******************************************************************************/
uint8_t flags;                 // Internal Flags
uint8_t wordFlags;             // Word flags
uint8_t spiFlashReading;       // Adafruit SPI flash: reading

uint8_t silentReading = FALSE ;   // the load word is silent, if this flag is set

uint8_t spiFlashWaiting = FALSE ;       // there is more to read from an open forth source file
uint8_t fileClosed = TRUE ;

// uint8_t noInterpreter = TRUE  ;
uint8_t noInterpreter = FALSE ;
uint8_t alreadyParsed = FALSE ;

// File thisFile; // spi flash file handle

/******************************************************************************/
/** Error Handling                                                           **/
/******************************************************************************/
int8_t errorCode = 0; // ainsuForth: stays.

/******************************************************************************/
/**  Forth Space (Name, Code and Data Space) and Associated Registers        **/
/******************************************************************************/
char* pPNO;                  // Pictured Numeric Output Pointer
cell_t forthSpace[FORTH_SIZE]; // Reserve a block on RAM for the forth environment
cell_t* pHere;               // HERE, points to the next free position in
                             // Forth Space
cell_t* pOldHere;            // Used by "colon-sys"
cell_t* pCodeStart;          // used by "colon-sys" and RECURSE
cell_t* pDoes;               // Used by CREATE and DOES>

/******************************************************************************/
/** Forth Global Variables                                                   **/
/******************************************************************************/
uint8_t state; // Holds the text interpreters compile/interpreter state
cell_t* ip;   // Instruction Pointer
cell_t* ip_begin;   // Instruction Pointer begin colon definition
cell_t  w;     // Working Register
uint8_t base;  // stores the number conversion radix

/******************************************************************************/

// gemma M0 has dotstar:  D3 is data   D4 is clock

#ifndef LEDX
  #define LED 13
#else // one edge-case: ADAFRUIT_ITSYBITSY_M0
  #define LED 37
#endif

void blink(void) {
  pinMode(LED, 1); /* samsuanchen@gmail.com 20190516
  dStack_push(1); dStack_push(LED);
  pinMode(dStack_pop(), dStack_pop()); */
  digitalWrite(LED, 1); /* samsuanchen@gmail.com 20190516
  dStack_push(1); dStack_push(LED);
  digitalWrite(dStack_pop(), dStack_pop()); */
  delay(11); // bad technique
  digitalWrite(LED, 0); /* samsuanchen@gmail.com 20190516
  dStack_push(0); dStack_push(LED);
  digitalWrite(dStack_pop(), dStack_pop()); */
  delay(3); // bad technique
}
//  NEEDS REVIEW with other than the current ItsyBitsyM4 target - 13 June 2018
void blink_m(void) {
//#ifdef HAS_DOTSTAR_LIB
//  loop_dotstar();
//#elif defined HAS_NEO_PIXEL_LIB
    delay(1200);
    _mblink(); // magenta 100 ms blip on neoPixel
    delay(1100);
//#endif // #ifdef HAS_DOTSTAR_LIB
    delay(1200);
    blink();
    delay(1200);
    // 2500 ms is 24 pulses per minute
}


/******************************************************************************/
/** Initialization                                                           **/
/******************************************************************************/
void setup(void) {              
//uint16_t mem;
  
//#ifdef HAS_NEO_PIXEL_LIB
//  setup_neoPixel();
//  Serial.println("setup_neoPixel()");
//#endif

//#ifdef HAS_DOTSTAR_LIB
//setup_dotstar();
//Serial.println("setup_dotstar()");
//#endif
  // magentaDull();
  Serial.begin(115200);        // Open serial communications:
  while (!Serial) {
    blink_m();
  }
  tone(A0, 440, 1000), delay(250), tone(A0, 330, 1000); //noTone(A0);
  extern void _fgYellow(void), _bgBlack(void), _bgBrightYellow(void);
  _fgYellow(), _bgBlack();
  Serial.print("\r\n Serial.begin(115200) buzzer pin A0 = "), Serial.println(A0);

#ifdef HAS_QSPI_FLASHROM_LIB // see yaffa.h for setting this toggle
  setup_qspiFlashROM(); // for Metro M4 Express Beta w/QSPI flashROM, only.
//Serial.println("setup_qspiFlashROM(); // Seen: Line 250 sketch");
#endif

#ifdef HAS_SPI_FLASH_DEMO
// src/kernel/getline.cpp:33:void setup_spi_flash(void) {
// src/kernel/getline.cpp:653:  ascii_xfer_setup_spi_flash();
  setup_spi_flash();
  Serial.println("setup_spi_flash()");
      // WORKS: 01 Aug 04:09z
      // read_a_test_file();
  // xxread_a_test_file();
#endif

  delay(300); // 300 ms
  _cblink();
  delay(300); // 300 ms

  // Serial.begin(57600);     // Open serial communications:
  // Serial.begin(115200);    // Open serial communications:

  // 24 June: upload during compile crashes even with higher baud rates.

  flags = ECHO_ON;
  base = DECIMAL;
  pNewUserEntry = (userEntry_t*)&forthSpace[0];
  pLastUserEntry = pFirstUserEntry = pNewUserEntry;
  forthSpace[0] = 0; // no prevWord
  forthSpace[1] = (cell_t) &forthSpace[4]; // cfa
  forthSpace[2] = 0x77656e00; // flag 0 and name "new"
  forthSpace[3] = 0; // end of string
  forthSpace[4] = 0x15; // VOC_SYS_IDX // (voc)
  forthSpace[5] = (cell_t) forthSpace; // this vocWord in vocabulary new
  forthSpace[6] = 0; // link to prevVoc
  pLastVoc = &forthSpace[6];
  pHere = &forthSpace[7];
  pOldHere = pHere;
  context[2] = context[1] = current = &forthSpace[5];
  nContext = 3;
  // Serial.print("\n warm boot message - early bird.  //  Gemma M0 29 Jul 2017\r\n          type 'warm' to reboot"); // instant confirmation
  // Serial.print("\n warm boot message - "    );
  // Serial.print("early bird.               " );
     Serial.print("\r\n GIT " gitShowStamp() );
     Serial.print("\r\n SIWNA feature " featureList() );
  // Serial.print("  c4e DEVPR - gen-exp-m4  " );
  // Serial.print(" date " dateStamp() );
  // Serial.print("\r\n"                       );
  // Serial.print("          "                 );
  // Serial.print("type 'warm' to reboot, but not" ); // instant confirmation
     Serial.print("\r\n time "       timeStamp() );
     Serial.print(" branch "      branchStamp() );
     Serial.print("\r\n shred "     shredStamp() );
     Serial.print(" target "      targetStamp() );
  // Serial.print(" sand birds");
     Serial.print("\r\n forthSpace $"), Serial.print((int)pHere,16);
     Serial.print(" size 0x"), Serial.print(FORTH_SIZE, 16);

  // 22 august: cosmetic update.  No code changes.

  // Serial.print("\n warm boot message - early bird.  //  Adafruit Metro M0 Express\r\n      snapshot 30 Jul 2017\r\n          type 'warm' to reboot"); // instant confirmation
  // Serial.print("\n warm boot message - early bird.  //  Adafruit Feather M0 Express\r\n      snapshot 30 Jul 2017\r\n          type 'warm' to reboot"); // instant confirmation

  // Serial.println("\r\nainsuForth -- main dev -- SEEN.\r\n   QUAVRO  MUVAK  03:25z or later.\r\n");

  delay(900); // 900 ms - optional - useful when coded for a 4+ second delay
              // to give the operator time to task switch from upload
              // to first .
  signOn();
}



/**                                                 **/
/** void compilePrompt(void);                       **/
/**                                                 **/
/** loop helper function                            **/
/**    -- when to print the compiler prompt         **/
/**       and what form it should take, depending   **/
/**       on how free the serial buffer is, to      **/
/**       print non-critical status info to the     **/
/**       terminal.                                 **/
/**                                                 **/

void compilePrompt(void) {
    int waiting = 0;
    waiting = Serial.available();
    if (waiting < 3) { // light traffic - there is slack enough to allow verbose output
      Serial.print(compile_prompt_str);
    } else {
        if (waiting < 20) { // moderate traffic
      Serial.print("ul \r\n"); // let user know that player-piano code upload speeds were noticed
        } else {
          if (waiting < 50) { // heavy traffic -- just the line endings are echo'd back to the user
            Serial.print("\r\n");
          } // else: inbound is just too fast -- print nothing extra
        } 
    }
}

/******************************************************************************/
/** Outer interpreter                                                        **/
/******************************************************************************/
void _ok() {
  Serial.print(" "); _fgBrightYellow(); Serial.print("OK");
  int n=dStack_size(); while(n--) Serial.print(".");
  _fgBlack(); Serial.println();
}
void loop(void) { blink();
    cpSource = cpToIn = cInputBuffer;
// -------------------------------------------------------------
// very last thing done before the commit was to set this trap,
// to avoid duplicate lines in the outfile (when it is setup to
// capture, which hasn't happened yett.  03 Aug 2017 15:08z
    alreadyParsed = FALSE ; // single-shot trap
// -------------------------------------------------------------
    cpSourceEnd = cpSource + getLine(cpSource, BUFFER_SIZE);
    if (cpSourceEnd > cpSource) { // 106 uint8_t noInterpreter = FALSE ;
        if (noInterpreter)
            dl_interpreter(); // if download sets noInterpreter == TRUE, then
                              // this is called after the 'download' word has
                              // executed, and, some other word has, also ..
                              // a bit too late, without further considerations.
        else interpreter();
        // if (spiFlashWaiting) { Serial.println("debug: LOOP - flash is WAITING."); }
        if (errorCode) errorCode = 0;
        else {
            if (!state) { // not compiling mode
                // suppress the ok prompt during ASCII upload:
                if (noInterpreter) int fake_intptrTwo = 0;
                else {
// was good but not quite enough to suppress CR/LF echo during a 'load' op:
                  if (!silentReading) _ok();
                }
                // This shows a DOT for each item on the data stack
                char n = dStack_size(); while(n--) Serial.print(".");
                if (! silentReading) Serial.println();
            }
        }
    } else { // test failed; do not run interpreter().

        if (noInterpreter) {
            // if (!silentReading)
                Serial.print("\r\n"); // just echo the CR/LF here
        } else {
          if (silentReading) int fake_SRT = 0;
          else if (! state) _ok(); // Leo Brodie 'Starting Forth' expects an ok here
        }
    } // replace these four lines with a single closing curly brace
      // to restore YAFFA behavior.
    if (state) {
        // if (silentReading && spiFlashReading && fileClosed) {
        if (silentReading && spiFlashReading) {
            int siRea = 0;
        } else {
          compilePrompt();
        }
    } else { // check what was here an hour ago -- don't remember if any flags were here.
        // if (silentReading && spiFlashReading) {
        // if (silentReading && fileClosed) {
        // if (silentReading) {
        if (spiFlashReading) {
            int fake = 0;
            // Serial.println("debug: we are still reading near compilePrompt.");
        } else { // dont be shy -- print it to the console
            Serial.print(prompt_str);
        }
    }
}
/******************************************************************************/
/** freeMem returns the amount of free forth space left.                     **/
/******************************************************************************/
static unsigned int freeMem(void) {
//   return (pHere - forthSpace);
}

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**  Version 0.7.0                                                           **/
/**                                                                          **/
/**  File: YAFFA.ino                                                         **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/**                                                                          **/
/**  This file is part of YAFFA.                                             **/
/**                                                                          **/
/**  YAFFA is free software: you can redistribute it and/or modify           **/
/**  it under the terms of the GNU General Public License as published by    **/
/**  the Free Software Foundation, either version 2 of the License, or       **/
/**  (at your option) any later version.                                     **/
/**                                                                          **/
/**  YAFFA is distributed in the hope that it will be useful,                **/
/**  but WITHOUT ANY WARRANTY; without even the implied warranty of          **/
/**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           **/
/**  GNU General Public License for more details.                            **/
/**                                                                          **/
/**  You should have received a copy of the GNU General Public License       **/
/**  along with YAFFA.  If not, see <http://www.gnu.org/licenses/>.          **/
/**                                                                          **/
/******************************************************************************/
/**                                                                          **/
/**  DESCRIPTION:                                                            **/
/**                                                                          **/
/**  YAFFA is an attempt to make a Forth environment for the Arduino that    **/
/**  is as close as possible to the ANSI Forth draft specification DPANS94.  **/
/**                                                                          **/
/**  The goal is to support at a minimum the ANS Forth C core word set and   **/
/**  to implement wrappers for the basic I/O functions found in the Arduino  **/
/**  library.                                                                **/
/**                                                                          **/
/**  YAFFA uses two dictionaries, one for built in words and is stored in    **/
/**  flash memory, and the other for user defined words, that is found in    **/
/**  RAM.                                                                    **/
/**                                                                          **/
/******************************************************************************/
