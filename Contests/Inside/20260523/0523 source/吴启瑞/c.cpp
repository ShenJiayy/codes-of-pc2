#include <bits/stdc++.h>
using namespace std;
int n;

int main()
{
	//freopen("c.in", "r", stdin);
	//freopen("c.out", "w", stdout);
	
	cin >> n;
	vector <long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += a[i] / 3;
		a[i] %= 3;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == 0) continue;
		int need = 3 - a[i];
		if (a[i + 1] >= need)
		{
			ans++;
			a[i + 1] -= need;
			a[i] = 0;
		}
	}
	cout << ans;
	return 0;
}
