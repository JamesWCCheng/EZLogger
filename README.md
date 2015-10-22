# EZLogger

請貼下面兩行在你的gecko code  

\#define GECKO  

\#include "ezlogger.h"  

複製ezlogger.h到你目錄下  

使用上只需寫P(_(你的變數),...)即可全部印出不須判別型別,超無腦der  

也可以換顏色  

PR -> LIGHT_RED  

PG -> LIGHT_GREEN  

PB -> LIGHT_BLUE  

PX(RED);  

PX(LIGHT_RED);  

PX(GREEN);  

PX(LIGHT_GREEN);  

PX(BLUE);  

PX(LIGHT_BLUE);  

PX(DARY_GRAY);  

PX(CYAN);  

PX(LIGHT_CYAN);  

PX(PURPLE);  

PX(LIGHT_PURPLE);  

PX(BROWN);  

PX(YELLOW);  

PX(LIGHT_GRAY);  

依序印出來的顏色是  

<a href="" target="_blank"><img src="https://dl.dropboxusercontent.com/u/15611020/color.png"/></a>

main.cpp經過測試會印出  

FunctionName:LineNumber  a = 55.660000, b = haha, c = 42689.200000, d = abc, e = 1, &f = 0x7fffffffbec0, g = -123, h = -5566, i = 123, j = 1234, foo = nsString, bar = nsCString, msg = nsAutoString, msg2 = nsAutoCString, res = 0  

FunctionName:LineNumber:203  

#know issue
我不知道怎麼盼別是不是在gecko下 所以用\#ifdef GECKO

