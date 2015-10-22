//#define GECKO
#include "ezlogger.h"
#include <string>
class MOZILLA
{
public:
  void GECKO()
  {
    P(_(this));
  }
};

int main() {

#ifdef GECKO
  MOZ_LOG(0,0, ("some log\n"));
  NS_WARNING("only string");
  nsresult res = NS_OK;
  nsString foo = NS_LITERAL_STRING("nsString");
  nsCString bar = NS_LITERAL_CSTRING("nsCString");
  nsAutoString msg = NS_ConvertASCIItoUTF16("nsAutoString");
  nsAutoCString msg2("nsAutoCString");
#endif
  float a = 55.66f;
  std::string b = "haha";
  double c = 42689.2;
  const char* d = "abc";
  bool e = true;
  MOZILLA f;
  f.GECKO();
  int32_t g = -123;
  int64_t h = -5566;
  uint32_t i = 123;
  uint64_t j = 1234;
#ifdef GECKO
  P(_(a), _(b), _(c), _(d), _(e), _(&f), _(g), _(h), _(i), _(j), _(foo), _(bar), _(msg), _(msg2), _(res));
#else
  P(_(a), _(b), _(c), _(d), _(e), _(&f), _(g), _(h), _(i), _(j));
#endif

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
  PR(); //Empty
  PG();
  PB();

  return 0;
}