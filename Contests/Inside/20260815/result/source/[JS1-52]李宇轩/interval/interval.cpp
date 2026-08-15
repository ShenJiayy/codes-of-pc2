#include<bits/stdc++.h>
using namespace std;
int n,m,l[500005],r[500005];
int a[500005],cnt,ans=2147483647;
int main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i] >> r[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=n;j++)
			if(l[j]<=l[i]&&r[j]>=l[i])
				a[++cnt]=r[j]-l[j];
		sort(a+1,a+cnt+1);
		for(int j=1;j<=cnt-m+1;j++)
			ans=min(ans,a[j+m-1]-a[j]);
		cnt=0;
		for(int j=1;j<=n;j++)
			if(l[j]<=r[i]&&r[j]>=r[i])
				a[++cnt]=r[j]-l[j];
		sort(a+1,a+cnt+1);
		for(int j=1;j<=cnt-m+1;j++)
			ans=min(ans,a[j+m-1]-a[j]);
	}
	cout << ans;
	return 0;
}
