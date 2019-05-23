// Sun Jun 25 03:24:01 UTC 2017
// 4735-a0r-04-

#include <Arduino.h>
#include "../../yaffa.h"
// #include "../../Error_Codes.h"

#ifdef EXT_KERN_CONSTANT
#include "constant.h"
/******************************************************************************/
/**                                                                          **/
/******************************************************************************/
const char con_sys_str[] = "con-sys";
// ( -- n )
void _con_sys(void) {
	dStack_push(*ip);
	_exit();
}
const char constant_str[] = "constant";
// ( x"<spaces>name" --  )
void _constant(void) {
  openEntry();
  *pHere++ = CONST_IDX;
  *pHere++ = dStack_pop();
  closeEntry();
}

#endif
