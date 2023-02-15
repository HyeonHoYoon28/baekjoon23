#include <stdio.h>
#include <vector>

#define MAXN 20000

using namespace std;

int	edge_num[MAXN + 10];
vector<int> edges[MAXN + 10];
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
		for (int j = 1; j <= v; j++)
		{
			edges[j].clear();
			edge_num[j] = 0;
			gp[j] = 0;
		}
		for (int j = 0; j < e; j++)
		{
			scanf("%d%d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
			edge_num[a]++;
			edge_num[b]++;
		}
		for (int j = 1; j <= v; j++)
		{
			if (!gp[j])
				dfs(1, j);
		}
		for (int j = 1; j <= v; j++)
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
