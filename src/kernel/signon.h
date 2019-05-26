// Tue Jun 20 21:33:06 UTC 2017
// 4735-a0p-02-

// external const
extern const flashEntry_t* pFlashEntry; // = flashDict;   // Pointer into the flash Dictionary
extern char cTokenBuffer[WORD_SIZE];
uint8_t getToken(void);
extern void dStack_push(cell_t); 
extern void _throw(void);
// prototypes - this word
extern void signOn(void);
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
// prototypes - variables
extern cell_t w;     // Working Register

