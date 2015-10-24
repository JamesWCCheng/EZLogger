#ifndef __EZLOGGER_H__
#define __EZLOGGER_H__
#include <stdio.h>
#include <utility>
#include <string>
#include <stdint.h>

#ifndef GECKO // GECKO
#define printf_stderr printf

#define NONE ""
#define RED ""
#define LIGHT_RED ""
#define GREEN ""
#define LIGHT_GREEN ""
#define BLUE ""
#define LIGHT_BLUE ""
#define DARY_GRAY ""
#define CYAN ""
#define LIGHT_CYAN ""
#define WHITE ""
#endif

#define EXPAND(x) x
#define PURPLE ""
#define LIGHT_PURPLE ""
#define BROWN ""
#define YELLOW ""
#define LIGHT_GRAY ""
#define CONCATENATE(x, y) x##y
// 傳入三個 展開變成  (a),(b),(c), 填滿 16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1....N是落在3這數字上 取代成N=3
#define NARG(...) NARG_(__VA_ARGS__, RSEQ_N())
#define NARG_(...) EXPAND(ARG_N(__VA_ARGS__))
#define ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
              _11, _12, _13, _14, _15, _16, N, ...) N
#define RSEQ_N() 16, 15, 14, 13, 12, 11, \
                 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
// 假設傳入三個P(a,b,c), 展開變成EXTEND_(3, __VA_ARGS__)
#define EXTEND(...) EXTEND_(NARG(__VA_ARGS__), __VA_ARGS__)
// EXTEND_(3, __VA_ARGS__) 展開成 "EXPAND"(EXTEND_3)(__VA_ARGS__), 這邊又怪小的用了一次EXPAND
// 反正就變成EXTEND_3(__VA_ARGS__)
#define EXTEND_(N, ...) EXPAND(CONCATENATE(EXTEND_, N))(__VA_ARGS__)
#define EXTEND_1(x, ...) std::make_pair(x, #x)
#define EXTEND_2(x, ...) EXTEND_1(x), EXTEND_1(__VA_ARGS__)
// EXTEND_3(__VA_ARGS__)
// 展開會先成 EXTEND_1(第一個傳入變數),EXTEND_2(__VA_ARGS__)
// 再展開會變成std::make_pair(x, #x), EXTEND_2(__VA_ARGS__)
// 後面繼續遞迴展開成一堆pair 大功告成
#define EXTEND_3(x, ...) EXTEND_1(x), EXTEND_2(__VA_ARGS__)
#define EXTEND_4(x, ...) EXTEND_1(x), EXTEND_3(__VA_ARGS__)
#define EXTEND_5(x, ...) EXTEND_1(x), EXTEND_4(__VA_ARGS__)
#define EXTEND_6(x, ...) EXTEND_1(x), EXTEND_5(__VA_ARGS__)
#define EXTEND_7(x, ...) EXTEND_1(x), EXTEND_6(__VA_ARGS__)
#define EXTEND_8(x, ...) EXTEND_1(x), EXTEND_7(__VA_ARGS__)
#define EXTEND_9(x, ...) EXTEND_1(x), EXTEND_8(__VA_ARGS__)
#define EXTEND_10(x, ...) EXTEND_1(x), EXTEND_9(__VA_ARGS__)
#define EXTEND_11(x, ...) EXTEND_1(x), EXTEND_10(__VA_ARGS__)
#define EXTEND_12(x, ...) EXTEND_1(x), EXTEND_11(__VA_ARGS__)
#define EXTEND_13(x, ...) EXTEND_1(x), EXTEND_12(__VA_ARGS__)
#define EXTEND_14(x, ...) EXTEND_1(x), EXTEND_13(__VA_ARGS__)
#define EXTEND_15(x, ...) EXTEND_1(x), EXTEND_14(__VA_ARGS__)
#define EXTEND_16(x, ...) EXTEND_1(x), EXTEND_15(__VA_ARGS__)

#ifdef GECKO // GECKO

#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

#include "nsLiteralString.h"
#include "nsStringFwd.h"
#include "nsString.h"
#include "nsError.h" // For nsresult
#include "nsDebug.h" //For printf_stderr

#ifdef NS_WARNING_COLOR
  #undef NS_WARNING
  #define NS_WARNING(str)                                       \
    NS_DebugBreak(NS_DEBUG_WARNING, LIGHT_RED str "\033[m", nullptr, __FILE__, __LINE__)
