#include <Arduino.h>
#include "yaffa.h"
#include "error_codes.h"

#include "b_flashDict.h"

#include "dictionary.h"
#include "src/dict/new_dict_entries.h" // #include "src/dict/dict_entries.h" // 21 June 2018


/*********************************************************************************/
/**   'static void _foo(void)'  -- conflicts with 'extern void'                 **/
/*********************************************************************************/


/*********************************************************************************/
/**                         Dictionary Initialization                           **/
/*********************************************************************************/

const flashEntry_t DLflashDict[] = {
  { dl_ends_str,        _dl_ends,         NORMAL },
  { NULL,               NULL,             NORMAL }
};

/**                         Dictionary Initialization                           **/
const flashEntry_t flashDict[] = {
  /*****************************************************/
  /* The initial entries must stay in this order so    */
  /* they always have the same index. They get called  */
  /* referenced when compiling code                    */
  /*****************************************************/
  { "exit",        _exit,          NORMAL }, // 01
  { "literal",      _literal,       IMMEDIATE }, // 02
  { "type",       _type,          NORMAL }, // 03
  { "bran",       _jump,          SMUDGE }, // 04
  { "zbran",      _zjump,         SMUDGE }, // 05
  { "(does>)",      _subroutine,      SMUDGE }, // 06
  { "throw",      _throw,         NORMAL }, // 07
  { "(do)",       _do_sys,        SMUDGE }, // 08
  { "(loop)",     _loop_sys,        SMUDGE }, // 09
  { "(leave)",      _leave_sys,       SMUDGE }, // 10
  { "(+loop)",      _plus_loop_sys,     SMUDGE }, // 11
  { "evaluate",     _evaluate,        NORMAL }, // 12
  { "s\"",        _s_quote,       IMMEDIATE + COMP_ONLY }, // 13
  { ".\"",        _dot_quote,       IMMEDIATE + COMP_ONLY }, // 14
  { "(var)",      _var_sys,       NORMAL }, // 15 // samsuanchen@gmail.com 20190508
  { "over",       _over,          NORMAL }, // 16 // CAL
  { "=",        _eq,          NORMAL }, // 17 // CAL
  { "drop",       _drop,          NORMAL }, // 18 // CAL
  { "(con)",      _con_sys,       NORMAL }, // 19 // samsuanchen@gmail.com 20190508
  { "variable",     _variable,        NORMAL }, // 20 // moved to here samsuanchen@gmail.com 20190508
  { "(voc)",      _voc_sys,       NORMAL }, // 21 // samsuanchen@gmail.com 20190603
  { "vocabulary",   _vocabulary,      NORMAL }, // 22 // samsuanchen@gmail.com 20190603
  { "'",        _tick,          NORMAL }, // added samsuanchen@gmail.com 20190502
  { "-",        _minus,         NORMAL },
  { "-rot",       _dash_rot,        NORMAL }, // added samsuanchen@gmail.com 20190606
  { "!",        _store,         NORMAL },
  { "#",        _number_sign,     NORMAL }, // added samsuanchen@gmail.com 20190510
  { "#>",       _number_sign_gt,    NORMAL }, // added samsuanchen@gmail.com 20190510
  { "#s",       _number_sign_s,     NORMAL }, // added samsuanchen@gmail.com 20190510
  { "(",        _paren,         IMMEDIATE }, // samsuanchen@gmail.com 20190503
  { "(see)",      _psee,          NORMAL }, // added samsuanchen@gmail.com 20190503
  { "*",        _star,          NORMAL },
  { "*/",       _star_slash,      NORMAL },
  { "*/mod",      _star_slash_mod,    NORMAL },
  { ",",        _comma,         NORMAL },
  { ".",        _dot,         NORMAL },
  { ".(",       _dot_paren,       NORMAL },
  { ".0r",        _dot_0r,        NORMAL },
  { ".name",      _dot_name,        NORMAL }, // added samsuanchen@gmail.com 20190503
  { ".r",       _dot_r,         NORMAL },
  { ".s",       _dot_s,         NORMAL },
  { "/",        _slash,         NORMAL },
  { "/mod",       _slash_mod,       NORMAL }, // samsuanchen@gmail.com 20190521
  { ":",        _colon,         NORMAL },
  { ";",        _semicolon,       IMMEDIATE },
  { "?",        _quest,         NORMAL },
  { "?dup",       _question_dup,      NORMAL },
  { "@",        _fetch,         NORMAL },
  { "[']",        _bracket_tick,      IMMEDIATE },
  { "[",        _left_bracket,      IMMEDIATE },
  { "[char]",     _bracket_char,      IMMEDIATE },
  { "\\",       _back_slash,      IMMEDIATE }, // added samsuanchen@gmail.com 20190503
  { "]",        _right_bracket,     NORMAL },
  { "+!",       _plus_store,      NORMAL },
  { "+",        _plus,          NORMAL },
  { "+loop",      _plus_loop,       IMMEDIATE + COMP_ONLY },
  { "<",        _lt,          NORMAL }, // samsuanchen@gmail.com 20190502
  { "<#",       _lt_number_sign,    NORMAL }, // samsuanchen@gmail.com 20190510
  { "<=",       _less_equal,      NORMAL },
  { "<>",       _neq,         NORMAL },
  { ">",        _gt,          NORMAL }, // samsuanchen@gmail.com 20190515
  { ">=",       _greater_equal,     NORMAL },
  { ">body",      _to_body,       NORMAL },
  { ">flags",     _to_flags,        NORMAL },
  { ">in",        _to_in,         NORMAL },
  { ">name",      _to_name,       NORMAL },
  { ">number",      _to_number,       NORMAL },
  { ">r",       _to_r,          NORMAL },
  { "0",        _zero,          NORMAL },
  { "0<",       _zero_less,       NORMAL }, // samsuanchen@gmail.com 20190521
  { "0<=",        _zero_less_equal,   NORMAL },
  { "0<>",        _zero_not_equal,    NORMAL },
  { "0=",       _zero_equal,      NORMAL },
  { "0>",       _zero_greater,      NORMAL },
  { "0>=",        _zero_greater_equal,  NORMAL },
  { "1-",       _one_minus,       NORMAL },
  { "1",        _one,         NORMAL },
  { "1+",       _one_plus,        NORMAL },
  { "2-",       _two_minus,       NORMAL },
  { "2!",       _two_store,       NORMAL },
  { "2",        _two,         NORMAL },
  { "2*",       _two_star,        NORMAL },
  { "2/",       _two_slash,       NORMAL }, // samsuanchen@gmail.com 20190515
  { "2@",       _two_fetch,       NORMAL },
  { "2+",       _two_plus,        NORMAL },
  { "2>r",        _two_to_r,        NORMAL },
  { "2drop",      _two_drop,        NORMAL },
  { "2dup",       _two_dup,       NORMAL }, // samsuanchen@gmail.com 20190515
  { "2over",      _two_over,        NORMAL }, // samsuanchen@gmail.com 20190515
  { "2r@",        _two_r_fetch,     NORMAL },
  { "2r>",        _two_r_from,      NORMAL },
  { "2swap",      _two_swap,        NORMAL }, // samsuanchen@gmail.com 20190515
  { "3",        _three,         NORMAL },
  { "4",        _four,          NORMAL },
  { "abort",      _abort,         NORMAL },
  { "abort\"",      _abort_quote,     IMMEDIATE + COMP_ONLY },
  { "abs",        _abs,         NORMAL },
  { "accept",     _accept,        NORMAL },
  { "addrToSee",    _addrToSee,       NORMAL },
  { "again",      _again,         IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "allot",      _allot,         NORMAL },
  { "also",       _also,          NORMAL },
  { "analogRead",   _analogRead,      NORMAL },  // ISTR this was defined
  { "analogWrite",    _analogWrite,     NORMAL },
  { "and",        _and,         NORMAL },
  { "base",       _base,          NORMAL },
  { "begin",      _begin,         IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "bgBlack",      _bgBlack,       NORMAL },
  { "bgBlue",     _bgBlue,        NORMAL },
  { "bgBlue",     _bgBlue,        NORMAL },
  { "bgBrightBlack",  _bgBrightBlack,     NORMAL },
  { "bgBrightBlue",   _bgBrightBlue,      NORMAL },
  { "bgBrightCyan",   _bgBrightCyan,      NORMAL },
  { "bgBrightGreen",  _bgBrightGreen,     NORMAL },
  { "bgBrightMagenta",  _bgBrightMagenta,   NORMAL },
  { "bgBrightRed",    _bgBrightRed,     NORMAL },
  { "bgBrightWhite",  _bgBrightWhite,     NORMAL },
  { "bgBrightYellow", _bgBrightYellow,    NORMAL },
  { "bgCyan",     _bgCyan,        NORMAL },
  { "bgGreen",      _bgGreen,       NORMAL },
  { "bgMagenta",    _bgMagenta,       NORMAL },
  { "bgRed",      _bgRed,         NORMAL },
  { "bgWhite",      _bgWhite,       NORMAL },
  { "bgYellow",     _bgYellow,        NORMAL },
  { "bl",       _bl,          NORMAL },
  { "c!",       _c_store,       NORMAL },
  { "c,",       _c_comma,       NORMAL },
  { "c@",       _c_fetch,       NORMAL },
  { "case",       _case,          IMMEDIATE + COMP_ONLY },    // CAL
  { "cblink",     _cblink,        NORMAL }, // NORMAL  // 'cblink' blinks current npx once .. in cyan
  { "cell-",      _cell_minus,      NORMAL },
  { "cell/",      _cell_div,        NORMAL },
  { "cell+",      _cell_plus,       NORMAL },
  { "cells",      _cells,         NORMAL },
  { "char",       _char,          NORMAL },
  { "char+",      _char_plus,       NORMAL },
  { "chars",      _chars,         NORMAL },
  { "compile-only",   _compileOnly,     NORMAL },
  { "constant",     _constant,        NORMAL },
  { "context",      _context,       NORMAL },
  { "count",      _count,         NORMAL }, // updated samsuanchen@gmail.com 20190502
  { "cr",       _cr,          NORMAL },
  { "create",     _create,        NORMAL },
  { "current",      _current,       NORMAL },
  { "decimal",      _decimal,       NORMAL },
  { "definitions",    _definitions,     NORMAL },
  { "delay",      _delay,         NORMAL },
  { "depth",      _depth,         NORMAL },
  { "do",       _do,          IMMEDIATE + COMP_ONLY },
  { "does>",      _does,          IMMEDIATE + COMP_ONLY }, // modified samsuanchen@gmail.com 20190521
  { "download",     _download,        NORMAL },
  { "dump",       _dump,          NORMAL },
  { "dup",        _dupe,          NORMAL },
  { "echo!",      _echo_bang,       NORMAL }, 
//{ "eeRead",     _eeprom_read,     NORMAL },
//{ "eeWrite",      _eeprom_write,      NORMAL },
  { "eflmkdir",     _eflmkdir,        IMMEDIATE + COMP_ONLY },
  { "else",       _else,          IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "emit",       _emit,          NORMAL },
  { "endcase",      _endcase,       IMMEDIATE + COMP_ONLY },    // CAL
  { "endof",      _endof,         IMMEDIATE + COMP_ONLY },    // CAL
  { "execute",      _execute,       NORMAL },
  { "false",      _false,         NORMAL },
  { "fgBlack",      _fgBlack,       NORMAL },
  { "fgBlue",     _fgBlue,        NORMAL },
  { "fgBrightBlack",  _fgBrightBlack,     NORMAL },
  { "fgBrightBlue",   _fgBrightBlue,      NORMAL },
  { "fgBrightCyan",   _fgBrightCyan,      NORMAL },
  { "fgBrightGreen",  _fgBrightGreen,     NORMAL },
  { "fgBrightMagenta",  _fgBrightMagenta,   NORMAL },
  { "fgBrightRed",    _fgBrightRed,     NORMAL },
  { "fgBrightWhite",  _fgBrightWhite,     NORMAL },
  { "fgBrightYellow", _fgBrightYellow,    NORMAL },
  { "fgCyan",     _fgCyan,        NORMAL },
  { "fgGreen",      _fgGreen,       NORMAL },
  { "fgMagenta",    _fgMagenta,       NORMAL },
  { "fgRed",      _fgRed,         NORMAL },
  { "fgWhite",      _fgWhite,       NORMAL },
  { "fgYellow",     _fgYellow,        NORMAL },
  { "fgYellow",     _fgYellow,        NORMAL },
  { "fill",       _fill,          NORMAL },
  { "find",       _find,          NORMAL },
  { "findFirst",    _findFirst,       NORMAL },
  { "fm/mod",     _fm_slash_mod,      NORMAL },
  { "freeMem",      _freeMem,       NORMAL },
  { "freq",       _freq,          NORMAL },
  { "h.",       _h_dot,         NORMAL },
  { "h.0r",       _h_dot_0r,        NORMAL },
  { "h.r",        _h_dot_r,       NORMAL },
  { "h8.",        _h8_dot,        NORMAL },
  { "help",       _help,          NORMAL },
  { "here",       _here,          NORMAL },
  { "hex",        _hex,         NORMAL },
  { "hold",       _hold,          NORMAL },
  { "i",        _i,           NORMAL }, // added samsuanchen@gmail.com 20190502
  { "if",       _if,          IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "immediate",    _immediate,       NORMAL },
  { "invert",     _invert,        NORMAL },
  { "isRamEntry",   _isRamEntry,      NORMAL }, // added samsuanchen@gmail.com 20190514
  { "isUserEntry",    _isUserEntry,     NORMAL },
  { "isWord",     _isWord,        NORMAL },
  { "j",        _j,           NORMAL }, // added samsuanchen@gmail.com 20190502
  { "lastVoc",      _lastVoc,       NORMAL },
  { "leave",      _leave,         IMMEDIATE + COMP_ONLY },
  { "load",       _load,          NORMAL },
  { "loop",       _loop,          IMMEDIATE + COMP_ONLY },
  { "lshift",     _lshift,        NORMAL },
  { "m*",       _m_star,        NORMAL },
  { "max",        _max,         NORMAL },
  { "min",        _min,         NORMAL },
  { "mod",        _mod,         NORMAL },
  { "move",       _move,          NORMAL },
  { "nContext",     _nContext,        NORMAL },
  { "negate",     _negate,        NORMAL },
  { "nextRamEntry",   _nextRamEntry,      NORMAL }, // added samsuanchen@gmail.com 20190515
  { "nip",        _nip,         NORMAL }, // added samsuanchen@gmail.com 20190515
  { "nop",        _nop,         NORMAL }, // 22 June 2018
  { "noTone",     _noTone,        NORMAL },
//{ "npx",        _npx,         NORMAL }, // NORMAL  // set npx array index (e.g. 0-9 on CPX)  '4 npx' sets the 5th npx for future write ops incl. 'rgb'
//{ "npx@",       _npx_fetch,       NORMAL }, // NORMAL  // fetch npx array index 'npx@ .' prints the current index without disturbing it
  { "nRomWords",    _nRomWords,       NORMAL },
  { "of",       _of,          IMMEDIATE + COMP_ONLY },    // CAL
  { "or",       _or,          NORMAL },
  { "order",      _order,         NORMAL },
  { "(forget)",   _pForget,       NORMAL },
  { "pHere",      _pHere,         NORMAL },
  { "pick",       _pick,          NORMAL }, // added samsuanchen@gmail.com 20190511
  { "pinMode",      _pinMode,       NORMAL },
  { "pinRead",      _pinRead,       NORMAL },
  { "pinWrite",     _pinWrite,        NORMAL },
//{ "pixel",      _pixel,         NORMAL }, // NORMAL  // 'pixel' runs a demo blinking pattern
  { "postpone",     _postpone,        IMMEDIATE + COMP_ONLY },
  { "previous",     _previous,        NORMAL },
  { "primitive",    _primitive,       NORMAL },
  { "print",      _print,         NORMAL },
  { "quit",       _quit,          NORMAL },
  { "r@",       _r_fetch,       NORMAL },
  { "r>",       _r_from,        NORMAL },
  { "ramFirst",     _ramFirst,        NORMAL }, // added samsuanchen@gmail.com 20190511
  { "ramLast",      _ramLast,       NORMAL }, // added samsuanchen@gmail.com 20190503
  { "recurse",      _recurse,       IMMEDIATE + COMP_ONLY },
  { "remove",     _remove,        NORMAL },
  { "repeat",     _repeat,        IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
//{ "rgb",        _rgb,         NORMAL }, // NORMAL  // '0 0 1 rgb' sets blue.  '0 0 0 rgb' makes current npx go dark
  { "romEntry",     _romEntry,        NORMAL }, // added samsuanchen@gmail.com 20190503
  { "rot",        _rot,         NORMAL },
  { "rshift",     _rshift,        NORMAL },
  { "see",        _see,         NORMAL }, // updated samsuanchen@gmail.com 20190503
  { "setEscPrint",    _setEscPrint,     NORMAL },
  { "source",     _source,        NORMAL }, // uncommented 2018 23 May
  { "space",      _space,         NORMAL },
  { "spaces",     _spaces,        NORMAL },
  { "strlen",     _strlen,        NORMAL }, // added samsuanchen@gmail.com 20190502
  { "swap",       _swap,          NORMAL },
  { "then",       _then,          IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "tone",       _tone,          NORMAL },
  { "true",       _true,          NORMAL },
  { "u.",       _u_dot,         NORMAL },
  { "until",      _until,         IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "vocs",       _vocs,          NORMAL },
  { "warm",       _warm,          NORMAL },
  { "while",      _while,         IMMEDIATE + COMP_ONLY }, // added samsuanchen@gmail.com 20190502
  { "who",        _who,         NORMAL }, // who is this target? dump shows it.
  { "word",       _word,          NORMAL },
  { "words",      _words,         NORMAL },
  { "xor",        _xor,         NORMAL },
//{ "align",      _align,         NORMAL },
//{ "aligned",      _aligned,       NORMAL },
//{ "environment",    _environment,     NORMAL },
//{ "key",        _key,         NORMAL },
//{ "key?",       _key_question,      NORMAL },
//{ "s>d",        _s_to_d,        NORMAL },
//{ "sign",       _sign,          NORMAL },
//{ "sm/rem",     _sm_slash_rem,      NORMAL },
//{ "state",      _state,         NORMAL },
//{ "u<",       _u_lt,          NORMAL },
//{ "um*",        _um_star,       NORMAL },
//{ "um/mod",     _um_slash_mod,      NORMAL },
//{ "unloop",     _unloop,        NORMAL + COMP_ONLY },
  { NULL,           NULL,    NORMAL }
};
