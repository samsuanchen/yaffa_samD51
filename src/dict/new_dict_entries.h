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
extern void endEntry(void);
extern cell_t* pDoes;
extern cell_t dStack_top(void);
extern void dStack_top(cell_t);
extern char cInputBuffer[BUFFER_SIZE]; // Input Buffer that gets parsed
extern void _bgBlue();
extern void _bgBlack();
extern void _fgRed();
extern void _fgWhite();

// extern char cTokenBuffer[WORD_SIZE];  // Stores Single Parsed token to be acted on

#if defined(INCL_NOP_WORD) || defined(XDICT)
// extern const char nop_str[]; // = "nop";
extern void _nop(void);
#endif // #if defined(INCL_NOP_WORD) || defined(XDICT)

// extern const char here_str[]; // = "here";
extern void _here(void);


// extern const char count_str[]; // = "count";
extern void _count(void);

// extern const char evaluate_str[]; // = "evaluate";
extern void _evaluate(void);

// extern const char word_str[]; // = "word";
extern void _word(void);

// extern const char source_str[]; // = "source"; // ( -- c-addr u )
extern void _source(void);

extern void _pinWrite(void);
extern void _pinMode(void);
extern void _pinRead(void);

extern void _strlen(void);			//samsuanchen@gmail.com 20190502
extern void _i(void);				//samsuanchen@gmail.com 20190502
extern void _j(void);				//samsuanchen@gmail.com 20190502
extern void _lt(void);				//samsuanchen@gmail.com 20190502
extern void _colon(void);			//samsuanchen@gmail.com 20190502
extern void _semicolon(void);		//samsuanchen@gmail.com 20190502
extern void _if(void);				//samsuanchen@gmail.com 20190502
extern void _else(void);			//samsuanchen@gmail.com 20190502
extern void _then(void); 			//samsuanchen@gmail.com 20190502
extern void _begin(void);			//samsuanchen@gmail.com 20190502
extern void _again(void);			//samsuanchen@gmail.com 20190502
extern void _until(void);			//samsuanchen@gmail.com 20190502
extern void _while(void);			//samsuanchen@gmail.com 20190502
extern void _repeat(void);			//samsuanchen@gmail.com 20190502
extern void _back_slash();			//samsuanchen@gmail.com 20190502
extern void _psee(void);			//samsuanchen@gmail.com 20190502
extern void _see(void);				//samsuanchen@gmail.com 20190502

extern char* pPNO;					//samsuanchen@gmail.com 20190510
extern void _comma();				//samsuanchen@gmail.com 20190510
extern void _two_drop();			//samsuanchen@gmail.com 20190510
extern void _base(void);			//samsuanchen@gmail.com 20190510
extern void _hold(void);			//samsuanchen@gmail.com 20190510
extern void _lt_number_sign(void);	//samsuanchen@gmail.com 20190510
extern void _number_sign(void);		//samsuanchen@gmail.com 20190510
extern void _number_sign_s(void);	//samsuanchen@gmail.com 20190510
extern void _number_sign_gt(void);	//samsuanchen@gmail.com 20190510

extern void _tick();				//samsuanchen@gmail.com 20190514
extern void _true();				//samsuanchen@gmail.com 20190514
extern void _false();				//samsuanchen@gmail.com 20190514
extern void _zero();				//samsuanchen@gmail.com 20190514
extern void _one();					//samsuanchen@gmail.com 20190514
extern void _two();					//samsuanchen@gmail.com 20190514
extern void _three();				//samsuanchen@gmail.com 20190514
extern void _four();				//samsuanchen@gmail.com 20190514
extern void _char_plus();			//samsuanchen@gmail.com 20190514
extern void _chars();				//samsuanchen@gmail.com 20190514
extern void _one_plus();			//samsuanchen@gmail.com 20190514
extern void _one_minus();			//samsuanchen@gmail.com 20190514
extern void _two_plus();			//samsuanchen@gmail.com 20190514
extern void _two_minus();			//samsuanchen@gmail.com 20190514
extern void _two_star();			//samsuanchen@gmail.com 20190514
extern void _bl(void);				//samsuanchen@gmail.com 20190514
extern void _cell_plus(void);		//samsuanchen@gmail.com 20190514
extern void _cell_minus(void);		//samsuanchen@gmail.com 20190514
extern void _cells(void);			//samsuanchen@gmail.com 20190514
extern void _cell_div(void);		//samsuanchen@gmail.com 20190514

extern void _question_dup(void);	//samsuanchen@gmail.com 20190515
extern void _depth(void);			//samsuanchen@gmail.com 20190515
extern void _nip(void);				//samsuanchen@gmail.com 20190515
extern void _two_slash(void);		//samsuanchen@gmail.com 20190515
extern void _two_dup(void);			//samsuanchen@gmail.com 20190515
extern void _two_over(void);		//samsuanchen@gmail.com 20190515
extern void _two_swap(void);		//samsuanchen@gmail.com 20190515
extern void _gt(void);				//samsuanchen@gmail.com 20190515
extern void _execute(void);			//samsuanchen@gmail.com 20190515

