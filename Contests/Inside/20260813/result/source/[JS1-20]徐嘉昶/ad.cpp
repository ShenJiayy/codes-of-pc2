#include<bits/stdc++.h>
using namespace std;
struct jumin
{
	int x,e;
}xxkan[500005];
bool vis[500005];
int n,ans;
bool cmp(jumin qq,jumin ww)
{
	if(qq.e==ww.e) return qq.x<ww.x;
	return qq.e>ww.e;
}
bool cmp2(jumin qq,jumin ww)
{
	return qq.x<ww.x;
}
void bfs(int st)
{
	queue<int> q;
	q.push(st);
	vis[st]=1;
	while(!q.empty())
	{
		int dian=q.front();
		q.pop();
		for(int i=dian+1;i<=n;i++)
		{
			if(!vis[i]&&abs(xxkan[dian].x-xxkan[i].x)<=xxkan[dian].e-xxkan[i].e)
			{
				vis[i]=1;
				q.push(i);
			}
		}
	}
}
int main()
{
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>xxkan[i].x>>xxkan[i].e;
	}
	if(n<=1000)
	{
		sort(xxkan+1,xxkan+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				ans++;
				bfs(i);
			}
		}
		cout<<ans;
	}
	else
	{
		sort(xxkan+1,xxkan+n+1,cmp2);
		for(int i=1;i<=n;i++)
		{
			if(xxkan[i].x!=xxkan[i-1].x)
			{
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
