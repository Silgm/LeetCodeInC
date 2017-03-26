
/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

#define Q1_TWOSUM
#ifdef Q1_TWOSUM

int* twoSum(int* nums, int numsSize, int target);

int main()
{

	int nums[] = { 2, 7, 11, 15 };
	int *result = twoSum(nums, MF_LENOF_ARR(nums), 9);
	printf("%d,%d\n", result[0], result[1]);
	return EXIT_SUCCESS;
}

/************************************************************************/
/* 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
/************************************************************************/

int* twoSum(int* nums, int numsSize, int target) {
	int* pnResult = (int *)(malloc(2 * sizeof(int)));
	int loopi, loopj;
	for (loopi = 0; loopi < numsSize - 1; loopi++)
	{
		for (loopj = loopi + 1; loopj < numsSize; loopj++)
		{
			if (nums[loopi] + nums[loopj] == target)
			{
				pnResult[0] = loopi;
				pnResult[1] = loopj;
				return pnResult;
			}
		}
	}
	free(pnResult);
	return NULL;
}

#endif


