#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	long long s=0;
	for(int i=1; i<=n; i++)
	{
		s+=a[i]/3;
		a[i]=a[i]%3;
	}
	for(int i=1; i<=n-1; i++)
	{
		if((a[i]==1&&a[i+1]==2)||(a[i]==2&&a[i+1]==1))
		{
			s++;
			a[i]=a[i+1]=0;
		}
	}
	cout << s;
	return 0;
 } 
