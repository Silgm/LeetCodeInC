/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"




/************************************************************************/
/* 
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±.

For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.


Example:

n = 15,

Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]

*/
/************************************************************************/

#ifndef Q412_FIZZBUZZ

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/

#define FIZZ_LEN		4
#define BUZZ_LEN		4
#define FIZZBUZZ_LEN	8

char* myitoa(int num)
{
	int tmpNum = num, digits = 0;
	char *pcResult = NULL;
	for (digits = 0; tmpNum > 0; tmpNum /= 10, digits++);
	pcResult = (char *)malloc(sizeof(char) * (digits + 1));
	pcResult[digits] = '\0';
	for (; digits > 0; digits--, pcResult[digits] = num % 10 + '0', num /= 10);
	return pcResult;
}

char** fizzBuzz(int n, int* returnSize) {
	char **ppResult = NULL, **ppTmpResult = NULL;
	char *tmpSz = NULL;
	int resultSize = 0, nloop = 0;

	if (n < 1)
		return NULL;

	for (nloop = 1; nloop < n + 1;nloop++)
	{
		resultSize++;
		if (!(nloop % 15))
		{
			tmpSz = (char *)malloc(sizeof(char) * (FIZZBUZZ_LEN + 1));
			strcpy(tmpSz, "FizzBuzz");
			ppTmpResult = ppResult; 
			ppResult = (char **)realloc(ppTmpResult, resultSize * sizeof(char *));
			ppResult[nloop - 1] = tmpSz;
		}
		else if(!(nloop % 3))
		{
			tmpSz = (char *)malloc(sizeof(char) * (FIZZ_LEN + 1));
			strcpy(tmpSz, "Fizz");
			ppTmpResult = ppResult;
			ppResult = (char **)realloc(ppTmpResult, resultSize * sizeof(char *));
			ppResult[nloop - 1] = tmpSz;
		}
		else if (!(nloop % 5))
		{
			tmpSz = (char *)malloc(sizeof(char) * (BUZZ_LEN + 1));
			strcpy(tmpSz, "Buzz");
			ppTmpResult = ppResult;
			ppResult = (char **)realloc(ppTmpResult, resultSize * sizeof(char *));
			ppResult[nloop - 1] = tmpSz;
		}
		else
		{
			ppTmpResult = ppResult;
			ppResult = (char **)realloc(ppTmpResult, resultSize * sizeof(char *));
			ppResult[nloop - 1] = myitoa(nloop);
		}
	}
	*returnSize = resultSize;
	return ppResult;
}





int main()
{
	int returnSize, nIndex = 0;
	char **ppStr = fizzBuzz(15, &returnSize);

	for (nIndex = 0; nIndex < returnSize; nIndex ++)
	{
		printf("%s\n", ppStr[nIndex]);
	}

	for (nIndex = 0; nIndex < returnSize; nIndex++)
	{
		free(ppStr[nIndex]);
	}

	return EXIT_SUCCESS;
}







#endif // !Q412_FIZZBUZZ

























