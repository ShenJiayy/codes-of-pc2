#include<bits/stdc++.h>
using namespace std;
struct tie
{
	int id,h;
	bool operator < (tie a)const{return h<a.h;}
}a[200010];
int main()
{
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n+1;i++)
	{
		cin>>a[i].h;a[i].id=i;
	}
	int b[200010];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	sort(a+1,a+n+2);
	int ans[200010];int now=0;
	for(int i=1;i<=n+1;i++)
	{
		now=0;
		for(int j=1;j<=n;j++)
		{
			if(j>=i)now=max(max(0,a[j+1].h-b[j]),now);
			if(j<i)now=max(max(0,a[j].h-b[j]),now);
			//cout<<i<<" "<<j<<" "<<now<<endl;
		}
		ans[a[i].id]=now;
	}
	for(int i=1;i<=n+1;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
//3 4 6 7
//2 4 6


