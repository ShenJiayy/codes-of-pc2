#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,l=0,r=0,h=0;
string s,t; 

signed main()
{
	freopen ("a.in","r",stdin);
	freopen ("a.out","w",stdout);
	cin>>n; 
	cin>>s;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='J') h++;
		else if (i<n-1&&s[i]=='O'&&s[i+1]=='I')
		{
			t+='O';
			t+='I';
			i++;
		}
		else
		{
			while (h) t+='J',h--;
			t+=s[i];
		}
	}
	while (h) t+='J',h--;
	cout<<t;
	return 0;
}
