#include <bits/stdc++.h>
using namespace std;
int n, p, cnt = 0;
priority_queue<int> q[10];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		while (!q[a].empty() && q[a].top() > b)
		{
			q[a].pop();
			cnt++;
		}
		if (!q[a].empty() && q[a].top() == b)
		{
			continue;
		}
		q[a].push(b), cnt++;
	}
	cout <<  cnt;
	return 0;
}
