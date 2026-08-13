#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[505][505], s[250005], sb[505][505], sy[505][505], b[250005];
signed main()
{
	freopen("rect4.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	if(n == 1)
	{
		for(int i = 1; i <= m; i++)
		{
			cin>>b[i];
			s[i] = s[i - 1] + b[i];
		}
		int cnt = 0;
		for(int i = 1; i <= m; i++)
		{
			for(int j = i; j <= m; j++)
			{
				int sum = s[j] - s[i - 1];
				if(sum == j - i + 1)
				{
					cnt++;
				}
			}
		}
		cout<<cnt;
		return 0;
	}
	bool flag = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin>>a[i][j];
			if(a[i][j] != 0 && a[i][j] != 1) flag = 1;
			sy[i][j] = sy[i][j - 1] + a[i][j];
			for(int k = 1; k <= i; k++)
			{
				sb[i][j] += sy[k][j];
			}
		}
	}
	/*
	cout<<"----------\n";
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cout<<sb[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	if(1)
	{
		
		int cnt = 0;
		for(int x1 = 1; x1 <= n; x1++)
		{
			for(int y1 = 1; y1 <=m; y1++)
			{
				for(int x2 = x1; x2 <= n; x2++)
				{
					for(int y2 = y1; y2 <= m; y2++)
					{
						int sum = sb[x2][y2] - sb[x2][y1 - 1] - sb[x1 - 1][y2] + sb[x1 - 1][y1 - 1];
						if(sum == (x2 - x1 + 1) * (y2 - y1 + 1))
						{
							cnt++;
						}
					}
				}
			}
		}
		cout<<cnt;
		
	}
	return 0;
}
