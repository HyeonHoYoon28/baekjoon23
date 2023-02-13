#include <stdio.h>

#define MAXN 500

int map[MAXN + 10][MAXN + 10];
int check[MAXN + 10][MAXN + 10];

void	dfs(int sx, int sy, int ex, int ey, int *cnt)
{
	int xd[4] = {1, -1, 0, 0};
	int yd[4] = {0, 0, 1, -1};

	if (sx == ex - 1 && sy == ey - 1)
	{
		(*cnt)++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (sx + xd[i] < 0 || sx + xd[i] >= ex || sy + yd[i] < 0 || sy + yd[i] >= ey)
			continue;
		else if (map[sx + xd[i]][sy + yd[i]] < map[sx][sy] && !check[sx + xd[i]][sy + yd[i]])
		{
			check[sx + xd[i]][sy + yd[i]] = 1;
			dfs(sx + xd[i], sy + yd[i], ex, ey, cnt);
			check[sx + xd[i]][sy + yd[i]] = 0;
		}
	}
}

int	main()
{
	int n, m, cnt = 0;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	check[0][0] = 1;
	dfs(0, 0, n, m, &cnt);
	printf("%d\n", cnt);
}