# https://github.com/samsuanchen/yaffa_samd51.git
  
## to do

	1. primitive words: >flags .r .0r 

## history

### 2019/06/11

#### vocabularies and words (after executing "load")

	vocs
	 vocB vocA new primitive OK
	
	allWords
	in vocabulary vocB
	 b4 b3 b2 b1
	in vocabulary vocA
	 a4 a3 a2 a1
	in vocabulary new
	 1234567890123456789012345678901 keyA keyNote: getPFA keyNote printableChars
	 tst h seeAll seeRamWords seeRomWords w. allWords prevVoc body> voc> nRamWords
	 nextCFA entry>cfa entry>link smudge? compile-only? immediate? romWords
	 z y X T L H I O BU BL BD BR buzzer led t .0r .r vocB vocA new
	in vocabulary primitive
	 isUserEntry addrToSee nRomWords primitive order previous also lastVoc vocs
	 definitions current context bgBrightWhite bgBrightCyan bgBrightMagenta
	 bgBrightBlue bgBrightYellow bgBrightGreen bgBrightRed bgBrightBlack bgWhite
	 bgCyan bgMagenta bgBlue bgYellow bgGreen bgRed bgBlack fgBrightWhite fgBrightCyan
	 fgBrightMagenta fgBrightBlue fgBrightYellow fgBrightGreen fgBrightRed fgBrightBlack
	 fgWhite fgCyan fgMagenta fgBlue fgYellow fgGreen fgRed fgBlack bgBlue fgYellow
	 setEscPrint isWord freq noTone tone download remove echo! load eflmkdir
	 >name analogWrite analogRead pinRead pinMode pinWrite delay .name nextRamEntry
	 isRamEntry ramLast ramFirst romEntry words see (see) dump .s who help endcase
	 endof of case hex <> 2r@ 2r> 2>r 0> 0<> .( ] [char] ['] [ xor \ word while
	 until u. then swap spaces space source rshift -rot rot repeat recurse r@
	 r> quit postpone pick or nip negate move mod min max m* lshift loop leave
	 j invert compile-only immediate if i hold here fm/mod find fill execute
	 emit else dup does> do depth decimal create cr count again strlen constant
	 chars char+ char cell/ cells cell- cell+ c@ c, c! bl begin base and allot
	 accept abs abort" @ ?dup >r >number >in >body > <# < ; : 2swap 2over 2dup
	 2drop 2@ 2/ 2! 2* 2- 2+ 1- 1+ 4 3 2 1 0 false true 0< /mod / , +loop +!
	 */mod */ ( ' #s #> # ! abort 0= * + - . print warm vocabulary (voc) variable
	 (con) drop = over (var) ." s" evaluate (+loop) (leave) (loop) (do) throw
	 (does>) zbran bran type literal exit  OK
	
	nRamWords . 49  OK
	
	nRomWords . 241  OK

### 2019/5/6

#### all primitive rom words:

	words
	exit literal type jump zjump subroutine throw do-sys loop-sys leave-sys plus_loop-sys
	evaluate s" ." variable over = drop warm . - + 
	* 0= ! +! , / 2! 2@ 2drop : ; >r @ abs accept allot and c! c, c@ char constant 
	strlen i j < if else then begin again until while repeat count cr decimal 
	do dup emit fill here loop max min negate or quit r> r@ rot source space 
	spaces swap u. word \ xor [char] ( .( hex help who .s dump see words romEntry 
	ramLast ' .name delay pinWrite pinMode pinRead eflmkdir load echo! remove 
	download romWords ramWords >cfa >link  OK

#### words to load:
	seeAll seeRomWords seeRamWords words ramWords countRamWords >cfa >link romWords countRomWords z y t X T L H I O

#### new words:
	strlen i j < if else then begin again until while repeat \ ( (see) romEntry 
	ramLast .name 

#### modified words:
	count see
 
### 2019/5/3

	git clone https://github.com/wa1tnr/ainsuForth-gen-exp-m4.git
