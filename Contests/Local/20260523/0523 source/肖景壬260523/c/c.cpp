#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
signed main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++)
	{
		int pp=(a[i])/3;
		a[i]-=pp*3;
		ans+=pp;
		if(a[i]==1)
		{
			if(a[i+1]>=2)
			{
				a[i+1]-=2;
				ans++;
				a[i]=0;
			}
		}
		else if(a[i]==2)
		{
			if(a[i+1]>=1)
			{
				a[i+1]--;
				ans++;
				a[i]=0;
			}
		}
	}
	cout<<ans;
}
