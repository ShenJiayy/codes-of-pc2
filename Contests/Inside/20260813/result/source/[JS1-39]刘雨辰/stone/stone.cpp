#include<bits/stdc++.h>
using namespace std;
int c[200010];int n,a[200010];
vector<int>b[200010];
struct s
{
	int f,l,c;
};
int main()
{
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
	int cnt=unique(c+1,c+n+1)-c-1;
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(c+1,c+cnt+1,a[i])-c;
	}
	//for(int i=1;i<=n;i+=1)cout<<a[i]<<endl;
	int lc[cnt+10];
	for(int i=1;i<=cnt;i++)
	{
		lc[i]=0;
	}
	vector<s>b;
	for(int i=1;i<=n;i++)
	{
		b.push_back({lc[a[i]],i,a[i]});
		lc[a[i]]=i;
	}
	for(auto i:b)
	{
		if(a[i.f]==i.c&&a[i.l]==i.c)
		{
			for(int j=i.f;j<=i.l;j++)
			{
				a[j]=i.c;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[a[i]]<<endl;
	}
	return 0;
}

