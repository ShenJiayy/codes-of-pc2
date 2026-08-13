#include <bits/stdc++.h>
using namespace std;
int n, m;
int e[5005][5005];
int v[100005] = {0};

int main()
{
	//freopen("e.in", "r", stdin);
	//freopen("e.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		e[u][v] = e[v][u] = 1;
	}
	for (int s = 1; s <= n; s++)
	{
		
	}
	return 0;
}