extern void _leave(void);			//samsuanchen@gmail.com 20190516
extern void _abort(void);			//samsuanchen@gmail.com 20190516
extern void _abort_quote(void);		//samsuanchen@gmail.com 20190516
extern void _eeprom_read(void);		//samsuanchen@gmail.com 20190516
extern void _eeprom_write(void);	//samsuanchen@gmail.com 20190516
extern void _to_name(void);			//samsuanchen@gmail.com 20190516
extern void _analogRead(void);		//samsuanchen@gmail.com 20190516
extern void _analogWrite(void);		//samsuanchen@gmail.com 20190516
extern void _tone(void);			//samsuanchen@gmail.com 20190520
extern void _noTone(void);			//samsuanchen@gmail.com 20190520
extern void _freq(void);			//samsuanchen@gmail.com 20190520
extern void _mod(void);				//samsuanchen@gmail.com 20190520

extern void _bracket_char(void);	//samsuanchen@gmail.com 20190521
extern void _bracket_tick(void);	//samsuanchen@gmail.com 20190521
extern void _create(void);			//samsuanchen@gmail.com 20190521
extern void _does(void);			//samsuanchen@gmail.com 20190521
extern cell_t* pNewDoes;			//samsuanchen@gmail.com 20190521
extern void _left_bracket(void);	//samsuanchen@gmail.com 20190521
extern void _right_bracket(void);	//samsuanchen@gmail.com 20190521
extern void _find(void);			//samsuanchen@gmail.com 20190521 fixed
extern void _star_slash(void);		//samsuanchen@gmail.com 20190521
extern void _star_slash_mod(void);	//samsuanchen@gmail.com 20190521
extern void _plus_loop(void);		//samsuanchen@gmail.com 20190521
extern void _slash_mod(void);		//samsuanchen@gmail.com 20190521
extern void _zero_less(void);		//samsuanchen@gmail.com 20190521
extern void _to_body(void);			//samsuanchen@gmail.com 20190521

extern void _zero_not_equal(void);	//samsuanchen@gmail.com 20190525
extern void _zero_greater(void);	//samsuanchen@gmail.com 20190525
extern void _two_to_r(void);		//samsuanchen@gmail.com 20190525
extern void _two_r_from(void);		//samsuanchen@gmail.com 20190525
extern void _two_r_fetch(void);		//samsuanchen@gmail.com 20190525
extern void _neq(void);				//samsuanchen@gmail.com 20190525
extern void _case(void);			//samsuanchen@gmail.com 20190525
extern void _of(void);				//samsuanchen@gmail.com 20190525
extern void _endof(void);			//samsuanchen@gmail.com 20190525
extern void _endcase(void);			//samsuanchen@gmail.com 20190525

extern void _fm_slash_mod(void);	//samsuanchen@gmail.com 20190601
extern void _immediate(void);		//samsuanchen@gmail.com 20190601
extern void _compileOnly(void);		//samsuanchen@gmail.com 20190601
extern void _invert(void);			//samsuanchen@gmail.com 20190601
extern void _fm_slash_mod(void);	//samsuanchen@gmail.com 20190601
extern void _lshift(void);			//samsuanchen@gmail.com 20190601
extern void _m_star(void);			//samsuanchen@gmail.com 20190601
extern void _move(void);			//samsuanchen@gmail.com 20190601
extern void _postpone(void);		//samsuanchen@gmail.com 20190601
extern void _recurse(void);			//samsuanchen@gmail.com 20190601
extern void _rshift(void);			//samsuanchen@gmail.com 20190601

extern void _lastVoc(void);			//samsuanchen@gmail.com 20190604
extern void _vocs(void);			//samsuanchen@gmail.com 20190604
extern void _context(void);			//samsuanchen@gmail.com 20190604
extern void _current(void);			//samsuanchen@gmail.com 20190604
extern void _definitions(void);		//samsuanchen@gmail.com 20190604
extern void _voc_sys(void);			//samsuanchen@gmail.com 20190604
extern void _vocabulary(void);		//samsuanchen@gmail.com 20190604
extern void _also(void);			//samsuanchen@gmail.com 20190604
extern void _previous(void);		//samsuanchen@gmail.com 20190604
extern void _order(void);			//samsuanchen@gmail.com 20190604
extern void _primitive(void);		//samsuanchen@gmail.com 20190604

extern void _dash_rot(void);		//samsuanchen@gmail.com 20190606
extern void _nRomWords(void);		//samsuanchen@gmail.com 20190609
extern void _addrToSee(void);		//samsuanchen@gmail.com 20190609
extern void _isUserEntry(void);		//samsuanchen@gmail.com 20190610

extern void _findFirst(void);		//samsuanchen@gmail.com 20190615