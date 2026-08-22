#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,k;
int xxkan[1000006];
int cnt[65];
bool f[65];
struct ys
{
	int wei,siliao;
}yueshu[1000006];
map<int,bool> sl;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>xxkan[i];
		for(int j=0;j<k;j++)
		{
			if(((xxkan[i]>>j)&1)==1)
			{
				cnt[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>yueshu[i].wei>>yueshu[i].siliao;
		if(!cnt[yueshu[i].wei]||sl[yueshu[i].siliao])
		{
			f[yueshu[i].wei]=1;
		}
		else
		{
			sl[yueshu[i].siliao]=1;
		}
	}
	int ans=1;
	for(int i=0;i<=k-1;i++)
	{
		if(!f[i]) ans*=2;
	}
	cout<<ans-n;
	return 0;
}
