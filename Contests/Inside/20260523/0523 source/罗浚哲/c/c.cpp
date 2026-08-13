#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int n;
bool is()
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > 3) return 0;
	}
	return 1;
}
signed main()
{
	
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin>>n;
	int sum = 0;
	for(int i = 1;i <= n; i++) cin>>a[i];
	if(is())
	{
		for(int i= 1; i <= n; i++)
		{
			int x = a[i];
			a[i] = (x - 1) % 3 + 1;
			sum += (x - a[i]) / 3;
		}
		for(int i = 1; i <= n - 1; i++)
		{
			
			if(a[i] + a[i + 1] < 3) continue;
			//cout<<"YES\n";
			int x = 3 - a[i];
			sum++;
			a[i + 1] -= x;
		}
	}
	else
	{
		for(int i= 1; i <= n; i++)
		{
			int x = a[i];
			a[i] = x % 3;
			sum += x / 3;
		}
		for(int i = 1; i <= n - 1; i++)
		{
			if(a[i] == 1 && a[i + 1] == 2 || a[i] == 2 && a[i + 1] == 1)
			{
				a[i] = 0;
				a[i + 1] = 0;
				sum++;
			}
			if(a[i] == 2 && a[i + 1] == 2)
			{
				a[i] = 0;
				a[i + 1] = 1;
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
