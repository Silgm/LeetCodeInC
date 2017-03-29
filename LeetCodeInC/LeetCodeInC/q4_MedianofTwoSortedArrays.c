/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

#ifndef Q4_MEDIAN_OF_TWO_SORTED_ARRAYS
/************************************************************************/
/* 
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
/************************************************************************/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int nums1Index = 0, nums2Index = 0, numsComIndex = 0;
	int comNumsSize = nums1Size + nums2Size;
	int *comNums = (int *)malloc(sizeof(int) * comNumsSize);
	double result = 0.0f;
	while (nums1Index < nums1Size || nums2Index < nums2Size)
		if (nums2Index == nums2Size ||
			nums1Index < nums1Size		&&
			nums1[nums1Index] < nums2[nums2Index]
			)
			comNums[numsComIndex++] = nums1[nums1Index++];
		else
			comNums[numsComIndex++] = nums2[nums2Index++];


	if (comNumsSize % 2)
		result = (double)(comNums[comNumsSize / 2]);
	else
		result = (double)(comNums[comNumsSize / 2] + comNums[comNumsSize / 2 - 1]) / 2.0f;

	free(comNums);

	return result;
}


int main()
{
	int nums1[] = { 1,3 };
	int nums2[] = { 2 };

	int nums3[] = { 1,2 };
	int nums4[] = { 3,4 };

	printf("Median:%lf\n", findMedianSortedArrays(nums1, MF_LENOF_ARR(nums1), nums2, MF_LENOF_ARR(nums2)));
	
	printf("Median:%lf\n", findMedianSortedArrays(nums3, MF_LENOF_ARR(nums3), nums4, MF_LENOF_ARR(nums4)));
	
	return EXIT_SUCCESS;
}

#endif // Q4_MEDIAN_OF_TWO_SORTED_ARRAYS

