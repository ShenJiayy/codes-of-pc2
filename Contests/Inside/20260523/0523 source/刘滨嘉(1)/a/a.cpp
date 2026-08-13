#include <bits/stdc++.h>
using namespace std;
int n,k1,k2;
string s;
bool check1()
{
	if(n%3!=0) return 0;
	for(int i=2; i<n; i+=3)
	{
		if(s[i-2]!='J'||s[i-1]!='O'||s[i]!='I')
		{
			return 0;
		}
	}
	return 1;
}
bool check2()
{
	for(int i=0; i<n; i++)
	{
		if(s[i]!='J')
		{
			k1=i-1;
			break;
		}
	}
	for(int i=k1+1; i<n-1; i++)
	{
		if(s[i]=='J') return 0;
	}
	for(int i=k1+1; i<n-1; i+=2)
	{
		if(s[i]!='O'||s[i+1]!='I')
		{
			k2=i+1;
			break;
		}
	}
	if(k2==0) k2=n-2;
	return 1;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin >> n >> s;
	if(check1())
	{
		for(int i=1; i<=n/3; i++)
		{
			cout << "OI";
		}
		for(int i=1; i<=n/3; i++)
		{
			cout << "J";
		}
	}
	else if(check2())
	{
		for(int i=k1+1; i<=k2; i++)
		{
			cout << s[i];
		}
		for(int i=0; i<=k1; i++)
		{
			cout << s[i];
		}
		for(int i=k2+1; i<n; i++)
		{
			cout << s[i];
		}
	}
	else
	{
		int f=1;
		while(f)
		{
			for(int i=2; i<n; i++)
			{
				if(s[i-2]=='J'&&s[i-1]=='O'&&s[i]=='I')
				{
					s[i-2]='O',s[i-1]='I',s[i]='J';
					f=2;
				}
			}
			if(f!=2) f=0;
			else f=1;
		}
		cout << s;
	}
	return 0;
 } 
