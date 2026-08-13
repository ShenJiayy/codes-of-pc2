#include <bits/stdc++.h>
#define int long long
using namespace std;
int sum[10], a[10][500005];
signed main()
{
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	int n, P;
	cin>>n>>P;
	int cnt = 0;
	while(n--)
	{
		int x, y;
		cin>>x>>y;
		while(sum[x] >= 1 && a[x][sum[x]] > y)
		{
			sum[x]--;
			cnt++;
		}
		if(a[x][sum[x]] == y) continue;
		a[x][++sum[x]] = y;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
