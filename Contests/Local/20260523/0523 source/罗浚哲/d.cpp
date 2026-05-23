#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	int n, q;
	cin>>n>>q;
	int s = 0;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
		s += a[i];
	}
	while(q--)
	{
		int c, d;
		cin>>c>>d;
		cout<<s;
	}
	return 0;
 } 
