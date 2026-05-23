#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005], b[500005];
map <string, bool> m;
signed main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a + 1, a + n + 1);
	int cur = 0;
	for(int i = 1; i <= n; i++)
	{
		if(m[to_string(a[i])]) continue;
		m[to_string(a[i])] = 1;
		b[++cur] = a[i];
	}
	int i = ceil((cur + 2) * 1.0 / 2);
	cout<<b[i];
	return 0;
}
