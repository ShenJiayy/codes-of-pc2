#include <bits/stdc++.h>
using namespace std;
int n;
int a[200010];
map<int, int> mp;

int main()
{
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mp[a[i]] = i;
	}
	int i = 1;
	while (i <= n)
	{
		int c = a[i];
		while (i <= n && i <= mp[c])
		{
			cout << c << "\n";
			i++;
		}
	}
	return 0;
}
