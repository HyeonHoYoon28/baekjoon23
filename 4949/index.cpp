#include <stdio.h>

#define MAXN 100

char str[MAXN + 10];
char mod[MAXN + 10];
/*
void printlist(char *str, int n)
{
	for (int i = 0; i < n; i++)
		printf("%c ", *(str + i));
	printf("\n");
}
*/
int main()
{
	char buf;
	int j, k, ans;

	while (1)
	{
		j = 0;
		while (1)
		{
			scanf("%c", &str[j]);
			if (str[j++] == '.')
				break;
		}
		if (j == 1)
			break;
		scanf("%c", &buf);
		k = 0;
		ans = 1;
		for (int i = 0; i < j - 1; i++)
		{
			if (str[i] == '(')
				mod[k++] = '(';
			if (str[i] == '[')
				mod[k++] = '[';
			if (str[i] == ')')
			{
				if (mod[k - 1] == '(')
					k--;
				else
				{
					ans = 0;
					break;
				}
			}
			if (str[i] == ']')
			{
				if (mod[k - 1] == '[')
					k--;
				else
				{
					ans = 0;
					break;
				}
			}
			//printf("%c | ", str[i]);
			//printlist(mod, k);
		}
		if (!ans || k)
			printf("no\n");
		else
			printf("yes\n");
	}
}
