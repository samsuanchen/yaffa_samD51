// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_ENTRY
#include "entry.h"
/******************************************************************************/
/** Start a New Entry in the Dictionary ** create a colon word               **/
/******************************************************************************/
void openEntry(void) {
  uint8_t index = 0;
  pOldHere = pHere;            // Save the old location of HERE so we can
                               // abort out of the new definition
  pNewUserEntry = (userEntry_t*)pHere;
  pLastUserEntry = (userEntry_t*) *current;
  pNewUserEntry->prevEntry = pLastUserEntry;
  if (!getToken()) { dStack_push(-16); _throw(); }
  char* ptr = pNewUserEntry->name;
  do {
    *ptr++ = cTokenBuffer[index++];
  } while (cTokenBuffer[index] != '\0');
  *ptr++ = '\0';
  pHere = (cell_t *)ptr;
  ALIGN_P(pHere);

  pNewUserEntry->cfa = pHere;
  pCodeStart = pHere;
}

/******************************************************************************/
/** Finish an new Entry in the Dictionary ** close a colon word              **/
/******************************************************************************/
void closeEntry(void) { // samsuanchen@gmail.com.tw 20190509
  if (errorCode == 0) {
    pNewUserEntry->flags = 0; // clear the word's flags
//  Serial.printf("\r\nnewUserEntry %X cfa %X %s (last %X)",pNewUserEntry, pNewUserEntry->cfa, pNewUserEntry->name, pLastUserEntry);
	pLastUserEntry = pNewUserEntry;
    *current = (cell_t) pLastUserEntry;
  } else pHere = pOldHere;   // Revert pHere to what it was before the start
                             // of the new word definition
}
void endEntry(void) { // samsuanchen@gmail.com.tw 20190509
  if (errorCode == 0) *pHere++ = EXIT_IDX;
  closeEntry();
}

#endif
