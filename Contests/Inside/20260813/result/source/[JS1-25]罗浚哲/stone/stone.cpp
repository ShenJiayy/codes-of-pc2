#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
map <int, int> m;
signed main()
{
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		m[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		int g = m[a[i]];
		for(int j = i + 1; j < g; j++)
		{
			a[j] = a[i];
		}
		i = g;
	}
	for(int i = 1; i <= n; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
