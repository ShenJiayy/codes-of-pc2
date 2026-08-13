#include <bits/stdc++.h>
#define int long long 
using namespace std;
int x;
bool is(string s)
{
	for(int i = 2; i < s.size(); i++)
	{
		string s2 = s.substr(i - 2, 3);
		if(s2 == "JOI")
		{
			return 0;
		}
	}
	return 1;
}
bool is2(string s)
{
	for(int i = 2; i < s.size(); i++)
	{
		string s2 = s.substr(i - 2, 3);
		if(s2 != "JOI")
		{
			return 0;
		}
	}
	return 1;
}
bool is3(string s)
{
	if(s[0] != 'J' || s[1] != 'J') return 0;
	for(int i = 2; i < s.size(); i++)
	{
		if(s[i] != 'J')
		{
			x = i;
			break;
		}
	}
	for(int i = x; i < s.size(); i++)
	{
		if(s[i] == 'J') return 0;
	}
	return 1;
}
string f(string s)
{
	for(int i = 2; i < s.size(); i++)
	{
		string s2 = s.substr(i - 2, 3);
		if(s2 == "JOI")
		{
			s[i - 2] = 'O';
			s[i - 1] = 'I';
			s[i] = 'J';
		}
	}
	return s;
}
signed main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n % 3 == 0 && is2(s))
	{
		for(int i = 1; i <= n / 3; i++)
		{
			cout<<"OI";
		}
		for(int i = 1; i <= n / 3; i++)
		{
			cout<<"J";
		}
	}
	else if(is3(s))
	{
		int cnt = 0; 
		for(int i = x; i < s.size(); i+=2)
		{
			if(s[i] == 'O' && s[i + 1] == 'I')
			{
			 	cnt++;
			 } 
			else break;
		}
		for(int i = 1; i <= cnt; i++) cout<<"OI";
		for(int i = 1; i <= x; i++) cout<<"J";
		cout<<s.substr(x + 2 * cnt);
	}
	else 
	{
		while(is(s) == 0)
		{
			s = f(s);
		}
		cout<<s;
	}
	return 0;
 } 
