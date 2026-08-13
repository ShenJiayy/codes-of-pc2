#include <bits/stdc++.h>
using namespace std;
long long n, q, c, d, mx = 0;
long long a[300010];

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	cin >> n >> q;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (long long i = 1; i <= q; i++)
	{
		cin >> c >> d;
		long long mi = 1e18+1;
		for (long long i = 0; i <= mx / d + 2; i++)
		{
			long long cnt = i * c;
			for (long long j = 1; j <= n; j++)
			{
				cnt += max(0ll, a[j] - d * i);
			}
			mi = min(mi, cnt);
		}
		cout << mi << "\n";
	}
	return 0;
}
