#ifndef __EZLOGGER_H__
#define __EZLOGGER_H__
#include <stdio.h>
#include <utility>
#include <string>
#include <stdint.h>
#ifndef GECKO
#define printf_stderr printf
#endif
#define _(x) std::make_pair(x, #x)


#ifdef GECKO
#include "nsError.h" // For nsresult
#include "nsStringAPI.h" // For nsXXXString

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
void printInternal(const nsAutoCString& aAutoStr, const char* const aObjName)
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
  printf_stderr("%s = %u", aObjName, static_cast<uint32_t>(aRes));
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
void printInternal(char* aStr, const char* const aObjName)
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
	printf_stderr("%s = %I64u", aObjName, aVal);
}


// For int64_t
void printInternal(int64_t aVal, const char* const aObjName)
{
	printf_stderr("%s = %I64d", aObjName, aVal);
}


void print() {
	printf_stderr("\n");
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
void PInternal(const char* aFileName, const int aLineNum, Types&&...  args)
{
	printf_stderr("%s:%d  ", aFileName, aLineNum);
	print(std::forward<Types>(args)...);
}

#define P(...) PInternal(__FUNCTION__, __LINE__, __VA_ARGS__) 

#endif