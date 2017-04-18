/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

/************************************************************************/
/* 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

Result:
1

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

*/
/************************************************************************/

#ifndef Q45_JUMP_GAME_II
int jump(int* nums, int numsSize) {
	int step = 0, curMax = 0, curRch = 0;
	for (int index = 0; index < numsSize; index++)
	{
		if (curRch < index)
		{
			step++;
			curRch = curMax;
		}
		curMax = (curMax > nums[index] + index) ? curMax : nums[index] + index;
	}
	return step;
}
int main() {
	int arr[] = { 2,3,1,1,4 };
	printf("%d\n", jump(arr, MF_LENOF_ARR(arr)));
	return EXIT_SUCCESS;
}



#endif
