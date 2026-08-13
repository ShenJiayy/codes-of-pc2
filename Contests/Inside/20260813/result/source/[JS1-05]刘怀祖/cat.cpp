#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int n,pa[N],a[N],bk[N];
vector<int> to[N];
void build(int dep,int x,int f)
{
	a[dep]=pa[x];
	for(auto p:to[x])
	{
		if(p!=f)build(dep+1,p,x);
	}
}
int dfs(int dep,int x)
{
	if(dep>=n)return 0;
	bk[x]=1;
	int ret=0;
	for(int i=x+1;i<=n;i++)
	{
		if(bk[i]||a[i]>a[x])break;
		ret=max(ret,dfs(dep+1,i)+i-x);
	}
	for(int i=x-1;i>0;i--)
	{
		if(bk[i]||a[i]>a[x])break;
		ret=max(ret,dfs(dep+1,i)+x-i);
	}
	bk[x]=0;
	return ret;
}
int main()
{
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&pa[i]);
	int x,y;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		to[x].push_back(y);
		to[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(to[i].size()==1)
		{
			build(1,i,0);
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==n)
		{
			printf("%d",dfs(1,i));
			break;
		}
	}
	return 0;
}
