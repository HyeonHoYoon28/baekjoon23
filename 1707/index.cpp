#include <stdio.h>

#define MAXN 20000

int	edge_num[MAXN + 10];
int	edges[MAXN + 10][MAXN + 10];
int gp[MAXN + 10];

int inv(int x)
{
	return (x == 1 ? 2 : 1);
}

void	dfs(int g_num, int ind)
{
	gp[ind] = g_num;
	for (int i = 0; i < edge_num[ind]; i++)
	{
		if (!gp[edges[ind][i]])
			dfs(inv(g_num), edges[ind][i]);
	}
}

int	main()
{
	int	k, v, e, a, b, ans;

	scanf("%d", &k);
	while (k--)
	{
		ans = 1;
		scanf("%d%d", &v, &e);
		for (int j = 0; j < v; j++)
		{
			edge_num[j] = 0;
			gp[j] = 0;
		}
		for (int j = 0; j < e; j++)
		{
			scanf("%d%d", &a, &b);
			edges[a][edge_num[a]++] = b;
			edges[b][edge_num[b]++] = a;
		}
		for (int j = 0; j < v; j++)
		{
			if (!gp[j])
				dfs(1, j);
		}
		for (int j = 0; j < v; j++)
		{
			for (int i = 0; i < edge_num[j]; i++)
			{
				if (gp[edges[j][i]] == gp[j])
					ans = 0;
			}
		}
		if (ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
