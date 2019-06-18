# https://github.com/samsuanchen/yaffa_samd51.git
  
## to do

	1. new primitive words: firstContext forget nRamWords nextCFA
	2. reorganize .cpp and .h files
	3. flash file system words: fload <filename> fload <filename> ftype <filename> fdel <filename> fdir

## history

### 2019/06/14

	new primitive words: >flags .r .0r h. h.r h0.r h8. <= >= 0<= 0>= outLen ? findFirst

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
	 ! # #> #s ' ( (+loop) (con) (do) (does>) (leave) (loop) (see) (var) (voc)
	 * */ */mod + +! +loop , - -rot . ." .( .name .s / /mod 0 0< 0<> 0= 0>
	 1 1+ 1- 2 2! 2* 2+ 2- 2/ 2>r 2@ 2drop 2dup 2over 2r> 2r@ 2swap 3 4 : ;
	 < <# <> = > >body >in >name >number >r ?dup @ [ ['] [char] \ ]
	 abort abort" abs accept addrToSee again allot also analogRead analogWrite and
	 base begin bgBlack bgBlue bgBrightBlack bgBrightBlue bgBrightCyan bgBrightGreen
	 bgBrightMagenta bgBrightRed bgBrightWhite bgBrightYellow bgCyan bgGreen bgMagenta
	 bgRed bgWhite bgYello bl bran c! c, c@ case cell+ cell- cell/ cells char+ char
	 chars compile-only context constant cr count create current
	 decimal definitions delay depth do does> download drop dump dup
	 echo! eflmkdir else endcase endof emit evaluate execute exit
	 false fgBlack fgBlue fgBrightBlack fgBrightBlue fgBrightCyan fgBrightGreen
	 fgBrightMagenta fgBrightRed fgBrightWhite fgBrightYellow fgCyan fgGreen fgMagenta
	 fgRed fgWhite fgYellow fill find fm/mod freq here help hex hold
	 i if immediate invert isRamEntry isUserEntry isWord j
	 lastVoc leave literal load loop lshift m* max min mod move
	 negate nextRamEntry nip noTone nRomWords of or order over
	 pick pinMode pinRead pinWrite postpone previous primitive print
	 quit r> r@ ramFirst ramLast recurse remove repeat romEntry rot rshift
	 s" see setEscPrint source space spaces strlen swap then throw tone true type
	 u. until variable vocabulary vocs warm while who word words xor zbran
	
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
