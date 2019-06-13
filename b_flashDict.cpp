// Fri 22 Jun 18:03:52 UTC 2018
// 4737-a3b-005-

// previous timestamps:
// Thu 21 Jun 22:17:21 UTC 2018
// 4737-a3b-001-  +dict_comments_only.cpp file

// eflmkdir - external flashROM mod - create new directory 17 June 2018.
// NOTE: you must compile this 'eflmkdir' word.  The very
// act of compilation also executes it
// (both IMMEDIATE and COMP_ONLY flags are set for it).

// Go ahead and compile it into a word and execute that
// new word (held as bytecode in RAM) as many times as
// you like.  It'll just give an ok prompt, as this word
// checks to see if the directory '/forth' exists or not,
// and only tries to mkdir if it does not.

// So it is harmless to do it a second, third, fourth .. time.

// { eflmkdir_str,       _eflmkdir,        IMMEDIATE + COMP_ONLY },

// Like that.


// Sun 17 Jun 22:09:15 UTC 2018 // 4737-a3a-0e0-
// Wed 23 May 03:16:05 UTC 2018 // 4737-a3a-05p-

// source word uncommented.

// Mon 14 May 18:47:28 UTC 2018 // 4737-a3a-05a-
// Sun 13 May 06:53:54 UTC 2018 // 4737-a3a-03f-
// Mon Jan 15 18:14:33 UTC 2018 // 4737-a0d-05c-

// SPI flashROM stuff

// look for #ifdef HAS_SPI_FLASH_DEMO   10 Dec 2017

// the accept word

// Sat Dec 16 01:24:37 UTC 2017 // 4737-a0a-00a-
// Sun Dec 10 22:48:03 UTC 2017 // 4735-b0d-00b-   the -00x- is new Dec 10, 2017.
// Sat Nov 25 19:03:16 UTC 2017 // 4735-b0c-09d-   the -09x- is new Nov 24, 2017.
// Fri Nov 24 23:31:39 UTC 2017 // 4735-b0c-09b-   the -09x- is new Nov 24, 2017.
// Thu Aug  3 01:46:56 UTC 2017 // 4735-b0d-00-

#include <Arduino.h>
#include "yaffa.h"
#include "error_codes.h"

#include "b_flashdict.h"

#include "dictionary.h"
#include "src/dict/new_dict_entries.h" // #include "src/dict/dict_entries.h" // 21 June 2018


/*********************************************************************************/
/**   'static void _foo(void)'  -- conflicts with 'extern void'                 **/
/*********************************************************************************/


/*********************************************************************************/
/**                         Dictionary Initialization                           **/
/*********************************************************************************/

const flashEntry_t DLflashDict[] = {
  { dl_ends_str,        _dl_ends,         NORMAL },  // IMMEDIATE
  { NULL,               NULL,             NORMAL }
};

