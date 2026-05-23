#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<n/2;
	}
	else
	{
		cout<<1;
	}
}
