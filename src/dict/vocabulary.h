// Sun Jun 25 03:24:01 UTC 2017
// 4735-a0r-04-

// external const

// prototypes - this word
extern void _vocabulary(void);
extern void _voc_sys(void);

// prototypes - variables
extern uint8_t nContext;
extern cell_t* context[8];
extern cell_t* current;
extern cell_t* pLastVoc;
extern cell_t* ip;
extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space

// prototypes - external functions
extern void dStack_push(cell_t);
extern void _exit(void);
extern void openEntry(void);
extern void closeEntry(void);
extern cell_t dStack_pop(void);

