#include <bits/stdc++.h>
using namespace std;
int n;
vector <int> v[500010];
int e[500010], x[500010];
bitset<500010> u;

int check()
{
	int cnt = 0;
	bitset<500010> used, b;
	for (int i = 1; i <= n; i++)
	{
		if (!u[i])
		{
			continue;
		}
		cnt++;
		for (auto j : v[i])
		{
			used[j] = 1;
		}
	}
	used[0] = 1;
	b.set();
	b >>= 500010-n-1;
//	for (int i = 0; i <= n; i++)
//	{
//		cout << used[i];
//	}
//	cout << "\n";
//	for (int i = 0; i <= n; i++)
//	{
//		cout << b[i];
//	}
//	cout << "\n";
//	cout << "\n";
	if (b != used)
	{
		return 998244353;
	}
	return cnt;
}

int dfs(int x)
{
	int mi = 998244353;
	if (x > n)
	{
		return check();
	}
	mi = dfs(x+1);
	u[x] = 1;
	mi = min(mi, dfs(x+1));
	u[x] = 0;
	return mi;
}

int main()
{
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);
	cin >> n;
	if (n <= 16)
	{
		for (int i = 1; i <= n ; i++)
		{
			cin >> x[i] >> e[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (e[i] - e[j] >= abs(x[i] - x[j]))
				{
					v[i].push_back(j);
				}
			}
		}
		cout << dfs(1);
	}
	else
	{
		set<int> s;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i] >> e[i];
			s.insert(x[i]);
		}
		cout << s.size();
	}
	return 0;
}
