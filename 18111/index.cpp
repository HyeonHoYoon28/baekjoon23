#include <stdio.h>
#include <limits.h>

#define MAXN 500

int world[MAXN+10][MAXN+10];

int maax(int a, int b)
{
	return (a > b) ? a : b;
}

int miin(int a, int b)
{
	return (a > b) ? b : a;
}

int main() {
	int n, m, b, Mb, mb, time, tblocks, ttime, ans;

	scanf("%d%d%d", &n, &m, &b);
	Mb = -1;
	mb = 257;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &world[i][j]);
			Mb = maax(Mb, world[i][j]);
			mb = miin(mb, world[i][j]);
		}
	}
	time = INT_MAX;
	for (int k = mb; k <= Mb; k++)
	{
		ttime = 0;
		tblocks = b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (world[i][j] >= k)
				{
					ttime += 2 * (world[i][j] - k);
					tblocks += world[i][j] - k;
				}
				else
				{
					ttime += k - world[i][j];
					tblocks -= k - world[i][j];
				}
			}
		}
		if (tblocks >= 0 && time >= ttime)
		{
			ans = k;
			time = ttime;
		}
	}
	printf("%d %d\n", time, ans);
	return 0;
}

			
