/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"


#ifndef Q3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS

/************************************************************************/
/* 
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
"pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question.
*/
/************************************************************************/

int lengthOfLongestSubstring(char* s)
{
	char* p = s, max = 0;
	char existTable[256] = { 0 };
	while (*s != '\0')
	{
		//s,p为边界, 如果存在s,p之间存在着重复值的时候
		//就把边界s更新之最近无重复值那里
		if (existTable[(size_t)(*s)])
		{
			max = (max > s - p) ? (max) : (s - p);
			while (*s != *p)//当没有找到重复值时
			{
				existTable[(size_t)(*p)] = 0;
				p++;
			}
			s++;
			p++;
		}
		else
		{
			existTable[(size_t)(*s)] = 1;
			s++;
		}
	}
	max = (max > s - p) ? (max) : (s - p);
	return max;
}

int main()
{
	printf("%s:%d\n", "abcabcbb", lengthOfLongestSubstring("abcabcbb"));

	printf("%s:%d\n", "bbbbb", lengthOfLongestSubstring("bbbbb"));

	printf("%s:%d\n", "pwwkew", lengthOfLongestSubstring("pwwkew"));

	return EXIT_SUCCESS;
}


#endif // Q3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS
