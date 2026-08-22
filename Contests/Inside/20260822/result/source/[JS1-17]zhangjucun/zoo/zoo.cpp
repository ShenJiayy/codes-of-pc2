#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int m,c,k;
ull n,a,s,p,q,x,ans=1;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) 
	{
		cin>>a;
		s|=a;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>p>>q;
		if(((1<<p)&s)==0) x|=(1<<p);
	}
	if((k==64&&x+1==0)||x==(1<<k)-1) 
	{
		cout<<1;
		return 0;
	}//判断是否全部没有 防止溢出 
	for(int i=0;i<k;i++)
	{
		if((x&(1<<i))==0) ans*=2;
	}
	cout<<ans-n;
	return 0;
}
