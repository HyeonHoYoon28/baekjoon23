#include <stdio.h>

int sbm_size(int N)
{
	int ret = 1;
	while (N--)
		ret *= 2;
	return ret;
}

int sbm(int N, int *r, int *c)
{
	int t = sbm_size(N - 1);
	if (*r < t)
	{
		if (*c < t)
			return 0;
		else
		{
			*c -= t;
			return 1;
		}
	}
	else
	{
		if (*c < t)
		{
			*r -= t;
			return 2;
		}
		else
		{
			*r -= t;
			*c -= t;
			return 3;
		}
	}

}

int main()
{
	int N, r, c, ans = 0, t;
	scanf("%d%d%d", &N, &r, &c);
	while (N)
	{
		t = sbm_size(N - 1);
		ans += sbm(N, &r, &c) * t * t;
		N--;
	}
	printf("%d\n", ans);
}