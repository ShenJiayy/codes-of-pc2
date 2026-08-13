#include <bits/stdc++.h>
using namespace std;
long long add, n, ans, a[200010];

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add += a[i];
		if (a[i] == 0)
		{
			ans += add / 3;
			add = 0;
		}
	}
	ans += add / 3;
	cout << ans;
	return 0;
}
