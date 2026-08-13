#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
long long ans;
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> n;
	cin >> a[1];
	for(int i=1;i<n;i++)
	{
		cin >> a[i+1];
		if(a[i+1]-(3-a[i]%3)>=0)
		{
			a[i+1]-=(3-a[i]%3);
			ans++;
		}
		ans+=a[i]/3;
	}
	cout << ans+a[n]/3;
	return 0;
}
