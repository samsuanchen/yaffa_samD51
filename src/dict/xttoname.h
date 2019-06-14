// Wed Jun 21 20:55:05 UTC 2017
// 4735-a0p-03-

extern uint16_t nFlashEntry;
extern uint8_t outLen;

extern void dot_name(cell_t xt);
extern char* to_name(cell_t xt);
extern uint8_t to_flags(cell_t xt);

extern cell_t dStack_pop();

extern void _dot_name();
extern void _to_name();
extern void _to_flags();