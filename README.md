# https://github.com/samsuanchen/yaffa_samd51.git

## 2019/5/3

copied original https://github.com/wa1tnr/ainsuForth-gen-exp-m4.git

## 2019/5/6

### all low level primitive words
	exit literal type jump zjump subroutine throw do-sys loop-sys leave-sys plus_loop-sys
	evaluate s" ." variable over = drop warm . - + 
	* 0= ! +! , / 2! 2@ 2drop : ; >r @ abs accept allot and c! c, c@ char constant 
	strlen i j < if else then begin again until while repeat count cr decimal 
	do dup emit fill here loop max min negate or quit r> r@ rot source space 
	spaces swap u. word \ xor [char] ( .( hex help who .s dump see words romEntry 
	ramLast ' .name delay pinWrite pinMode pinRead eflmkdir load echo! remove 
	download romWords ramWords >cfa >link 

### low level primitive words modified:
	count see
 
### new low level primitive words:
	strlen i j < if else then begin again until while repeat \ ( (see) romEntry 
	ramLast .name 

### high level colon words defined in text.txt (past each one into arduino IDE input box):
	seeAll seeRomWords seeRamWords words ramWords countRamWords >cfa >link romWords countRomWords z y t X T L H I O
  
 

### need to add
	var-sys con-sys
 
### need to modify
	variable constant
  