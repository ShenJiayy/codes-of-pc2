#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
	int l=1,r=n+1;
	int m=n;
	int ma=0,mid=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(m>=1)
	{
		for(int i=r-1;i<=n;i++)
		{
			ma=max(ma,a[i]);
			if(ma==a[i])mid=i;
		}
		if(l+1==mid)
		{
			m--;break;
		}
		if(a[mid]-a[l]<a[l+1])
		{
			break;
		}
		a[mid]=a[mid]-a[l];
		l++;
		if(mid<r)r--;
		//cout<<l<<" "<<r<<" "<<ma<<" "<<a[mid]<<endl;
		ma=0;
		m--;
	}
	cout<<m<<endl;
	for(int i=2;i<=t;i++)
	{
		int k;
		cin>>k;
		for(int k=1;k<=n;k++)
		{
			int i;
			cin>>i;
			cin>>a[i];
		}
		ma=0;
		l=1,r=n+1;
		m=n;
		while(m>=1)
		{
			for(int i=r-1;i<=n;i++)
			{
				ma=max(ma,a[i]);
				if(ma==a[i])mid=i;
			}
			//cout<<l<<" "<<r<<" "<<ma<<" "<<a[mid]<<endl;
			if(l+1==mid)
			{
				m--;break;
			}
			if(a[mid]-a[l]<a[l+1])
			{
				break;
			}
			a[mid]=a[mid]-a[l];
			l++;
			if(mid<r)r--;
			ma=0;
			m--;
		}
		cout<<m<<endl;
	}
    return 0;
}
