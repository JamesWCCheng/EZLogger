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

也可以傳入指定顏色
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

PR();  

PG();  

PB();  

依序印出來的顏色是  

<a href="" target="_blank"><img src="https://dl.dropboxusercontent.com/u/15611020/color.png"/></a>  

main.cpp經過測試會印出  

<a href="" target="_blank"><img src="https://dl.dropboxusercontent.com/u/15611020/result.png"/></a>  

##NS_WARNING_COLOR  

如果#define NS_WARNING_COLOR, 行為是會把NS_WARNING變紅色  

##MOZ_LOG_886  
如果#define MOZ_LOG_886, 行為是會把PR_LOG導到printf_stderr然後套上藍色  

#know issue
我不知道怎麼盼別是不是在gecko下 所以用\#ifdef GECKO

