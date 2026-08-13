#include<bits/stdc++.h>
using namespace std;
int n,a[200020],num[200020],b[200020];
int c[200020],p[200020],f[200020];
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		num[i]=a[i];
	}
	sort(a+1,a+n+1);
	int cnt=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;i++) 
	{
		int x=num[i];
		num[i]=lower_bound(a+1,a+cnt+1,num[i])-a;
		b[num[i]]=x;
	}
	for(int i=n;i>=1;i--)
	{
		if(f[num[i]]>0) p[i]=f[num[i]];
		f[num[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		c[i]=num[i];
		if(p[i]>0) 
		{
			for(int j=i+1;j<=p[i];j++) c[j]=c[i];
			i=p[i]-1;
		}
	}
	for(int i=1;i<=n;i++) cout<<b[c[i]]<<endl;
	return 0;
}
