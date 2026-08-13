#include<bits/stdc++.h>
using namespace std;
int n,f[500050],b=1,ans;
struct str{
	int x,e;
}s[500050];
bool cmp(str a,str b)
{
	return a.x<b.x;
}
bool cmp2(str a,str b)
{
	return a.e>b.e;
}
int main()
{
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i].x>>s[i].e;
		if(i>1&&s[i].e!=s[i-1].e) b=0;
	}
	if(b==1)
	{
		sort(s+1,s+n+1,cmp);		
		for(int i=1;i<=n;i++) if(s[i].x!=s[i-1].x) ans++;
		cout<<ans;
	}
	else
	{
		sort(s+1,s+n+1,cmp2);	
		for(int i=1;i<=n;i++)
		{
			if(f[i]==1) continue;
			for(int j=1;j<=n;j++)
			{
				if(i==j||f[j]==1) continue;
				if(abs(s[i].x-s[j].x)<=s[i].e-s[j].e)
				{
					f[j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++) if(f[i]==0) ans++;
		cout<<ans;
	}
	return 0;
}
