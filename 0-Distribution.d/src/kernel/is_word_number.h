// Sun Jun 18 02:05:55 UTC 2017
// 4735-a0k

#ifdef EXT_KERN_IS_WORD_NUMBER // may need this guard
const char charset[] = "0123456789abcdefghijklmnopqrstvuwxyz"; // samsuanchen@gmail.com 20190510
#endif

// prototypes - these words
extern uint32_t isWord(char* addr); // samsuanchen@gmail.com 20190502
extern uint8_t isNumber(char* subString);
extern void _isWord(void);

// prototypes - variables
extern userEntry_t* pLastUserEntry; // = NULL;
extern userEntry_t* pUserEntry; // = NULL;
extern uint8_t wordFlags;             // Word flags
extern cell_t w;     // Working Register
extern uint8_t base;  // stores the number conversion radix

// prototypes - external functions
extern void dStack_push(cell_t);
extern cell_t dStack_pop(void);

