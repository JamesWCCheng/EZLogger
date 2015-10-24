//#define GECKO
#include "ezlogger.h"
#include <string>
class MOZILLA
{
public:
  void Gecko()
  {
    P(this);
  }
};

int main() {

#ifdef GECKO
  MOZ_LOG(0,0, ("some log\n"));
  NS_WARNING("only string\n");
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
  f.Gecko();
  int32_t g = -123;
  int64_t h = -5566;
  uint32_t i = 123;
  uint64_t j = 1234;
#ifdef GECKO
  P(a, b, c, d, e, &f, g, h, i, j, foo, bar, msg, msg2, res);
#else
  P(a, b, c, d, e, &f, g, h, i, j);
#endif
  EZ_TAG = "123";
  PR(a, b, c, d, e, &f, g, h, i, j);
  PG(a, b, c, d, e, &f, g, h, i, j);
  PB(a, b, c, d, e, &f, g, h, i, j);
  PX0(EZ_RED);
  PX0(EZ_LIGHT_RED);
  PX0(EZ_GREEN);
  PX0(EZ_LIGHT_GREEN);
  PX0(EZ_BLUE);
  PX0(EZ_LIGHT_BLUE);
  PX0(EZ_DARY_GRAY);
  PX0(EZ_CYAN);
  PX0(EZ_LIGHT_CYAN);
  PX(EZ_LIGHT_CYAN, a, b, c, d, e, &f, g, h, i, j);
  PX0(EZ_PURPLE);
  PX0(EZ_LIGHT_PURPLE);
  PX0(EZ_BROWN);
  PX0(EZ_YELLOW);
  PX0(EZ_LIGHT_GRAY);
  PR0(); //Empty
  PG0();
  PB0();

  return 0;
}
