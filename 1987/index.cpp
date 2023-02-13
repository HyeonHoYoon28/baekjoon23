#include <stdio.h>

#define MAXN 20

char map[MAXN + 10][MAXN + 10];
int check[MAXN + 10][MAXN + 10];
int charset[26];
int n, m;

int maax(int a, int b)
{
	return a > b ? a : b;
}

int	dfs(int sx, int sy)
{
	int xd[4] = {1, -1, 0, 0};
	int yd[4] = {0, 0, 1, -1};
	int ret = 0;

	for (int i = 0; i < 4; i++)
	{
		if (sx + xd[i] == 0 || sx + xd[i] == n + 1 || sy + yd[i] == 0 || sy + yd[i] == m + 1)
			continue;
		else if (!charset[map[sx + xd[i]][sy + yd[i]] - 'A'] && !check[sx + xd[i]][sy + yd[i]])
		{
			check[sx + xd[i]][sy + yd[i]] = 1;
			charset[map[sx + xd[i]][sy + yd[i]] - 'A']++;
			ret = maax(ret, dfs(sx + xd[i], sy + yd[i]) + 1);
			check[sx + xd[i]][sy + yd[i]] = 0;
			charset[map[sx + xd[i]][sy + yd[i]] - 'A']--;
		}
	}
	return ret;
}

int	main()
{
	char buf;

	scanf("%d%d", &n, &m);
	scanf("%c", &buf);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			scanf("%c", &map[i][j]);
		scanf("%c", &buf);
	}
	check[1][1] = 1;
	charset[map[1][1] - 'A']++;
	printf("%d\n", dfs(1, 1) + 1);
}
