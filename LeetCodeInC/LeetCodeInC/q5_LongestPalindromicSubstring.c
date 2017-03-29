/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

/************************************************************************/
/* 
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/
/************************************************************************/

#ifndef Q5_LONGEST_PALINDROMIC_SUBSTRING

unsigned char isPalindromic(char* front, char* back)
{
	for (; front < back; front++, back--)
	{
		if (*front != *back)
			return 0;
	}
	return 1;
}

char* longestPalindrome(char* s) {
	int lengthSub = 0;
	const int STRLEN = strlen(s);
	char *scanFront = s, *scanBack = s;
	char *markFront = s, *markBack = s;

	for (; *scanFront; scanFront++)
	{
		for (scanBack = s + STRLEN - 1; scanBack >= scanFront; scanBack--)
		{
			if (scanBack - scanFront >= lengthSub && *scanBack == *scanFront && isPalindromic(scanFront, scanBack))
			{
				markFront = scanFront;
				markBack = scanBack;
				lengthSub = scanBack - scanFront;
			}
		}
	}

	char* resultStr = (char *)(malloc((markBack - markFront + 2) * sizeof(char)));
	strncpy(resultStr, markFront, markBack - markFront + 1);
	resultStr[markBack - markFront + 1] = '\0';
	return resultStr;
}

int main()
{
	char *sz;
	sz = longestPalindrome("babad");
	printf("Input:%s\nResult:%s\n", "babad", sz);
	free(sz);
	sz = longestPalindrome("cbbd");
	printf("Input:%s\nResult:%s\n", "cbbd", sz);
	free(sz);

	return EXIT_SUCCESS;
}






#endif

