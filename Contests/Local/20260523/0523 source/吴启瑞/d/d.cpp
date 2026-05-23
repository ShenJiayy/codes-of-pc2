#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100005], c[100005], d[100005];

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= q; i++)
	{
		cin >> c[i] >> d[i];
	} 
	int dp[120][120][120];
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= q; j++)
		{
			for (int k = 1; k <= a[i]; k++)
			{
				
			}
		}
	}
	return 0;
}
