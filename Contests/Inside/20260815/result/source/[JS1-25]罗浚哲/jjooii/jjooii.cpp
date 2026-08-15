#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005], b[200005], c[200005];
signed main()
{
	freopen("jjooii.in", "r", stdin);
	freopen("jjooii.out", "w", stdout);
	int n, k;
	string s;
	cin>>n>>k>>s;
	for(int i = 1; i <= n; i++)
	{
		a[i] = a[i - 1];
		b[i] = b[i - 1];
		c[i] = c[i - 1];
		if(s[i - 1] == 'J') a[i]++;
		if(s[i - 1] == 'O') b[i]++;
		if(s[i - 1] == 'I') c[i]++;
	}
	int minn = 1e9;
	for(int i = 1; i <= n; i++)
	{
		if(s[i - 1] != 'J') continue;
		int x = lower_bound(a + i, a + n + 1, a[i - 1] + k) - a;
		int y = lower_bound(b + x, b + n + 1, b[x - 1] + k) - b;
		int z = lower_bound(c + y, c + n + 1, c[y - 1] + k) - c;
		if(x > n || y > n || z > n) break;
		minn = min(minn, z - i + 1);
	}
	//cout<<minn<<endl;
	if(minn == 1e9) cout<<-1;
	else cout<<minn - k* 3;
	return 0;
}
