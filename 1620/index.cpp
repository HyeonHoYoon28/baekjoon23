#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

#define MAXN 20
#define MAXM 100000

using namespace std;

typedef struct s_pokemon
{
	int index;
	char name[MAXN + 10];
} t_pokemon;

bool cmp(t_pokemon a, t_pokemon b)
{
	return strcmp(a.name, b.name) < 0;
}

vector<t_pokemon> V;
int finder[MAXM + 10];
char tmp_str[MAXN + 10];

int find_by_name(char *name, int n)
{
	int s = 0, e = n - 1, m;

	// printf("\n%s\n", name);
	while (s <= e)
	{
		m = (s + e) / 2;
		// printf("%d %d %s\n", s, e, V[m].name);
		if (strcmp(V[m].name, name) == 0)
			return V[m].index;
		else if (strcmp(V[m].name, name) < 0)
			s = m + 1;
		else
			e = m - 1;
	}
	return -1;
}

int main()
{
	int n, m;
	t_pokemon tmp;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		tmp.index = i + 1;
		scanf("%s", tmp.name);
		V.push_back(tmp);
	}
	sort(V.begin(), V.end(), cmp);
	for (int i = 0; i < n; i++)
		finder[V[i].index] = i;
	// for (int i = 0; i < n; i++)
	// 	printf("%d %s\n", V[i].index, V[i].name);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", tmp_str);
		if (tmp_str[0] >= '0' && tmp_str[0] <= '9')
			printf("%s\n", V[finder[atoi((const char *)tmp_str)]].name);
		else
			printf("%d\n", find_by_name(tmp_str, n));
	}
}