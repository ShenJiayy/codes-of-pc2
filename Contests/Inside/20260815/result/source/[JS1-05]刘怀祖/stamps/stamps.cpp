#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=405;
int n,ans,bk[N];
ll l,t[N],x[N];
void dfs(int nw,int cnt,ll tt,int al,int ar)
{
	if(tt>t[nw])return;
	ans=max(ans,cnt);
	if(ar-al>=2*n||cnt>=n)
	{
		return;
	}
	bk[nw]=1;
	int ls=al-1,rs=ar+1;
	while(ls>0&&t[ls]<tt+x[nw]-x[ls])ls--;
	while(rs<=2*n&&t[rs]<tt+x[rs]-x[nw])rs++;
	if(ls>0)dfs(ls,cnt+1,tt+x[nw]-x[ls],ls,rs-1);
	if(rs<=2*n)dfs(rs,cnt+1,tt+x[rs]-x[nw],ls+1,rs);
	bk[nw]=0;
}
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d%lld",&n,&l);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		x[i+n]=x[i]+l;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i]);
		t[i+n]=t[i];
	}
	dfs(n,1,l-x[n],n,n);
	dfs(n+1,1,x[n+1]-l,n+1,n+1);
	printf("%d",ans);
	return 0;
}
