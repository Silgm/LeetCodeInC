/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

#ifndef Q7_REVERSE_INTEGER
/************************************************************************/
/* 

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.

Subscribe to see which companies asked this question.

*/
/************************************************************************/
int reverse(int x) {
	int result = x % 10;
	if (x >= 0)
	{
		while (x /= 10)
		{
			if (result > (2147483647 - x % 10) / 10)
				return 0;
			result = result * 10 + x % 10;
		}
	}
	else
	{
		while (x /= 10)
		{
			if (result < (-2147483647 - x % 10) / 10)
				return 0;
			result = result * 10 + x % 10;
		}
	}
	return result;
}


int main()
{
	int input1 = 123, input2 = -123;

	printf("Input:%d, Result:%d\n", input1, reverse(input1));
	printf("Input:%d, Result:%d\n", input2, reverse(input2));

	return EXIT_SUCCESS;
}



#endif // !Q7_REVERSE_INTEGER

