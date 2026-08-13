#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5;
int n,a[N],i=1,ans=1e9,m=0;

bool cmp (int a,int b){return a>b;}

signed main()
{
	freopen ("b.in","r",stdin);
	freopen ("b.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort (a+1,a+n+1,cmp);
	while (i<=n)
	{
		while (i<n&&a[i+1]==a[i]) i++;
		int t=abs(n-i-i);
		if (t<ans) ans=t,m=a[i];
		i++;
	}
	cout<<m;
	return 0;
}
