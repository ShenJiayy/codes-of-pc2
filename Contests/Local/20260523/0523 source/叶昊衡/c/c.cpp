#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1)
	{
		cout<<a[1]/3;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int have=a[i]/3;
		int need=3-a[i]%3;
		if(need!=3)
			if(i!=n)
				if(need<=a[i+1])
				{
					a[i+1]-=need;
					need=0;
				}
		a[i]=0;
		if(need==0) have++;
		ans+=have;
	}
	cout<<ans;
}
