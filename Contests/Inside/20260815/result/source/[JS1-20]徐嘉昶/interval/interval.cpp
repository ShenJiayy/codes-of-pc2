#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
struct line
{
	int x,y,len;
}xxkan[500005];
int lsh[1000005],ans=2147483647;
bool cmp(line qq,line ww)
{
	return qq.len>ww.len;
}
signed main()
{
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>xxkan[i].x>>xxkan[i].y;
		lsh[(i<<1)-1]=xxkan[i].x;
		lsh[i<<1]=xxkan[i].y;
		xxkan[i].len=xxkan[i].y-xxkan[i].x+1;
	}
	sort(lsh+1,lsh+2*n+1);
	int len=unique(lsh+1,lsh+2*n+1)-lsh-1;
	for(int i=1;i<=len;i++)
	{
		xxkan[i].x=lower_bound(lsh+1,lsh+len+1,xxkan[i].x)-lsh;
		xxkan[i].y=lower_bound(lsh+1,lsh+len+1,xxkan[i].y)-lsh;
	}
	sort(xxkan+1,xxkan+n+1,cmp);
	for(int k=1;k<=2*n;k++)
	{
		queue<int> q;
		for(int i=1;i<=n;i++)
		{
			if(k<=xxkan[i].y&&k>=xxkan[i].x)
			{
				q.push(xxkan[i].len);
			}
			if(q.size()==m)
			{
				ans=min(ans,q.front()-xxkan[i].len);
				q.pop();
			}
		}
	}
	if(ans==2147483647) cout<<"-1";
	cout<<ans;
	return 0;
}
