#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==0) continue;
		int x=a[i]/3ll;
		ans+=x;
		a[i]-=x*3ll;
		if(a[i]&&a[i]+a[i+1]>=3)
		{
			a[i+1]=a[i+1]+a[i]-3;
			a[i]=0;
			ans++;
		}
//		if(i>2)
//		{
//			if(a[i-2]>0&&a[i-1]>0)
//			{
//				int x=min({a[i-2],a[i-1],a[i]});
//				a[i-2]-=x,a[i-1]-=x,a[i]-=x;
//				ans+=x;
//			}
//		}
	}
	cout<<ans+a[n]/3;
}

