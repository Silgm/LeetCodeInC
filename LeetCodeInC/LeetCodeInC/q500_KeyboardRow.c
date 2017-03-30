/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"


/************************************************************************/
/* 
Given a List of words, 
return the words that can be typed using letters of alphabet 
on only one row's of American keyboard like the image below.


American keyboard

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

*/
/************************************************************************/

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** findWords(char** words, int wordsSize, int* returnSize) {
	/*qwertyuiop asdfghjkl zxcvbnm*/
	//char keyboard[] = {};
	char *thisChar = NULL, *tmpSz = NULL;
	char **tmpResultWords = NULL, **resultWords = NULL;
	/*This char array mask the postion of every alphabet on the keyboard ;0 is line 1; 1 is line 2; 2 is line 3 */
	char flagKeyboard[] = { 1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2, };
	char flag = 1;
	
	int resultSize = 0, nIndexI = 0;
	
	for (nIndexI = 0; nIndexI < wordsSize; nIndexI++)
	{
		for (thisChar = words[nIndexI], flag = flagKeyboard[tolower(*thisChar) - 'a'], thisChar++;
			*thisChar && flagKeyboard[tolower(*thisChar) - 'a'] == flag;
			thisChar++);
		/*Find a result*/
		if (!*thisChar)
		{
			resultSize++;
			tmpSz = (char *)malloc(sizeof(char) * (strlen(words[nIndexI]) + 1));
			strcpy(tmpSz, words[nIndexI]);
			tmpResultWords = resultWords;
			resultWords = (char **)realloc(tmpResultWords, sizeof(char *));
			resultWords[resultSize - 1] = tmpSz;
		}
	}
	*returnSize = resultSize;
	return resultWords;
}

#ifndef Q500_KEYBOARD_ROW

int main()
{
	char *input[] = { "Hello", "Alaska", "Dad", "Peace" };
	int returnSize = 0;
	int nIndexI = 0;
	char **result = findWords(input, 4, &returnSize);

	for (nIndexI = 0; nIndexI < returnSize; nIndexI++)
	{
		printf("%s,", result[nIndexI]);
	}
	puts("");
	
	for (nIndexI = 0; nIndexI < returnSize; nIndexI++)
	{
		free(result[nIndexI]);
	}

	return EXIT_SUCCESS;
}






#endif // !Q500_KEYBOARD_ROW


