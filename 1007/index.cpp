#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAXN 20

typedef struct s_point {
	int x;
	int y;
} t_point;

t_point arr[MAXN+10];

void dfs(int point, int n, int cnt, long long *xsum, long long *ysum, long long *x, long long *y)
{
	if (cnt > n / 2 || point - cnt > n / 2)
		return;
	if (point == n)
	{
		if (cnt == n / 2)
		{
			if (*xsum * *xsum + *ysum * *ysum < *x * *x + *y * *y)
			{
				*x = *xsum;
				*y = *ysum;
			}
		}
		return;
	}
	*xsum += arr[point].x;
	*ysum += arr[point].y;
	dfs(point + 1, n, cnt, xsum, ysum, x, y);
	*xsum -= 2 * arr[point].x;
	*ysum -= 2 * arr[point].y;
	dfs(point + 1, n, cnt + 1, xsum, ysum, x, y);
	*xsum += arr[point].x;
	*ysum += arr[point].y;
	return;
}

int main()
{
	int t, n;
	long long x_sum, y_sum, x, y;

	scanf("%d", &t);
	while (t--)
	{
		x = INT_MAX;
		y = INT_MAX;
		x_sum = 0;
		y_sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &(arr[i].x), &(arr[i].y));
		dfs(0, n, 0, &x_sum, &y_sum, &x, &y);
		printf("%.10lf\n", (double)sqrt(x * x + y * y));
	}
}
