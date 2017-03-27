/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

#ifdef Q2_ADDTWONUMBERS

/************************************************************************/
/* 
You are given two non-empty linked lists representing two non-negative integers. T
he digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

/************************************************************************/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {



	struct ListNode* listResultOld = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* listResultNew = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* listResultHead = listResultOld;

	int carryVal = 0;

	int sumVal = 0;

	listResultOld->val = (l1->val + l2->val + carryVal) % 10;

	carryVal = (l1->val + l2->val + carryVal) / 10;

	l1 = l1->next;

	l2 = l2->next;

	listResultOld->next = listResultNew;


	while (l1 || l2 || carryVal)
	{

		sumVal = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carryVal;

		listResultNew->val = sumVal % 10;

		carryVal = sumVal / 10;

		l1 = l1 ? l1->next : l1;

		l2 = l2 ? l2->next : l2;

		listResultOld = listResultNew;


		listResultNew = (struct ListNode*)malloc(sizeof(struct ListNode));

		listResultOld->next = listResultNew;

	}

	free(listResultNew);

	listResultOld->next = NULL;

	return listResultHead;
}

int main()
{
	struct ListNode *l1, *l2, *resultlist, *it;
	l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->val = 2;
	l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->next->val = 4;
	l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l1->next->next->val = 3;
	l1->next->next->next = NULL;

	l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->val = 5;
	l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->next->val = 6;
	l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	l2->next->next->val = 4;
	l2->next->next->next = NULL;

	resultlist = addTwoNumbers(l1, l2);
	for (it = resultlist; it; it = it->next)
	{
		printf("%d,", it->val);
	}
	printf("\n");
	return EXIT_SUCCESS;
}




#endif // Q2_ADDTWONUMBERS



