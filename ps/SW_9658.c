//[SW] 9658 : 전봇대

#include <stdio.h>
#include <string.h>

char num[100002];

int main()
{
	int TC;
	int len;
	int sum;

	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; test_case++)
	{
		scanf("%s", num);
		sum = (num[0] - '0') * 10 + (num[1] - '0');
		if (num[2] >= '5')
			sum++;
		len = strlen(num) - 1;
		if (sum > 99)
		{
			len++;
			sum = 10;
		}
		printf("#%d ", test_case);
		printf("%d.%d*10^%d\n", sum / 10, sum % 10, len);
	}
	return (0);
}