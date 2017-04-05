/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"
/************************************************************************/
/* 
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

Subscribe to see which companies asked this question.

*/
/************************************************************************/

#ifndef Q344_REVERSE_STRING

char* reverseString(char* s) {
	int szLen = strlen(s);
	char *szResult = (char *)malloc(sizeof(char) * (szLen + 1));
	strcpy(szResult, s);
	char *pleft = szResult, *pright = szResult + szLen - 1;
	char tmp;
	for (; pright > pleft; tmp = *pright, *pright = *pleft, *pleft = tmp, pright--, pleft++);
	return szResult;
}

int main() {
	char *sz = "hello";
	char *sz2;
	puts(sz2 = reverseString(sz));
	free(sz2);
	return EXIT_SUCCESS;
}







#endif