#endif

#ifdef MOZ_LOG_886
  #undef MOZ_LOG
  #define REAL_LOG(X) printf_stderr(LIGHT_BLUE X "\033[m")
  #define MOZ_LOG(_module,_level, arg) REAL_LOG arg
#endif

/*
nsString foo = NS_LITERAL_STRING
nsCString bar = NS_LITERAL_CSTRING

*/
// For nsAutoString
void printInternal(const nsAutoString& aAutoStr, const char* const aObjName)
{
  printf_stderr("%s = %s", aObjName, NS_ConvertUTF16toUTF8(aAutoStr).get());
}

// For nsAutoCString
void printInternal(const nsAutoCString& aAutoCStr, const char* const aObjName)
{
  printf_stderr("%s = %s", aObjName, aAutoCStr.get());
}

// For nsACString
void printInternal(const nsACString& aACStr, const char* const aObjName)
{
  printf_stderr("%s = %s", aObjName, nsPromiseFlatCString(aACStr).get());
}
// For nsAString
void printInternal(const nsAString& aAStr, const char* const aObjName)
{
  printf_stderr("%s = %s", aObjName,
    NS_ConvertUTF16toUTF8(nsPromiseFlatString(aAStr).get()).get());
}

void printInternal(nsresult aRes, const char* const aObjName)
{
  printf_stderr("%s = %x", aObjName, static_cast<uint32_t>(aRes));
}

#endif
// For std string
void printInternal(std::string aStdStr, const char* const aObjName)
{
  printf_stderr("%s = %s", aObjName, aStdStr.c_str());
}
// For pointer
void printInternal(void* aPtr, const char* const aObjName)
{
  printf_stderr("%s = %p", aObjName, aPtr);
}
// For c style string
void printInternal(const char* aStr, const char* const aObjName)
{
  printf_stderr("%s = %s", aObjName, aStr);
}
// For float
void printInternal(float aVal, const char* const aObjName)
{
  printf_stderr("%s = %f", aObjName, aVal);
}
// For double
void printInternal(double aVal, const char* const aObjName)
{
  printf_stderr("%s = %lf", aObjName, aVal);
}
// For bool
void printInternal(bool aVal, const char* const aObjName)
{
  printf_stderr("%s = %d", aObjName, aVal);
}
// For int32_t
void printInternal(int32_t aVal, const char* const aObjName)
{
  printf_stderr("%s = %d", aObjName, aVal);
}
// For uint32_t
void printInternal(uint32_t aVal, const char* const aObjName)
{
  printf_stderr("%s = %u", aObjName, aVal);
}
// For uint64_t
void printInternal(uint64_t aVal, const char* const aObjName)
{
  printf_stderr("%s = %lu", aObjName, aVal);
}
// For int64_t
void printInternal(int64_t aVal, const char* const aObjName)
{
  printf_stderr("%s = %ld", aObjName, aVal);
}

void print() {
  printf_stderr(NONE"\n");
}

template<class Type>
void print(
  const std::pair<Type, const char *> &arg) {
  printInternal(arg.first, arg.second);
  print();
}
template<class Type, class... Types>
void print(
  const std::pair<Type, const char *> &arg,
  const std::pair<Types, const char *> &... args) {
  // first is the real object, second is the object variable name.
  printInternal(arg.first, arg.second);
  printf_stderr(", ");
  print(args...);
}


template<class... Types>
void PInternal(const char* aColor, const char* aFileName, const int aLineNum, Types&&...  args)
{
  printf_stderr("%s%s:%d  ", aColor, aFileName, aLineNum);
  print(std::forward<Types>(args)...);
}

#define P(...) PInternal("", __FUNCTION__, __LINE__, EXTEND(__VA_ARGS__))
#define PR(...) PInternal(LIGHT_RED, __FUNCTION__, __LINE__, EXTEND(__VA_ARGS__))
#define PG(...) PInternal(LIGHT_GREEN, __FUNCTION__, __LINE__, EXTEND(__VA_ARGS__))
#define PB(...) PInternal(LIGHT_BLUE, __FUNCTION__, __LINE__, EXTEND(__VA_ARGS__))
#define PX(COLOR, ...) PInternal(COLOR, __FUNCTION__, __LINE__, EXTEND(__VA_ARGS__))

#endif
