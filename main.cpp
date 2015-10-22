#define GECKO

#include "ezlogger.h"
#include <string>
class MOZILLA
{
};


int main() {
  nsresult res = NS_OK;
  nsString foo = NS_LITERAL_STRING("nsString");
  nsCString bar = NS_LITERAL_CSTRING("nsCString");
  nsAutoString msg = NS_ConvertASCIItoUTF16("nsAutoString");
  nsAutoCString msg2("nsAutoCString");
  float a = 55.66f;
  std::string b = "haha";
  double c = 42689.2;
  const char* d = "abc";
  bool e = true;
  MOZILLA f;
  int32_t g = -123;
  int64_t h = -5566;
  uint32_t i = 123;
  uint64_t j = 1234;
  P(_(a), _(b), _(c), _(d), _(e), _(&f), _(g), _(h), _(i), _(j), _(foo), _(bar), _(msg), _(msg2), _(res));
  P(); //Empty
	return 0;
}