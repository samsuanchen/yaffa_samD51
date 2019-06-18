// Fri 22 Jun 18:03:52 UTC 2018
// 4737-a3b-005-

// Thu 21 Jun 22:17:21 UTC 2018
// 4737-a3b-001-  +dict_comments_only.cpp file

// Sat Jul 29 18:14:02 UTC 2017
// 4735-b0b-01-

// count word evaluate : ; c, here 

extern uint16_t nFlashEntry;
extern flashEntry_t* pLimitFlashEntry;
extern userEntry_t* pUserEntry;
extern userEntry_t* pFirstUserEntry;
extern userEntry_t* pLastUserEntry;
extern char* to_name(cell_t);
extern uint8_t outLen;
extern cell_t* context[];
extern cell_t* current;
extern uint8_t nContext;
extern int8_t iContext;
extern cell_t* pLastVoc;
extern cell_t* pCodeStart;
extern uint32_t isWord(char* addr, uint8_t n);
extern void endEntry();
extern cell_t* pDoes;
extern cell_t dStack_top();
extern void dStack_top(cell_t);
extern char cInputBuffer[BUFFER_SIZE]; // Input Buffer that gets parsed
extern void _bgBlue();
extern void _bgBlack();
extern void _fgRed();
extern void _fgWhite();
extern unsigned int freeMem();
extern void _throw( cell_t errorCode, char* message );
extern cell_t* firstUserEntry;
extern char* to_name(cell_t xt);

// extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

//#if defined(INCL_NOP_WORD) || defined(XDICT)
// extern const char nop_str[]; // = "nop";
extern void _nop();
//#endif // #if defined(INCL_NOP_WORD) || defined(XDICT)

// extern const char here_str[]; // = "here";
extern void _here(); // here ( -- here )
extern void _count(); // count ( cStr -- str u )
extern void _evaluate();
extern void _word(); // word ( delimiter -- cStr )
extern void _source(); // source ( -- str u )

extern void _pinWrite();
extern void _pinMode();
extern void _pinRead();

extern void _strlen();			//samsuanchen@gmail.com 20190502
extern void _i();				//samsuanchen@gmail.com 20190502
extern void _j();				//samsuanchen@gmail.com 20190502
extern void _lt();				//samsuanchen@gmail.com 20190502
extern void _colon();			//samsuanchen@gmail.com 20190502
extern void _semicolon();		//samsuanchen@gmail.com 20190502
extern void _if();				//samsuanchen@gmail.com 20190502
extern void _else();			//samsuanchen@gmail.com 20190502
extern void _then(); 			//samsuanchen@gmail.com 20190502
extern void _begin();			//samsuanchen@gmail.com 20190502
extern void _again();			//samsuanchen@gmail.com 20190502
extern void _until();			//samsuanchen@gmail.com 20190502
extern void _while();			//samsuanchen@gmail.com 20190502
extern void _repeat();			//samsuanchen@gmail.com 20190502
extern void _back_slash();		//samsuanchen@gmail.com 20190502
extern void _psee();			//samsuanchen@gmail.com 20190502
extern void _see();				//samsuanchen@gmail.com 20190502

extern char* pPNO;				//samsuanchen@gmail.com 20190510
extern void _comma();			//samsuanchen@gmail.com 20190510
extern void _two_drop();		//samsuanchen@gmail.com 20190510
extern void _base();			//samsuanchen@gmail.com 20190510
extern void _hold();			//samsuanchen@gmail.com 20190510
extern void _lt_number_sign();	//samsuanchen@gmail.com 20190510
extern void _number_sign();		//samsuanchen@gmail.com 20190510
extern void _number_sign_s();	//samsuanchen@gmail.com 20190510
extern void _number_sign_gt();	//samsuanchen@gmail.com 20190510

extern void _tick();			//samsuanchen@gmail.com 20190514
extern void _true();			//samsuanchen@gmail.com 20190514
extern void _false();			//samsuanchen@gmail.com 20190514
extern void _zero();			//samsuanchen@gmail.com 20190514
extern void _one();				//samsuanchen@gmail.com 20190514
extern void _two();				//samsuanchen@gmail.com 20190514
extern void _three();			//samsuanchen@gmail.com 20190514
extern void _four();			//samsuanchen@gmail.com 20190514
extern void _char_plus();		//samsuanchen@gmail.com 20190514
extern void _chars();			//samsuanchen@gmail.com 20190514
extern void _one_plus();		//samsuanchen@gmail.com 20190514
extern void _one_minus();		//samsuanchen@gmail.com 20190514
extern void _two_plus();		//samsuanchen@gmail.com 20190514
extern void _two_minus();		//samsuanchen@gmail.com 20190514
extern void _two_star();		//samsuanchen@gmail.com 20190514
extern void _bl();				//samsuanchen@gmail.com 20190514
extern void _cell_plus();		//samsuanchen@gmail.com 20190514
extern void _cell_minus();		//samsuanchen@gmail.com 20190514
extern void _cells();			//samsuanchen@gmail.com 20190514
extern void _cell_div();		//samsuanchen@gmail.com 20190514

