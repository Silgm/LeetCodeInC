/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"


/************************************************************************/
/* 

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/
/************************************************************************/



#ifndef Q8_STRING_TO_INTEGER
int myAtoi(char* str) {
	int result;
	for (; *str == ' '; str++);//Jump space
	if (*str)
	{
		if (*str == '+')
		{
			//sign = 1;
			for (result = 0, str++; *str >= '0' && *str <= '9'; str++)
			{
				if (result > (INT_MAX - ((*str) - '0')) / 10)
					return INT_MAX;
				else
					result = ((result * 10) + ((*str) - '0'));
			}
		}
		else if (*str == '-')
		{
			//sign = -1;
			for (result = 0, str++; *str >= '0' && *str <= '9'; str++)
			{
				if (result < (INT_MIN + ((*str) - '0')) / 10)
					return INT_MIN;
				else
					result = ((result * 10) - ((*str) - '0'));
			}
		}
		else if (*str >= '0' && *str <= '9')
		{
			for (result = 0; *str >= '0' && *str <= '9'; str++)
			{
				if (result > (INT_MAX - ((*str) - '0')) / 10)
					return INT_MAX;
				else
					result = ((result * 10) + ((*str) - '0'));
			}
		}
		else
			return 0;
	}
	else
		return 0;
	return result;
}

int main()
{
	printf("%d\n", myAtoi("123321"));

	printf("%d\n", myAtoi("-121"));
	return EXIT_SUCCESS;
}


#endif // !Q8_STRING_TO_INTEGER

