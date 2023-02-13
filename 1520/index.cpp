#include <stdio.h>
#include <algorithm>

#define MAXN 500

using namespace std;

typedef struct s_coor
{
	int x;
	int y;
	int h;
} t_coor;


int map[MAXN + 10][MAXN + 10];
int di[MAXN + 10][MAXN + 10];
t_coor li[MAXN * MAXN];

int xd[4] = {1, -1, 0, 0};
int yd[4] = {0, 0, 1, -1};

int	cmpp(t_coor a, t_coor b)
{
	return (a.h > b.h);
}

int	main()
{
	int n, m;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
			li[i * m + j].x = i;
			li[i * m + j].y = j;
			li[i * m + j].h = map[i][j];
		}
	}
	sort(li, li + n * m, cmpp);
	di[0][0] = 1;
	for (int i = 0; i < n * m; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (li[i].x + xd[j] < 0 || li[i].x + xd[j] >= n || li[i].y + yd[j] < 0 || li[i].y + yd[j] >= m)
				continue;
			if (map[li[i].x + xd[j]][li[i].y + yd[j]] < map[li[i].x][li[i].y])
				di[li[i].x + xd[j]][li[i].y + yd[j]] += di[li[i].x][li[i].y];
		}
	}
	printf("%d\n", di[n - 1][m - 1]);
}
