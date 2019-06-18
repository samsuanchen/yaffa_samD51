// Fri Jun  9 02:32:35 UTC 2017
// 4735-a0f

#include <Arduino.h>
#include "../../yaffa.h"
#include "../../Error_Codes.h"

#ifdef EXT_KERN_THROW
#include "throw.h"

#ifndef EXCEPTION_SET
#define EXCEPTION_SET
#endif // #ifndef EXCEPTION_SET

#ifdef EXCEPTION_SET
// const char throw_str[] = "throw";
// ( k*x n -- k*x | i*x n)
// if any bit of n are non-zero, pop the topmost exception frame from the
// exception stack, along with everything on the return stack above that frame.
// ...
void _throw( cell_t errCode, char* message ){
	_cr();
	_fgRed();
	Serial.print(cTokenBuffer);
	_fgWhite();
	Serial.print(F(" EXCEPTION "));
	if( errCode ){
		uint8_t index = 0;
		int tableCode;
		do {
			tableCode = pgm_read_dword(&exception[index].code);
			if (errCode == tableCode) {
				errorCode = errCode;
				Serial.print((int)errCode);
				Serial.print(" ");
				Serial.print(exception[index].name);
				break;
			}
		index++;
		} while ( tableCode );
		
	} else errorCode = 1, Serial.print(message); 
	ip = ip_begin = 0;
	dStack_clear(), state = FALSE;
	extern void waitEsc(void);
	waitEsc();
	_quit();
}
void _throw( char* message ) { _throw( 0, message ); }
void _throw( cell_t errorCode ) { _throw( errorCode, "" ); }
void _throw(void) {
	cell_t error = dStack_pop();
	if( error > 256 ) _throw( (char*) error );
	else _throw( error );
}  
#endif
#endif
