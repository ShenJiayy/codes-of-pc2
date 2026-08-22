#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[1000010];
char c[1000010], ans[1000010];

bool check()
{
	int b[1000010];
	int l = 1, r = n;
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 'L')
		{
			b[i] = a[l++];
		}
		else
		{
			b[i] = a[r--];
		}
	}
	for (int i = 1; i <= n / 2; i++)
	{
		if (b[i] != b[n-i+1])
		{
			return 0;
		}
	}
	return 1;
}

void dfs(int x)
{
	if (x > n)
	{
		if (check())
		{
			for (int i = 1; i <= n; i++)
			{
				ans[i] = c[i];
			}
		}
		return ;
	}
	c[x] = 'R';
	dfs(x+1);
	c[x] = 'L';
	dfs(x+1);
	c[x] = '\0';
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		memset(ans, '\0', sizeof ans);
		memset(c, '\0', sizeof c);
		cin >> n;
		n *= 2;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i]; 
		}
		dfs(1);
		if (ans[1] == '\0')
		{
			cout << "-1\n";
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				cout << ans[i];
			}
			cout << "\n";
		}
	}
	return 0;
}
