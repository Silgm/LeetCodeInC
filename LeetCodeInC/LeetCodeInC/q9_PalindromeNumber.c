/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"


/************************************************************************/
/* 
Determine whether an integer is a palindrome. Do this without extra space.
*/
/************************************************************************/


#ifndef Q9_PALINDROME_NUMBER

bool isPalindrome(int x) {
	int nReverse = 0;
	int nVal = x;
	if (x < 0)
		return false;
	while (x)//µ¹ÖÃÒ»¸öÊý
	{
		nReverse = nReverse * 10 + x % 10;
		x /= 10;
	}
	if (nReverse == nVal)
		return true;
	else
		return false;
}

int main()
{
	int input = 121;

	(isPalindrome(input)) ? (printf("Yes")) : (printf("No"));

	puts("");

	return EXIT_SUCCESS;
}

#endif
