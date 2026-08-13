#include <bits/stdc++.h>
using namespace std;
map <int, bool> m;
int main()
{
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);
	int n;
	cin>>n;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int x, e;
		cin>>x>>e;
		if(m[x] == 0) cnt++;
		m[x] = 1;
	}
	cout<<cnt;
	return 0;
}
