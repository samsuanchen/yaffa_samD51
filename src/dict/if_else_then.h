// samsuanchen@gmail.com 20190502

extern const char if_str[]; // = "if";
extern void _if(void);

extern const char else_str[]; // = "else";
extern void _else(void);

extern const char then_str[]; // = "then";
extern void _then(void);

extern cell_t* pHere;               // HERE, points to the next free position in
                                    // Forth Space
extern void dStack_push(cell_t value);
extern cell_t dStack_pop(void);
extern void _throw(void);

/******************************************************************************/
/**  YAFFA - Yet Another Forth for Arduino                                   **/
/**                                                                          **/
/**  File: Dictionary.ino                                                    **/
/**  Copyright (C) 2012 Stuart Wood (swood@rochester.rr.com)                 **/
/******************************************************************************/
