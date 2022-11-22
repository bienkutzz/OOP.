#include <iostream>
#include "a.h"
#include "b.h"

#define F1 1
#define F2 2
int main()
{
#ifdef F1
	function1();
#endif
#ifdef F2
	function2();
#endif

#undef F1 //we undefine F1 to show that if it is undefined function1 will be ignored

#ifdef F1
	function1();
#endif
#ifdef F2
	function2();
#endif
}

// if the macro is defined, the statements following #ifdef will compile
// if the macro is undefined, the statements following #ifdef will be skipped