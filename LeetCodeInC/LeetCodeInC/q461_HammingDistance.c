/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"



/************************************************************************/
/* 
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ¡Ü x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
	   ¡ü   ¡ü

The above arrows point to positions where the corresponding bits are different.
*/
/************************************************************************/

#ifndef Q461_HAMMINGDISTANCE

int hammingDistance(int x, int y) {
	int nCnt;
	for (nCnt = 0; x || y; (x % 2 != y % 2 && nCnt++), x >>= 1, y >>= 1);
	return nCnt;
}

int main()
{
	int x = 1, y = 4;
	printf("Hamming Distance between %d and %d.:\n", x, y);
	printf("%d\n", hammingDistance(x, y));
	return EXIT_SUCCESS;
}

#endif


