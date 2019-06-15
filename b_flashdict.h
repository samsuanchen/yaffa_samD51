// Mon Jan 15 18:14:33 UTC 2018
// 4737-a0d-05c-

// version bump

// Thu Aug  3 01:46:56 UTC 2017
// 4735-b0d-00-

extern cell_t dStack_pop(void);
extern const flashEntry_t* pFlashEntry; // = flashDict;      the main forth vocabulary
extern const flashEntry_t* pDLFlashEntry; // = DLflashDict;  the download vocabulary
extern cell_t* pHere;
extern void signOn(void);
extern cell_t* lastVoc;

extern void _dot_s(void);
extern void _isWord(void);
extern void _setEscPrint(void);
extern void _fgBlack(void);
extern void _fgRed(void);
extern void _fgGreen(void);
extern void _fgYellow(void);
extern void _fgBlue(void);
extern void _fgMagenta(void);
extern void _fgCyan(void);
extern void _fgWhite(void);
extern void _fgBrightBlack(void);
extern void _fgBrightRed(void);
extern void _fgBrightGreen(void);
extern void _fgBrightYellow(void);
extern void _fgBrightBlue(void);
extern void _fgBrightMagenta(void);
extern void _fgBrightCyan(void);
extern void _fgBrightWhite(void);
extern void _bgBlack(void);
extern void _bgRed(void);
extern void _bgGreen(void);
extern void _bgYellow(void);
extern void _bgBlue(void);
extern void _bgMagenta(void);
extern void _bgCyan(void);
extern void _bgWhite(void);
extern void _bgBrightBlack(void);
extern void _bgBrightRed(void);
extern void _bgBrightGreen(void);
extern void _bgBrightYellow(void);
extern void _bgBrightBlue(void);
extern void _bgBrightMagenta(void);
extern void _bgBrightCyan(void);
extern void _bgBrightWhite(void);

extern void _zero_not_equal(void);
extern void _zero_greater(void);
extern void _two_to_r(void);
extern void _two_r_from(void);
extern void _two_r_fetch(void);
extern void _neq(void);
extern void _case(void);
extern void _of(void);
extern void _endof(void);
extern void _endcase(void);
extern void _to_in(void);
extern void _to_number(void);
extern void _immediate(void);
extern void _compileOnly(void);
extern void _invert(void);
extern void _lshift(void);
extern void _m_star(void);
extern void _postpone(void);
extern void _recurse(void);
extern void _rshift(void);
extern void _context(void);
extern void _current(void);
extern void _defitions(void);
extern void _voc_sys(void);
extern void _vocabulary(void);
extern void _lastVoc(void);
extern void _vocs(void);
extern void _also(void);
extern void _previous(void);
extern void _order(void);
extern void _dash_rot(void);
extern void _nRomWords(void);
extern void _addrToSee(void);
extern void _isUserEntry(void);
extern void _to_flags(void);
extern void _h8_dot(void);
extern void _h_dot(void);
extern void _dot_r(void);
extern void _h_dot_r(void);
extern void _dot_0r(void);
extern void _h_dot_0r(void);
extern void _zero_less_equal(void);
extern void _less_equal(void);
extern void _zero_greater_equal(void);
extern void _greater_equal(void);
extern void _quest(void);
extern void _findFirst(void);