extern void _question_dup();	//samsuanchen@gmail.com 20190515
extern void _depth();			//samsuanchen@gmail.com 20190515
extern void _nip();				//samsuanchen@gmail.com 20190515
extern void _two_slash();		//samsuanchen@gmail.com 20190515
extern void _two_dup();			//samsuanchen@gmail.com 20190515
extern void _two_over();		//samsuanchen@gmail.com 20190515
extern void _two_swap();		//samsuanchen@gmail.com 20190515
extern void _gt();				//samsuanchen@gmail.com 20190515
extern void _execute();			//samsuanchen@gmail.com 20190515

extern void _leave();			//samsuanchen@gmail.com 20190516
extern void _abort();			//samsuanchen@gmail.com 20190516
extern void _abort_quote();		//samsuanchen@gmail.com 20190516
extern void _eeprom_read();		//samsuanchen@gmail.com 20190516
extern void _eeprom_write();	//samsuanchen@gmail.com 20190516
extern void _to_name();			//samsuanchen@gmail.com 20190516
extern void _analogRead();		//samsuanchen@gmail.com 20190516
extern void _analogWrite();		//samsuanchen@gmail.com 20190516
extern void _tone();			//samsuanchen@gmail.com 20190520
extern void _noTone();			//samsuanchen@gmail.com 20190520
extern void _freq();			//samsuanchen@gmail.com 20190520
extern void _mod();				//samsuanchen@gmail.com 20190520

extern void _bracket_char();	//samsuanchen@gmail.com 20190521
extern void _bracket_tick();	//samsuanchen@gmail.com 20190521
extern void _create();			//samsuanchen@gmail.com 20190521
extern void _does();			//samsuanchen@gmail.com 20190521
extern cell_t* pNewDoes;		//samsuanchen@gmail.com 20190521
extern void _left_bracket();	//samsuanchen@gmail.com 20190521
extern void _right_bracket();	//samsuanchen@gmail.com 20190521
extern void _find();			//samsuanchen@gmail.com 20190521 fixed
extern void _star_slash();		//samsuanchen@gmail.com 20190521
extern void _star_slash_mod();	//samsuanchen@gmail.com 20190521
extern void _plus_loop();		//samsuanchen@gmail.com 20190521
extern void _slash_mod();		//samsuanchen@gmail.com 20190521
extern void _zero_less();		//samsuanchen@gmail.com 20190521
extern void _to_body();			//samsuanchen@gmail.com 20190521

extern void _zero_not_equal();	//samsuanchen@gmail.com 20190525
extern void _zero_greater();	//samsuanchen@gmail.com 20190525
extern void _two_to_r();		//samsuanchen@gmail.com 20190525
extern void _two_r_from();		//samsuanchen@gmail.com 20190525
extern void _two_r_fetch();		//samsuanchen@gmail.com 20190525
extern void _neq();				//samsuanchen@gmail.com 20190525
extern void _case();			//samsuanchen@gmail.com 20190525
extern void _of();				//samsuanchen@gmail.com 20190525
extern void _endof();			//samsuanchen@gmail.com 20190525
extern void _endcase();			//samsuanchen@gmail.com 20190525

extern void _fm_slash_mod();	//samsuanchen@gmail.com 20190601
extern void _immediate();		//samsuanchen@gmail.com 20190601
extern void _compileOnly();		//samsuanchen@gmail.com 20190601
extern void _invert();			//samsuanchen@gmail.com 20190601
extern void _fm_slash_mod();	//samsuanchen@gmail.com 20190601
extern void _lshift();			//samsuanchen@gmail.com 20190601
extern void _m_star();			//samsuanchen@gmail.com 20190601
extern void _move();			//samsuanchen@gmail.com 20190601
extern void _postpone();		//samsuanchen@gmail.com 20190601
extern void _recurse();			//samsuanchen@gmail.com 20190601
extern void _rshift();			//samsuanchen@gmail.com 20190601

extern void _lastVoc();			//samsuanchen@gmail.com 20190604
extern void _vocs();			//samsuanchen@gmail.com 20190604
extern void _context();			//samsuanchen@gmail.com 20190604
extern void _current();			//samsuanchen@gmail.com 20190604
extern void _definitions();		//samsuanchen@gmail.com 20190604
extern void _voc_sys();			//samsuanchen@gmail.com 20190604
extern void _vocabulary();		//samsuanchen@gmail.com 20190604
extern void _also();			//samsuanchen@gmail.com 20190604
extern void _previous();		//samsuanchen@gmail.com 20190604
extern void _order();			//samsuanchen@gmail.com 20190604
extern void _primitive();		//samsuanchen@gmail.com 20190604

extern void _dash_rot();		//samsuanchen@gmail.com 20190606
extern void _nRomWords();		//samsuanchen@gmail.com 20190609
extern void _addrToSee();		//samsuanchen@gmail.com 20190609
extern void _isUserEntry();		//samsuanchen@gmail.com 20190610

extern void _findFirst();		//samsuanchen@gmail.com 20190615
extern void _freeMem();			//samsuanchen@gmail.com 20190615
extern void _pHere();			//samsuanchen@gmail.com 20190615

extern void _pForget(void);		//samsuanchen@gmail.com 20190617