#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> V1, V2, res;
string tmp;

int main()
{
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		// scanf("%s", tmp);
		cin >> tmp;
		V1.push_back(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		// scanf("%s", tmp);
		cin >> tmp;
		V2.push_back(tmp);
	}
	sort(V1.begin(), V1.end());
	sort(V2.begin(), V2.end());
	// for (int i = 0; i < n; i++)
	// 	cout << V1[i] << endl;
	// printf("\n");
	// for (int i = 0; i < m; i++)
	// 	cout << V2[i] << endl;
	// printf("\n");
	int p1 = 0, p2 = 0;
	while (p1 < n && p2 < m)
	{
		// printf("%d %d\n", p1, p2);
		if (V1[p1].compare(V2[p2]) == 0)
		{
			// printf("%s\n", V1[p1]);
			// cout << V1[p1] << endl;
			res.push_back(V1[p1]);
			ans++;
			p1++;
			p2++;
		}
		else if (V2[p2].compare(V1[p1]) < 0)
		{
			if (p2 == m)
				break;
			p2++;
		}
		else
		{
			if (p1 == n)
				break;
			p1++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < ans; i++)
		cout << res[i] << endl;
}