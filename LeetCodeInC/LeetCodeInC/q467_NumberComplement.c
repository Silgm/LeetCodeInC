/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

/************************************************************************/
/* 
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer��s binary representation.

Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

*/
/************************************************************************/

#ifndef Q476_NUMBER_COMPLEMENT

int findComplement(int num) {
	unsigned mask = ~0;
	while (num & mask) mask <<= 1;
	return ~mask & ~num;
}

int main()
{
	int input1 = 5, intpu2 = 2;
	printf("Q476:Number Complement.\n");
	printf("%d -> %d.\n", input1, findComplement(input1));
	printf("%d -> %d.\n", intpu2, findComplement(intpu2));

	return EXIT_SUCCESS;
}

#endif // !Q476_NUMBER_COMPLEMENT

