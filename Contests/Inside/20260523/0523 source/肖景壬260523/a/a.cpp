#include<bits/stdc++.h>
using namespace std;
string s;
char ch[500005];
int n,sz,cntj,cntx;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	s=' '+s;
	sz=0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i-1]=='O'&&s[i]=='I') ch[sz]='X';
		else
		{
			sz++;
			ch[sz]=s[i];
		}
	}
	for(int i = 1; i <= sz; i++)
	{
		if(ch[i]=='J') cntj++;
		else if(ch[i]=='X') cntx++;
		else
		{
			for(int i = 1; i <= cntx; i++) cout<<"OI";
			for(int i = 1; i <= cntj; i++) cout<<"J";
			cntx=cntj=0;
			cout<<ch[i];
		}
	}
	for(int i = 1; i <= cntx; i++) cout<<"OI";
	for(int i = 1; i <= cntj; i++) cout<<"J";
}
