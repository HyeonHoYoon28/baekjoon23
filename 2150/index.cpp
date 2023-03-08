#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

#define MAXN 10000

using namespace std;

typedef struct s_data
{
	int top;
	priority_queue<int> pq;
} t_data;

int c1[MAXN + 10],
	c2[MAXN + 10];
vector<int> V1[MAXN + 10];
vector<int> V2[MAXN + 10];
vector<t_data> V3;
t_data tmp;
// priority_queue<int> pq[MAXN + 10];
stack<int> S;
int k;

void dfs1(int i)
{
	c1[i] = 1;
	int t = V1[i].size();
	for (int j = 0; j < t; j++)
	{
		if (!c1[V1[i][j]])
			dfs1(V1[i][j]);
	}
	S.push(i);
	// printf("%d ", i);
	return;
}

void dfs2(int i)
{
	c2[i] = 1;
	int t = V2[i].size();
	for (int j = 0; j < t; j++)
	{
		if (!c2[V2[i][j]])
			dfs2(V2[i][j]);
	}
	tmp.pq.push(-1 * i);
	// printf("%d ", i);
	return;
}

bool cmp(t_data a, t_data b)
{
	return a.top > b.top;
}

int main()
{
	int V, E, a, b;
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		scanf("%d%d", &a, &b);
		V1[a].push_back(b);
		V2[b].push_back(a);
	}
	for (int i = 1; i <= V; i++)
	{
		if (!c1[i])
			dfs1(i);
	}
	// printf("\n");
	while (!S.empty())
	{
		if (!c2[S.top()])
		{
			while (!tmp.pq.empty())
				tmp.pq.pop();
			dfs2(S.top());
			tmp.top = tmp.pq.top();
			V3.push_back(tmp);
			// printf("\n");
		}
		S.pop();
	}
	k = V3.size();
	sort(V3.begin(), V3.end(), cmp);
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
	{
		while (!V3[i].pq.empty())
		{
			printf("%d ", -1 * V3[i].pq.top());
			V3[i].pq.pop();
		}
		printf("-1\n");
	}
}