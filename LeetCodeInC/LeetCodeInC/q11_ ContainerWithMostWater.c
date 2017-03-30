/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

/************************************************************************/
/* 
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/
/************************************************************************/

#ifndef Q11_CONTAINER_WITH_MOST_WATER

#define MF_MIN2(x, y)   ((x < y)?(x):(y))

int maxArea(int* height, int heightSize) {

	int nIndexLeft = 0, nIndexRight = heightSize - 1;

	int nMaxContainer = 0, nNewContainer = 0;

	while (nIndexLeft < nIndexRight)
	{
		if (nMaxContainer < (nNewContainer = (nIndexRight - nIndexLeft)*MF_MIN2(height[nIndexLeft], height[nIndexRight])))
		{
			nMaxContainer = nNewContainer;
		}

		if (height[nIndexLeft] > height[nIndexRight])
			nIndexRight--;
		else
			nIndexLeft++;
	}

	return nMaxContainer;
}

int main()
{
	int arr1[] = { 1,1 };
	int arr2[] = { 2,2,4,5,6 };
	int arr3[] = { 2,7,4,4,5 };
	printf("%d\n", maxArea(arr1, MF_LENOF_ARR(arr1)));
	printf("%d\n", maxArea(arr2, MF_LENOF_ARR(arr2)));
	printf("%d\n", maxArea(arr3, MF_LENOF_ARR(arr3)));
	return EXIT_SUCCESS;
}



#endif



