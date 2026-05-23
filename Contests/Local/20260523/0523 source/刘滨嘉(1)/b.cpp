#include <bits/stdc++.h>
using namespace std;
int n,a[500005],c=INT_MAX,g,f1,f5,f8;
bool check()
{
	for(int i=1; i<=n; i++)
	{
		if(a[i]!=500&&a[i]!=800&&a[i]!=1000) return 0;
		if(a[i]==500) f5++;
		else if(a[i]==800) f8++;
		else f1++;
	}
	return 1;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	if(check())
	{
		if(abs(f5+f8-f1)>=abs(f1+f8-f5)) cout << 1000;
		else cout << 800;
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=n; i>=1; i--)
		{
			while(a[i]==a[i-1]) i--;
			if(abs(n-2*i+2)>=c)
			{
				cout << g;
				return 0;
			}
			c=abs(n-2*i+2);
			g=a[i];
		}
	}
	return 0;
 } 
