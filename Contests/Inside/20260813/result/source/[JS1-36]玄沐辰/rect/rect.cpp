#include <bits/stdc++.h>
using namespace std;
long long n, m, cnt = 0;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	cin >> n >> m;
	int a[n+5][m+5], b[n+5][m+5];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			a[i][j] = read();
			b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
			for (int k = 1; k <= i; ++k)
			{
				for (int l = 1; l <= j; ++l)
				{
					cnt += b[i][j] - b[k-1][j] - b[i][l-1] + b[k-1][l-1] == (i - k + 1) * (j - l + 1);
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
