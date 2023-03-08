#include <stdio.h>

#define MAXN 50

char str[MAXN + 10];

int main()
{
	scanf("%s", str);
	int num = 0, ans = 0, c = 0;
	for (int i = 0; str[i] != 0; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 10 + str[i] - '0';
		if (str[i] == '+')
		{
			if (c == 0)
				ans += num;
			else
				ans -= num;
			num = 0;
		}
		if (str[i] == '-')
		{
			if (c == 0)
				ans += num;
			else
				ans -= num;
			num = 0;
			c = 1;
		}
	}
	if (c == 0)
		ans += num;
	else
		ans -= num;
	printf("%d\n", ans);
}