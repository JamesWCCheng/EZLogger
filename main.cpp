#include "ezlogger.h"
#include <string>
class Foo
{
	
};


int main() {
	float a = 55.66f;
	std::string b = "haha";
	double c = 42689.2;
	char* d = "abc";
	bool e = true;
	Foo f;
	int32_t g = -123;
	int64_t h = -5566;
	uint32_t i = 123;
	uint64_t j = 1234;
	P(_(a), _(b), _(c), _(d), _(e), _(&f), _(g), _(h), _(i), _(j));
	P(); //empty
	/*PP(&f);
	XD("abc");
	XD(a);*/
	return 0;
}