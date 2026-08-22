#include<bits/stdc++.h>
using namespace std;
int t,k,n,b[1000100];
struct nd
{
	int s,id;
}a[1000100];
bool cmp(nd a1,nd a2)
{
	if(a1.s==a2.s) return a1.id<a2.id;
	return a1.s<a2.s;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	if(n<=2) cout<<1<<'\n';
	else
	{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) b[a[i].id]=i; 
		if((a[n].s-a[1].s<a[n-1].s)||((a[n].s-a[1].s==a[n-1].s)&&(a[n].id<a[n-1].id))) cout<<n<<'\n';
		else cout<<1<<'\n';
	}		
	for(int i=2;i<=t;i++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int x,y;
			cin>>x>>y;
			a[b[x]].s=y;
		}
		if(n<=2) cout<<1<<'\n';
		else
		{
			sort(a+1,a+n+1,cmp);
			if((a[n].s-a[1].s<a[n-1].s)||((a[n].s-a[1].s==a[n-1].s)&&(a[n].id<a[n-1].id))) cout<<n<<'\n';
			else cout<<1<<'\n';
		}		
	}
	return 0;
}
