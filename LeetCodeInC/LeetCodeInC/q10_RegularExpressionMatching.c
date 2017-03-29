/*Some Macro tool and basic head file like stdio.h stdlib.h etc. in toolbox.h*/
#include "toolbox.h"

/*question_test_choose*/
#include "question_choose.h"

#ifndef Q10_REGULAR_EXPRESSION_MATCHING

#define DATA(dp, i, j, col)		(*((dp) + (col)*(i) + (j)))
#define BOOL_TO_STR(_bool)		((_bool)?("true"):("false"))
bool isMatch(char* s, char* p) {
	size_t slen = strlen(s);
	size_t plen = strlen(p);
	size_t i, j;
	//uint8_t dp[slen + 1][plen + 1];
	uint8_t *dp = (uint8_t *)malloc(sizeof(uint8_t) * (slen + 1) * (plen + 1));

	for (i = 0; i < slen + 1; i++)
	{
		for (j = 0; j < plen + 1; j++)
		{
			//dp[i][j] = false;
			DATA(dp, i, j, slen) = false;
		}
	}
	*dp = true;
	for (i = 0; i < plen; i++)
	{
		if (i > 0)
			if (p[i] == '*' && DATA(dp, 0, i - 1, slen))
			{
				DATA(dp, 0, i + 1, slen) = true;
			}
	}
	for (i = 0; i < slen; i++)
	{
		for (j = 0; j < plen; j++)
		{
			if (p[j] == '.' || p[j] == s[i])
				DATA(dp, i + 1, j + 1, slen) = DATA(dp, i, j, slen);
			if (p[j] == '*')
			{
				if (j > 0)
					if (p[j - 1] != s[i] && p[j - 1] != '.')
						DATA(dp, i + 1, j + 1, slen) = DATA(dp, i + 1, j - 1, slen);
					else
						DATA(dp, i + 1, j + 1, slen) = (DATA(dp, i + 1, j, slen) || DATA(dp, i, j + 1, slen) || DATA(dp, i + 1, j - 1, slen));
			}
		}
	}
	return DATA(dp, slen, plen, slen);
}

int main()
{
	printf("isMatch(\"aa\",\"a\") -> %s.\n", BOOL_TO_STR(isMatch("aa", "a")));
	printf("isMatch(\"aa\",\"aa\") -> %s.\n", BOOL_TO_STR(isMatch("aa", "aa")));
	printf("isMatch(\"aaa\",\"aa\") -> %s.\n", BOOL_TO_STR(isMatch("aaa", "aa")));
	printf("isMatch(\"aa\",\"a*\") -> %s.\n", BOOL_TO_STR(isMatch("aa", "a*")));
	printf("isMatch(\"aa\", \".*\") -> %s.\n", BOOL_TO_STR(isMatch("aa", ".*")));
	printf("isMatch(\"ab\", \".*\") -> %s.\n", BOOL_TO_STR(isMatch("ab", ".*")));
	printf("isMatch(\"aab\", \"c*a*b\") -> %s\n", BOOL_TO_STR(isMatch("aab", "c*a*b")));
	return EXIT_SUCCESS;
}


#endif
