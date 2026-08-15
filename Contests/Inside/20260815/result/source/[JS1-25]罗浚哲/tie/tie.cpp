#include <bits/stdc++.h>
#define IAK return
#define IOI 0;
#define int long long
using namespace std;
int b[200005], p[200005], q[200005], ans[200005];
struct S
{
	int id, w;
};
S a[200005];
bool cmp(S x, S y)
{
	return x.w < y.w;
}
signed main()
{
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n + 1; i++)
	{
		cin>>a[i].w;
		a[i].id = i;
	}
	for(int j = 1; j <= n; j++)
	{
		cin>>b[j];
	}
	sort(a + 1, a + n + 2, cmp);
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++)
	{
		p[i] = max(p[i - 1], a[i].w - b[i]);
	}
	for(int i = n; i >= 1; i--)
	{
		q[i] = max(q[i + 1], a[i + 1].w - b[i]);
	}
	for(int i = 1; i <= n + 1; i++)
	{
		ans[a[i].id] = max(p[i - 1], q[i]);
	}
	for(int i = 1; i <= n + 1; i++)
	{
		cout<<ans[i]<<' ';
	}
	IAK IOI
}
