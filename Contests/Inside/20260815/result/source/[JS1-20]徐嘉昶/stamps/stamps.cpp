#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,l,x[205],t[205],ans;
bitset<205> vis;
signed main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++) cin>>t[i];
	n+=1;
	for(int i=0;i<(1<<n-1);i++)
	{
		vis=0;
		vis[0]=1;
		int cnt=0,wei=0,pre=0,ansxx=0;
		for(int k=1;k<=n-1;k++)
		{
			int f=((i>>(k-1))&1);
			if(f)
			{
				while(vis[wei]==1)
				{
					wei=(wei+1)%n;
				}
				cnt+=((x[wei]-pre)+l)%l;
				pre=x[wei];
				vis[wei]=1;
				if(cnt<=t[wei]) ansxx++;
			}
			else 
			{
				while(vis[wei]==1)
				{
					wei=(wei-1+n)%n;
				}
				cnt+=((pre-x[wei])+l)%l;
				pre=x[wei];
				vis[wei]=1;
				if(cnt<=t[wei]) ansxx++;
			}
		}
		ans=max(ans,ansxx);
	}
	cout<<ans;
	return 0;
}
