#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("c.in","r",stdin);freopen("c.out","w",stdout);
	int n;
	cin>>n;
	long long a[2000010];long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];ans+=a[i]/3;a[i]=a[i]%3;
	}
	for(int i=1;i<n;i++)
	{
		if((a[i]+a[i+1])>=3)
		{
			a[i]=0;
			a[i+1]=a[i]+a[i+1]-3;
			ans++;
		}
	}
	cout<<ans;
    return 0;
}

