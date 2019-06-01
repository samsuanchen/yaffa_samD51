// Thu Aug  3 19:07:55 UTC 2017
// 4735-b0f-00-

// download interpreter

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#include "dl_interpreter.h"
/******************************************************************************/
/** Interpeter - Interprets a new string                                     **/
/**                                                                          **/
/** Parse the new line. For each parsed subString, try to execute it.  If it **/
/** can't be executed, try to interpret it as a number.  If that fails,      **/
/** signal an error.                                                         **/
/******************************************************************************/
void dl_interpreter(void) { // download interpreter
    func function;
    // if (noInterpreter) { }
    while (getToken()) { // parse a string into cTokenBuffer
            /************************/
            /* Interpret Mode       */
            /************************/
            if (isDLWord(cTokenBuffer)) { // get w and wordFlags
                if (wordFlags & COMP_ONLY) {
                    dStack_push(-14);
                    _throw();
                    return;
                }
                if (w > nFlashEntry) { // w of DLWord could not be greater than 255
                //  Serial.printf("\r\ndebug: Error w=$%X line 32 dl_interpreter.cpp.\r\n", w);
                }
                else { // execute the DLWord
                    function = DLflashDict[w - 1].function;
                    function();
                    if (errorCode) return;
                }
            } // ends stanza that began 'if (isDLWord(cTokenBuffer))'

            else if (isDLNumber(cTokenBuffer)) {
                int fake_Int_xx = 0 ; // noop // Is something supposed to be here?
            }
            else {
                return;
            }

    } // ends stanza that began 'while (getToken())'
    cpToIn = cpSource;
  }

