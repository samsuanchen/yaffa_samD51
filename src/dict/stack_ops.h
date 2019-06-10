// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

//extern const char dupe_str[]; // = "dup";
extern void _dupe(void);

//extern const char pick_str[]; // = "pick";
extern void _pick(void);

//extern const char swap_str[]; // = "swap";
extern void _swap(void);

//extern const char rot_str[]; // = "rot";
extern void _rot(void);

//extern const char and_str[]; // = "and";
extern void _and(void);

//extern const char or_str[]; // = "or";
extern void _or(void);

//extern const char xor_str[]; // = "xor";
extern void _xor(void);

//extern const char dot_str[];    // = ".";
extern void _dot(void);

//extern const char u_dot_str[]; // = "u.";
extern void _u_dot(void);

//extern const char dot_s_str[]; // = ".s";
extern void _dot_s(void);

//extern const char emit_str[]; // = "emit";
extern void _emit(void);

//extern const char paren_str[]; // = "("; // samsuanchen@gmail.com 20190503
extern void _paren(void); // samsuanchen@gmail.com 20190503

//extern const char dot_paren_str[]; // = ".(";
extern void _dot_paren(void);

//extern const char cr_str[]; // = "cr"; // ( -- ) Carriage Return
extern void _cr(void);

//extern const char space_str[]; // = "space";
extern void _space(void);

//extern const char spaces_str[]; // = "spaces";
extern void _spaces(void); // n --

//extern const char hex_str[]; // = "hex";
extern void _hex(void); // --

//extern const char decimal_str[]; // = "decimal";
extern void _decimal(void);

//extern const char romEntry_str[]; // = "romEntry" // samsuanchen@gmail.com 20190502
extern void _romEntry(void); // i -- romEntryAdr // samsuanchen@gmail.com 20190502

//extern const char ramFirst_str[]; // = "ramFirst" // samsuanchen@gmail.com 20190511
extern void _ramFirst(void); // -- ramFirstAdr // samsuanchen@gmail.com 20190511

//extern const char ramLast_str[]; // = "ramLast" // samsuanchen@gmail.com 20190502
extern void _ramLast(void); // -- ramLastAdr // samsuanchen@gmail.com 20190502

//extern const char isRamEntry_str[]; // samsuanchen@gmail.com 20190502
extern void _isRamEntry(void); // samsuanchen@gmail.com 20190502

//extern const char nextRamEntry_str[]; // samsuanchen@gmail.com 20190502
extern void _nextRamEntry(void); // samsuanchen@gmail.com 20190502
	
//extern const char words_str[]; // = "words";
extern void _words(void); // --

//extern const char zero_equal_str[]; // = "0=";
extern void _zero_equal(void);

//extern const char delay_str[]; // = "delay";
extern void _delay(void);

extern cell_t dStack_pop();
extern void dStack_top(cell_t);
extern cell_t dStack_top(void);
extern userEntry_t* pFirstUserEntry;

extern void _dash_rot(void);

extern void _bgBlue(void);
extern void _fgRed(void);
extern void _fgWhite(void);
extern void _bgBlack(void);
extern void _to_in(void);
extern void _to_number(void);
/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
