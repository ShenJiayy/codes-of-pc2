#include<bits/stdc++.h>
using namespace std;
int n,fa[500010];
struct ren
{
	int x,e;
}a[500010];
bool cmp(ren a,ren b)
{
	return a.x<b.x;
}
void tsk1()
{
	int x2[500010];
	for(int i=1;i<=n;i++)
	{
		x2[i]=a[i].x;
	}
	sort(x2+1,x2+n+1);
	int ans=unique(x2+1,x2+n+1)-x2-1;
	cout<<ans;
}
int find(int x)
{
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
int main()
{
    freopen("ad.in","r",stdin);
    freopen("ad.out","w",stdout);
	cin>>n;bool flg=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].e;
		if(a[i].e!=a[i-1].e&&i!=1)flg=0;
	}
	if(flg)
	{
		tsk1();return 0;
	}
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	//cout<<endl;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(abs(a[j].x-a[i].x)<=(a[i].e-a[j].e))
			{
				int b;
				b=find(i);
				fa[j]=b;
				//cout<<i<<" "<<j<<endl;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

