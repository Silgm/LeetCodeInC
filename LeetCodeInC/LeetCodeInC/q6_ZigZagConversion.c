/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"



/************************************************************************/
/* 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
/************************************************************************/

#ifndef Q6_ZIGZAG_CONVERSION

char* convert(char* s, int numRows) {
	size_t len = strlen(s);
	size_t curFront = 0, curBack = 2 * (numRows - 1);
	size_t curMoveFront, curMoveBack;
	size_t curResult = 0;
	unsigned char isFirst = 1;
	char* resultStr = (char *)(malloc((len + 1) * sizeof(char)));
	if (numRows == 1)
		strncpy(resultStr, s, len);
	else
	{
		for (; curBack >= curFront; curFront++, curBack--)
		{
			for (curMoveFront = curFront, curMoveBack = curBack; curMoveFront < len;)
			{
				if (curFront != curBack)
				{
					resultStr[curResult] = s[curMoveFront];
					if (curMoveBack < len)
					{
						resultStr[curResult + 1] = s[curMoveBack];
						curResult += 2;
					}
					else
					{
						curResult += 1;
					}
				}
				else
				{
					resultStr[curResult] = s[curMoveFront];
					curResult++;
				}
				if (isFirst)
				{
					curMoveFront += 2 * (2 * (numRows - 1));
					curMoveBack += 2 * (2 * (numRows - 1));

				}
				else
				{
					curMoveFront += (2 * (numRows - 1));
					curMoveBack += (2 * (numRows - 1));
				}
			}
			isFirst = 0;
		}
	}
	resultStr[len] = '\0';
	return resultStr;
}

int main()
{
	char *sz = convert("PAHNAPLSIIGYIR", 3);
	printf("Input:%s\n", "PAHNAPLSIIGYIR");
	printf("Result:%s\n", sz);
	free(sz);
	return EXIT_SUCCESS;
}


#endif



