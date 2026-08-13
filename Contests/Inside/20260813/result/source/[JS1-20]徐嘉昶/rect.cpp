#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[250005],xxkan[250005];
int num[5500005];
int vis[5500005];
int n,m,ans;
inline int wei(int x,int y)
{
	if(x<=0||y<=0) return 0;
	return (x-1)*m+y;
}
signed main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int kkk=wei(i,j);
			cin>>a[kkk];
			a[kkk]-=1;
			xxkan[kkk]=xxkan[wei(i,j-1)]+xxkan[wei(i-1,j)]-xxkan[wei(i-1,j-1)]+a[kkk];
		}
	}
	if(n>m)
	{
		int check=0;
		for(int y_=0;y_<=m;y_++)
		{
			for(int y2=y_+1;y2<=m;y2++)
			{
				check=y_*10000+y2;
				for(int i=0;i<=n;i++)
				{
					int ccc=xxkan[wei(i,y_)]-xxkan[wei(i,y2)];
					if(vis[ccc+2750000]!=check)
					{
						vis[ccc+2750000]=check;
						num[ccc+2750000]=0;
					}
					ans+=num[ccc+2750000];
					++num[ccc+2750000];
				}
			}
		}
	}
	else
	{
		int check=0;
		for(int x1=0;x1<=n;x1++)
		{
			for(int x2=x1+1;x2<=n;x2++)
			{
				check=x1*10000+x2;
				for(int j=0;j<=m;j++)
				{
					int ccc=xxkan[wei(x1,j)]-xxkan[wei(x2,j)];
					if(vis[ccc+2750000]!=check)
					{
						vis[ccc+2750000]=check;
						num[ccc+2750000]=0;
					}
					ans+=num[ccc+2750000];
					++num[ccc+2750000];
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
