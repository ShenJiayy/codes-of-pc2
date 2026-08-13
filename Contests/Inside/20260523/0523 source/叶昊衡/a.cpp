#include<bits/stdc++.h>
using namespace std;
int n,num=0,jnum=0;
string s;
vector<char>v;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>s;
	for(int i=n-1;i>=0;i--)
	{
		char c=s[i];
		if(c=='O')
		{
			if(i==0)
			{
				while(jnum--)
					v.push_back('J');
				while(num--)
				{
					v.push_back('I');
					v.push_back('O');
				}
				num=jnum=0;
				if(s[i+1]!='I') v.push_back('O');
			}
			else
			{
				if(s[i-1]=='J') jnum++;
				else if(s[i-1]=='O')
				{
					while(num--)
					{
						v.push_back('I');
						v.push_back('O');
					}
					num=0;
				}
				if(i==n-1||s[i+1]!='I') v.push_back('O');
			}
		}
		if(c=='I')
		{
			if(i==0)
			{
				while(jnum--)
					v.push_back('J');
				while(num--)
				{
					v.push_back('I');
					v.push_back('O');
				}
				num=jnum=0;
			}
			else
			{
				if(s[i-1]=='J') jnum++;
				else if(s[i-1]=='O') num++;
				else if(s[i-1]=='I')
				{
					while(num--)
					{
						v.push_back('I');
						v.push_back('O');
					}
					num=0;
					v.push_back('I');
				}
			}
		}
		if(c=='J')
		{
			if(i==0)
			{
				while(jnum--)
					v.push_back('J');
				while(num--)
				{
					v.push_back('I');
					v.push_back('O');
				}
				num=jnum=0;
			}
			else if(s[i-1]=='J') jnum++;
			else
			{
				while(jnum--)
					v.push_back('J');
				jnum=0;
			}
		}
	}
	for(int i=n-1;i>=0;i--) cout<<v[i];
	return 0;
}
