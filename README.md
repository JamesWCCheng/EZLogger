# EZLogger

請貼下面兩行在你的gecko code
\#define GECKO
\#include "ezlogger.h"
複製ezlogger.h到你目錄下
使用上只需寫P(_(你的變數),...)即可全部印出不須判別型別,超無der

main.cpp經過測試會印出

FunctionName:LineNumber  a = 55.660000, b = haha, c = 42689.200000, d = 1, e = 1, &f = 0x7fffffffbec0, g = -123, h = -5566, i = 123, j = 1234, 4foo = nsString, 3bar = nsCString, 1msg = nsAutoString, 2msg2 = nsAutoCString, 5res = 0
FunctionName:LineNumber:203

#know issue
我不知道怎麼盼別是不是在gecko下 所以用\#ifdef GECKO