/**                         Dictionary Initialization                           **/
const flashEntry_t flashDict[] = {
  /*****************************************************/
  /* The initial entries must stay in this order so    */
  /* they always have the same index. They get called  */
  /* referenced when compiling code                    */
  /*****************************************************/
  { "exit",           _exit,            NORMAL }, // 1
  { "literal",        _literal,         IMMEDIATE }, // 2
  { "type",           _type,            NORMAL }, // 3
  { "bran",           _jump,            SMUDGE }, // 4
  { "zbran",          _zjump,           SMUDGE }, // 5
  { "(does>)",        _subroutine,      SMUDGE }, // 6
  { "throw",          _throw,           NORMAL }, // 7
  { "(do)",           _do_sys,          SMUDGE }, // 8
  { "(loop)",         _loop_sys,        SMUDGE }, // 9
  { "(leave)",        _leave_sys,       SMUDGE }, // 10
  { "(+loop)",        _plus_loop_sys,   SMUDGE }, // 11
  { "evaluate",       _evaluate,        NORMAL }, // 112
  { "s\"",            _s_quote,         IMMEDIATE + COMP_ONLY }, // 113
  { ".\"",            _dot_quote,       IMMEDIATE + COMP_ONLY }, // 114
  { "(var)",          _var_sys,         NORMAL }, // 15 // samsuanchen@gmail.com 20190508
  { "over",           _over,            NORMAL }, // 16 // CAL
  { "=",              _eq,              NORMAL }, // 17 // CAL
  { "drop",           _drop,            NORMAL }, // 18 // CAL
  { "(con)",          _con_sys,         NORMAL }, // 19 // samsuanchen@gmail.com 20190508
  { "variable",       _variable,        NORMAL }, // 20 // moved to here samsuanchen@gmail.com 20190508
  { "(voc)",          _voc_sys,         NORMAL }, // 21 // samsuanchen@gmail.com 20190603
  { "vocabulary",     _vocabulary,      NORMAL }, // 22 // samsuanchen@gmail.com 20190603

  /*****************************************************/
  /* Order does not matter after here                  */
  /* Core Words                                        */
  /*****************************************************/
#if defined(INCL_NOP_WORD) || defined(XDICT)
  { "nop",            _nop,             NORMAL }, // 22 June 2018
#endif
  { "warm",           _warm,            NORMAL },
  { "print",          _print,           NORMAL },
  { ".",              _dot,             NORMAL },
  { "-",              _minus,           NORMAL },
  { "+",              _plus,            NORMAL },
  { "*",              _star,            NORMAL },
  { "0=",             _zero_equal,      NORMAL },
  { "abort",          _abort,           NORMAL },
  { "!",              _store,           NORMAL },
  { "#",              _number_sign,     NORMAL }, // added samsuanchen@gmail.com 20190510
  { "#>",             _number_sign_gt,  NORMAL }, // added samsuanchen@gmail.com 20190510
  { "#s",             _number_sign_s,   NORMAL }, // added samsuanchen@gmail.com 20190510
  { "'",              _tick,            NORMAL }, // added samsuanchen@gmail.com 20190502
  { "(",              _paren,           IMMEDIATE }, // samsuanchen@gmail.com 20190503
  { "*/",             _star_slash,      NORMAL },
  { "*/mod",          _star_slash_mod,  NORMAL },
  { "+!",             _plus_store,      NORMAL },
  { "+loop",          _plus_loop,       IMMEDIATE + COMP_ONLY },
  { ",",              _comma,           NORMAL },
  { "/",              _slash,           NORMAL },
  { "/mod",           _slash_mod,       NORMAL }, // samsuanchen@gmail.com 20190521
  { "0<",             _zero_less,       NORMAL }, // samsuanchen@gmail.com 20190521
  { "true",           _true,            NORMAL },
  { "false",          _false,           NORMAL },
  { "0",              _zero,            NORMAL },
  { "1",              _one,             NORMAL },
  { "2",              _two,             NORMAL },
  { "3",              _three,           NORMAL },
  { "4",              _four,            NORMAL },
  { "1+",             _one_plus,        NORMAL },
  { "1-",             _one_minus,       NORMAL },
  { "2+",             _two_plus,        NORMAL },
  { "2-",             _two_minus,       NORMAL },
  { "2*",             _two_star,        NORMAL },
  { "2!",             _two_store,       NORMAL },
  { "2/",             _two_slash,       NORMAL }, // samsuanchen@gmail.com 20190515
  { "2@",             _two_fetch,       NORMAL },
  { "2drop",          _two_drop,        NORMAL },
  { "2dup",           _two_dup,         NORMAL }, // samsuanchen@gmail.com 20190515
  { "2over",          _two_over,        NORMAL }, // samsuanchen@gmail.com 20190515
  { "2swap",          _two_swap,        NORMAL }, // samsuanchen@gmail.com 20190515
  { ":",              _colon,           NORMAL },
  { ";",              _semicolon,       IMMEDIATE },
  { "<",              _lt,              NORMAL }, // samsuanchen@gmail.com 20190502
  { "<#",             _lt_number_sign,  NORMAL }, // samsuanchen@gmail.com 20190510
  { ">",              _gt,              NORMAL }, // samsuanchen@gmail.com 20190515
  { ">body",          _to_body,         NORMAL },
  { ">in",            _to_in,           NORMAL },
  { ">number",        _to_number,       NORMAL },
  { ">r",             _to_r,            NORMAL },
  { "?dup",   _question_dup,    NORMAL },
  { "@",          _fetch,           NORMAL },
  { "abort\"",    _abort_quote,     IMMEDIATE + COMP_ONLY },
  { "abs",            _abs,             NORMAL },
//#ifdef EXT_KERN_ACCEPT // lets get rid of this test - legacy cruft - 22 June 2018
  { "accept",         _accept,          NORMAL },
//#endif
//   { "align",          _align,           NORMAL },
//   { "aligned",        _aligned,         NORMAL },
  { "allot",          _allot,           NORMAL },
  { "and",            _and,             NORMAL },
  { "base",           _base,            NORMAL },
  { "begin",         _begin,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "bl",             _bl,              NORMAL },
  { "c!",        _c_store,         NORMAL },
  { "c,",        _c_comma,         NORMAL },
  { "c@",        _c_fetch,         NORMAL },
  { "cell+",      _cell_plus,       NORMAL },
  { "cell-",      _cell_minus,       NORMAL },
  { "cells",          _cells,           NORMAL },
  { "cell/",      _cell_div,       NORMAL },
  { "char",           _char,            NORMAL },
  { "char+",      _char_plus,       NORMAL },
  { "chars",          _chars,           NORMAL },
  { "constant",       _constant,        NORMAL },
  { "strlen",           _strlen,        NORMAL }, // added samsuanchen@gmail.com 20190502
  { "again",         _again,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "count",          _count,           NORMAL }, // updated samsuanchen@gmail.com 20190502
  { "cr",             _cr,              NORMAL },
  { "create",         _create,          NORMAL },
  { "decimal",        _decimal,         NORMAL },
  { "depth",          _depth,           NORMAL },
  { "do",             _do,              IMMEDIATE + COMP_ONLY },
  { "does>",           _does,            IMMEDIATE + COMP_ONLY }, // modified samsuanchen@gmail.com 20190521
  { "dup",           _dupe,            NORMAL },
  { "else",         _else,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "emit",           _emit,            NORMAL },
//   { "environment",    _environment,     NORMAL },
  { "execute",        _execute,         NORMAL },
  { "fill",           _fill,            NORMAL },
  { "find",           _find,            NORMAL },
  { "fm/mod",   _fm_slash_mod,    NORMAL },
  { "here",           _here,            NORMAL },
  { "hold",           _hold,            NORMAL },
  { "i",           _i,        NORMAL }, // added samsuanchen@gmail.com 20190502
  { "if",         _if,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "immediate",      _immediate,       NORMAL },
  { "compile-only",      _compileOnly,       NORMAL },
  { "invert",         _invert,          NORMAL },
  { "j",           _j,        NORMAL }, // added samsuanchen@gmail.com 20190502
//   { "key",            _key,             NORMAL },
  { "leave",          _leave,           IMMEDIATE + COMP_ONLY },
  { "loop",           _loop,            IMMEDIATE + COMP_ONLY },
  { "lshift",         _lshift,          NORMAL },
  { "m*",         _m_star,          NORMAL },
  { "max",            _max,             NORMAL },
  { "min",            _min,             NORMAL },
  { "mod",            _mod,             NORMAL },
  { "move",           _move,            NORMAL },
  { "negate",         _negate,          NORMAL },
  { "nip",            _nip,           NORMAL }, // added samsuanchen@gmail.com 20190515
  { "or",             _or,              NORMAL },
  { "pick",           _pick,            NORMAL }, // added samsuanchen@gmail.com 20190511
  { "postpone",       _postpone,        IMMEDIATE + COMP_ONLY },
  { "quit",           _quit,            NORMAL },
  { "r>",         _r_from,          NORMAL },
  { "r@",        _r_fetch,         NORMAL },
  { "recurse",        _recurse,         IMMEDIATE + COMP_ONLY },
  { "repeat",         _repeat,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "rot",            _rot,             NORMAL },
  { "-rot",           _dash_rot,        NORMAL }, // added samsuanchen@gmail.com 20190606
  { "rshift",         _rshift,          NORMAL },
//   { "s>d",         _s_to_d,          NORMAL },
//   { "sign",           _sign,            NORMAL },
//   { "sm/rem",   _sm_slash_rem,    NORMAL },
  { "source",         _source,          NORMAL }, // uncommented 2018 23 May
  { "space",          _space,           NORMAL },
  { "spaces",         _spaces,          NORMAL },
//   { "state",          _state,           NORMAL },
  { "swap",           _swap,            NORMAL },
  { "then",         _then,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "u.",          _u_dot,           NORMAL },
//   { "u<",           _u_lt,            NORMAL },
//   { "um*",        _um_star,         NORMAL },
//   { "um/mod",   _um_slash_mod,    NORMAL },
//   { "unloop",         _unloop,          NORMAL + COMP_ONLY },
  { "until",         _until,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "while",         _while,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "word",           _word,            NORMAL },
  { "\\", _back_slash,       IMMEDIATE }, // added samsuanchen@gmail.com 20190503
  { "xor",            _xor,             NORMAL },
  { "[",   _left_bracket,    IMMEDIATE },
  { "[']",   _bracket_tick,    IMMEDIATE },
  { "[char]",   _bracket_char,    IMMEDIATE },
  { "]",  _right_bracket,   NORMAL },

#ifdef CORE_EXT_SET
  { ".(",      _dot_paren,       NORMAL },
  { "0<>", _zero_not_equal,  NORMAL },
  { "0>",   _zero_greater,    NORMAL },
  { "2>r",       _two_to_r,        NORMAL },
  { "2r>",     _two_r_from,      NORMAL },
  { "2r@",    _two_r_fetch,     NORMAL },
  { "<>",            _neq,             NORMAL },
  { "hex",            _hex,             NORMAL },
  { "case",           _case,            IMMEDIATE + COMP_ONLY },    // CAL
  { "of",             _of,              IMMEDIATE + COMP_ONLY },    // CAL
  { "endof",          _endof,           IMMEDIATE + COMP_ONLY },    // CAL
  { "endcase",        _endcase,         IMMEDIATE + COMP_ONLY },    // CAL
  { "help",           _help,            NORMAL },
  { "who",            _who,             NORMAL }, // who is this target? dump shows it.
#endif

#ifdef DOUBLE_SET
#endif

#ifdef EXCEPTION_SET
#endif

#ifdef FACILITY_SET
//   { "key?",   _key_question,    NORMAL },
#endif

#ifdef LOCALS_SET
#endif

#ifdef MEMORY_SET
#endif

#ifdef TOOLS_SET
  { ".s",          _dot_s,           NORMAL },
  { "dump",           _dump,            NORMAL },
  { "(see)",           _psee,            NORMAL }, // added samsuanchen@gmail.com 20190503
  { "see",            _see,             NORMAL }, // updated samsuanchen@gmail.com 20190503
  { "words",          _words,           NORMAL },
  { "romEntry",       _romEntry,        NORMAL }, // added samsuanchen@gmail.com 20190503
  { "ramFirst", _ramFirst,        NORMAL }, // added samsuanchen@gmail.com 20190511
  { "ramLast", _ramLast,         NORMAL }, // added samsuanchen@gmail.com 20190503
  { "isRamEntry", _isRamEntry,      NORMAL }, // added samsuanchen@gmail.com 20190514
  { "nextRamEntry", _nextRamEntry,    NORMAL }, // added samsuanchen@gmail.com 20190515
  { ".name", _dot_name,        NORMAL }, // added samsuanchen@gmail.com 20190503
  
#endif

#ifdef SEARCH_SET
#endif

#ifdef STRING_SET
#endif

#ifdef EN_ARDUINO_OPS
//   { "freeMem",        _freeMem,         NORMAL },
  { "delay",          _delay,           NORMAL },
  { "pinWrite",       _pinWrite,        NORMAL },
  { "pinMode",        _pinMode,         NORMAL },
  { "pinRead",        _pinRead,         NORMAL },
  { "analogRead",     _analogRead,      NORMAL },  // ISTR this was defined
  { "analogWrite",    _analogWrite,     NORMAL },
  { ">name",        _to_name,          NORMAL },
#endif
#ifdef EN_EEPROM_OPS
  { "eeRead",         _eeprom_read,     NORMAL },
  { "eeWrite",        _eeprom_write,    NORMAL },
#endif


#ifdef NEO_PIXEL

  { "npx",            _npx,             NORMAL }, // NORMAL  // set npx array index (e.g. 0-9 on CPX)  '4 npx' sets the 5th npx for future write ops incl. 'rgb'
  { "npx@",      _npx_fetch,       NORMAL }, // NORMAL  // fetch npx array index 'npx@ .' prints the current index without disturbing it
  { "rgb",            _rgb,             NORMAL }, // NORMAL  // '0 0 1 rgb' sets blue.  '0 0 0 rgb' makes current npx go dark
  { "pixel",          _pixel,           NORMAL }, // NORMAL  // 'pixel' runs a demo blinking pattern
  { "cblink",         _cblink,          NORMAL }, // NORMAL  // 'cblink' blinks current npx once .. in cyan
                                                               // 3 npx 9 0 9 rgb -- this would select the 4th npx and color it in magenta

#endif // #ifdef NEO_PIXEL

#define SPI_FLASH_SRC
#ifdef SPI_FLASH_SRC

#ifdef HAS_SPI_FLASH_DEMO
    #warning THIS_THING_TRIPS

  { "eflmkdir",       _eflmkdir,        IMMEDIATE + COMP_ONLY },
  { "load",           _load,            NORMAL },
  { "echo!",      _echo_bang,       NORMAL }, 
  { "remove",         _remove,          NORMAL },
  { "download",       _download,        NORMAL },
#endif // #ifdef HAS_SPI_FLASH_DEMO

#ifdef HAS_QSPI_FLASH_DEMO
    #warning THAT_THING_TRIPS
  { "eflmkdir",       _eflmkdir,        IMMEDIATE + COMP_ONLY },
  { "load",           _load,            NORMAL },
  { "echo!",      _echo_bang,       NORMAL }, 
  { "remove",         _remove,          NORMAL },
  { "download",       _download,        NORMAL },
  { "tone",       _tone,        NORMAL },
  { "noTone",       _noTone,        NORMAL },
  { "freq",       _freq,        NORMAL },
  { "isWord",     _isWord,        NORMAL },
  { "setEscPrint",_setEscPrint,NORMAL },
  { "fgYellow",   _fgYellow,   NORMAL },
  { "bgBlue",     _bgBlue,        NORMAL },
  { "fgBlack",   _fgBlack,      NORMAL },
  { "fgRed",   _fgRed,      NORMAL },
  { "fgGreen",   _fgGreen,      NORMAL },
  { "fgYellow",   _fgYellow,      NORMAL },
  { "fgBlue",   _fgBlue,      NORMAL },
  { "fgMagenta",   _fgMagenta,      NORMAL },
  { "fgCyan",   _fgCyan,      NORMAL },
  { "fgWhite",   _fgWhite,      NORMAL },
  { "fgBrightBlack",   _fgBrightBlack,      NORMAL },
  { "fgBrightRed",   _fgBrightRed,      NORMAL },
  { "fgBrightGreen",   _fgBrightGreen,      NORMAL },
  { "fgBrightYellow",   _fgBrightYellow,      NORMAL },
  { "fgBrightBlue",   _fgBrightBlue,      NORMAL },
  { "fgBrightMagenta",   _fgBrightMagenta,      NORMAL },
  { "fgBrightCyan",   _fgBrightCyan,      NORMAL },
  { "fgBrightWhite",   _fgBrightWhite,      NORMAL },
  { "bgBlack",   _bgBlack,      NORMAL },
  { "bgRed",   _bgRed,      NORMAL },
  { "bgGreen",   _bgGreen,      NORMAL },
  { "bgYellow",   _bgYellow,      NORMAL },
  { "bgBlue",   _bgBlue,      NORMAL },
  { "bgMagenta",   _bgMagenta,      NORMAL },
  { "bgCyan",   _bgCyan,      NORMAL },
  { "bgWhite",   _bgWhite,      NORMAL },
  { "bgBrightBlack",   _bgBrightBlack,      NORMAL },
  { "bgBrightRed",   _bgBrightRed,      NORMAL },
  { "bgBrightGreen",   _bgBrightGreen,      NORMAL },
  { "bgBrightYellow",   _bgBrightYellow,      NORMAL },
  { "bgBrightBlue",   _bgBrightBlue,      NORMAL },
  { "bgBrightMagenta",   _bgBrightMagenta,      NORMAL },
  { "bgBrightCyan",   _bgBrightCyan,      NORMAL },
  { "bgBrightWhite",   _bgBrightWhite,      NORMAL },

  { "context",    _context,     NORMAL },
  { "current",    _current,     NORMAL },
  { "definitions",   _definitions,    NORMAL },
  { "vocs",      _vocs,     NORMAL },
  { "lastVoc",      _lastVoc,     NORMAL },
  { "also",       _also,        NORMAL },
  { "previous",   _previous,    NORMAL },
  { "order",   _order,    NORMAL },
  { "primitive",   _primitive,    NORMAL },
  { "nRomWords",   _nRomWords,    NORMAL },
  { "addrToSee",   _addrToSee,    NORMAL },
  { "isUserEntry", _isUserEntry,  NORMAL },
  

#endif // #ifdef HAS_QSPI_FLASH_DEMO

#endif // #ifdef SPI_FLASH_SRC

#ifdef QSPI_FLASHROM
#ifdef HAS_QSPI_FLASHROM_LIB

// { ffmt_str,           _ffmt,            NORMAL }, // flash format

#endif // HAS_QSPI_FLASHROM_LIB
#endif // QSPI_FLASHROM


  { NULL,           NULL,    NORMAL }
};


/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
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

