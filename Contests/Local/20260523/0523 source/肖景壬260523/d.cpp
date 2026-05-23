#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[500005],s[500005],c,d;
int check(int x)
{
	int l=0,r=n,mid,ans1,ans2;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]<=x*d)
		{
			ans1=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	l=0,r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]<=(x+1)*d)
		{
			ans2=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	int ret=0;
	ret+=s[ans2]-s[ans1]-(ans2-ans1)*d*x;
	ret+=(n-ans2)*d;
	return ret;
}
int calcans(int x)
{
	int l=0,r=n,mid,ans1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(a[mid]<=x*d)
		{
			ans1=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return s[n]-s[ans1]-(n-ans1)*x*d+x*c;
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i <= n; i++) s[i]=s[i-1]+a[i];
	while(q--)
	{
		cin>>c>>d;
		int nl=0,nr=1000000003,mid,ans=-1;
		while(nl<=nr)
		{
			mid=(nl+nr)>>1;
			if(check(mid)<c)
			{
				ans=mid;
				nr=mid-1;
			}
			else
			{
				nl=mid+1;
			}
		}
		cout<<calcans(ans)<<endl;
	}
}
