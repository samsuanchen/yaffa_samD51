 \ \033[<fgColor>;<bgColor>m see bgColor
 variable escLeading $5b1b escLeading ! \ $5b1b escLeading ! \ esc [
 variable fgColor 0 , $3733 fgColor ! \ fgWhite default
 variable bgColor 0 , $3034 fgColor ! \ bgBlack default
 : fgColor: create bl word cell+ @ , does> r> r> drop @ fgColor ! escLeading print fgColor print [char] m emit ;
 : bgColor: create bl word cell+ @ , does> r> r> drop @ bgColor ! escLeading print bgColor print [char] m emit ;
 fgColor: fgBlack 30
 fgColor: fgRed 31
 fgColor: fgGreen 32
 fgColor: fgYellow 33
 fgColor: fgBlue 34
 fgColor: fgMagenta 35
 fgColor: fgCyan 36
 fgColor: fgWhite 37
 fgColor: fgBrightBlack 30;1
 fgColor: fgBrightRed 31;1
 fgColor: fgBrightGreen 32;1
 fgColor: fgBrightYellow 33;1
 fgColor: fgBrightBlue 34;1
 fgColor: fgBrightMagenta 35;1
 fgColor: fgBrightCyan 36;1
 fgColor: fgBrightWhite 37;1
 bgColor: bgBlack 40
 bgColor: bgRed 41
 bgColor: bgGreen 42
 bgColor: bgYellow 43
 bgColor: bgBlue 44
 bgColor: bgMagenta 45
 bgColor: bgCyan 46
 bgColor: bgWhite 47
 bgColor: bgBrightBlack 100
 bgColor: bgBrightRed 101
 bgColor: bgBrightGreen 102
 bgColor: bgBrightYellow 103
 bgColor: bgBrightBlue 104
 bgColor: bgBrightMagenta 105
 bgColor: bgBrightCyan 106
 bgColor: bgBrightWhite 107
 