#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[300005];
int s[300005];
int n,q,c,d;
int solve(int x)
{
	int pos=lower_bound(a+1,a+n+1,x*d)-a;
//	cout<<pos<<" "<<x<<" "<<c*x+(s[n]-s[pos-1]-d*x*(n-pos+1))<<'\n';
	return c*x+(s[n]-s[pos-1]-d*x*(n-pos+1));
}
signed main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int k=__lg(n)+3;
	while(q--)
	{
		cin>>c>>d;
		int ans=1e18;
		int l=0,r=a[n]/d+1,lmid,rmid,lans,rans;
		while(l<r-k)
		{
			lmid=l+(r-l)/3.0;
			rmid=l+(r-l)/3.0*2.0;
			lans=solve(lmid);
			rans=solve(rmid);
			if(lans<rans)
			{
				r=rmid;
			}
			else l=lmid;
		}
		for(int i=l;i<=r;i++)
		{
			ans=min(ans,solve(i));
		}
		cout<<ans<<'\n';
	}
}
