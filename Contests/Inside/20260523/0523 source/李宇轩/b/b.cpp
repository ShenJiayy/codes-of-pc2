#include<bits/stdc++.h>
using namespace std;
int n,a[500005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	int l=0,r=0;
	for(int i=(n+1)/2-1;i>=1&&a[i]==a[(n+1)/2];i--)
	{
		l++;
	}
	for(int i=(n+1)/2+1;i<=n&&a[i]==a[(n+1)/2];i++)
	{
		r++;
	}
	if(n%2==1)
	{
		if(l<=r)
		{
			cout << a[(n+1)/2-l-1];
			return 0;
		}
		else
		{
			cout << a[(n+1)/2+r];
			return 0;
		}
	}
	else
	{
		l++;
		if(l<=r)
		{
			cout << a[(n+1)/2-l];
			return 0;
		}
		else
		{
			cout << a[(n+1)/2+r];
			return 0;
		}
	}
	return 0;
}
