#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],b[300005];
long long ans;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	cin >> n >> m;
	for(long long i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	while(m--)
	{
		long long x,y;
		cin >> x >> y;
		long long cnt=(x+y-1)/y;
		long long k=a[n-cnt+1]/y;
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			ans+=max((long long)0,a[i]-k*y);
		}
		ans+=k*x;
		long long ans1=0;
		for(long long i=1;i<=n;i++)
		{
			ans1+=max((long long)0,a[i]-(k+1)*y);
		}
		ans1+=(k+1)*x;
		cout << min(ans,ans1) << '\n';
	}
	return 0;
}
