#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans=1000000000,nmx;
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1; i < n; i++)
	{
		if(a[i]!=a[i+1])//1~i i+1~n
		{
			if(abs(n-2*i)<=ans)
			{
				ans=abs(n-2*i);
				nmx=a[i+1];
			}
		}
	}
	cout<<nmx;
 } 
