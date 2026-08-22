#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m, c, k;
bitset<70> b1, b2;
unsigned long long a[1000010];

inline unsigned long long read()
{
	unsigned long long x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	cin >> n >> m >> c >> k;
	if (n == 0 && m == 0 && k == 0)
	{
		cout << "18446744073709551616\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		b1 |= a[i];
	}
	for (int i = 1; i <= m; i++)
	{
		int p = read(), q = read();
		b2[p] = 1;
	}
	unsigned long long ans = 1;
	for (int i = 0; i < k; i++)
	{
		if (!b1[i] && b2[i])
		{
			ans *= 1;
		}
		else
		{
			ans <<= 2;
		}
	}
	cout << ans - n;
	return 0;
}
