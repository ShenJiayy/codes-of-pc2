#include <bits/stdc++.h>
using namespace std;
int main() 
{
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int j=0,oi=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='J')
		{
			j++;
		}
		else
		{
			if(s[i]=='O'&&s[i+1]=='I')
			{
				oi++;
				i++;
			}
			else
			{
				for(int k=1;k<=oi;k++)
				{
					cout<<"OI";
				}
				for(int k=1;k<=j;k++)
				{
					cout<<"J";
				}
				cout<<s[i];
				j=0;
				oi=0;
			}
		}
	}
	if(oi!=0||j!=0)
	{
		for(int k=1;k<=oi;k++)
		{
			cout<<"OI";
		}
		for(int k=1;k<=j;k++)
		{
			cout<<"J";
		}
		j=0;
		oi=0;
	}
    return 0;
}

