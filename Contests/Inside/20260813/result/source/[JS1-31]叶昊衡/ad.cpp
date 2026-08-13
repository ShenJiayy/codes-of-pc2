#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,tot;
bool flag=1;
int spec=-1;
struct node{
	int x,e,num,id;
	bool ok=0;
	bool operator < (const node &n) const
	{
		return e>n.e;
	}
	void out()
	{
		cout<<x<<' '<<e<<' '<<num<<' '<<id<<endl;
	}
}peo[500005];
int dis(int i,int j)
{
	int xx=peo[i].x-peo[j].x;
	if(xx>=0) return xx;
	else return -xx;
}
map<int,node>now;
map<int,bool>hpeo;
signed main()
{
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		node in;
		cin>>in.x>>in.e;
		if(i==1) spec=in.e;
		else if(in.e!=spec) flag=0;
		if(hpeo[in.x])
		{
			node oth=now[in.x];
			oth.e=max(oth.e,in.e);
			oth.num++;
			peo[oth.id]=oth;
		}
		else
		{
			hpeo[in.x]=1;
			in.num=1,in.id=++tot;
			peo[tot]=in;
			now[in.x]=in;
		}
	}
	if(flag)
	{
		cout<<tot;
		return 0;
	}
	sort(peo+1,peo+tot+1);
	for(int i=1;i<=tot;i++)
		if(!peo[i].ok)
		{
			ans++;
			peo[i].ok=1;
			for(int j=i-1;j>=1;j--)
				if(!peo[j].ok&&dis(i,j)<=peo[i].e-peo[j].e)
					peo[j].ok=1;
			for(int j=i+1;j<=tot;j++)
				if(!peo[j].ok&&dis(i,j)<=peo[i].e-peo[j].e)
					peo[j].ok=1;
		}
	cout<<ans<<endl;
}
