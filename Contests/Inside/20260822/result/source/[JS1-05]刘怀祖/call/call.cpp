#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=4e5+5,P=998244353;
int n,m,q,a0[N],a[N],op[N],p[N],v[N];
ll tim=1;
vector<int> sn[N];
void dfs(int x)
{
	if(op[x]==1)
	{
		(a[p[x]]+=v[x]*tim%P)%=P;
	}
	else if(op[x]==2)
	{
		(tim*=v[x])%=P;
	}
	else
	{
		int s=sn[x].size();
		for(int i=s-1;i>=0;i--)
		{
			dfs(sn[x][i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a0[i]);
	scanf("%d",&m);
	int c,s;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&op[i]);
		if(op[i]==1)
		{
			scanf("%d%d",&p[i],&v[i]);
		}
		else if(op[i]==2)
		{
			scanf("%d",&v[i]);
		}
		else
		{
			scanf("%d",&c);
			for(int j=0;j<c;j++)
			{
				scanf("%d",&s);
				sn[i].push_back(s);
			}
		}
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&c);
		sn[0].push_back(c);
	}
	dfs(0);
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",(a0[i]*tim%P+a[i])%P);
	}
	return 0;
}
