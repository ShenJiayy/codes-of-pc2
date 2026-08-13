#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[300005];
struct node{
	int id;
	bool b;
};
queue<node>q;
bool vis[300005];
void add(int a,int b)
{
	v[a].push_back(b);
	v[b].push_back(a);
}
void fix()
{
	while(q.size()) q.pop();
	for(int i=1;i<=n;i++) vis[i]=0;
}
int bfs(int i)
{
	fix();
	q.push({i,1});
	vis[i]=1;
	while(!q.empty())
	{
		node qout=q.front();
		q.pop();
		if(qout.b)
		{
			for(int qin:v[qout.id])
			if(!vis[qin]&&qin>qout.id)
			{
				vis[qin]=1;
				q.push({qin,0});
			}
		}
		else
		{
			for(int qin:v[qout.id])
			if(!vis[qin]&&qin<qout.id)
			{
				vis[qin]=1;
				q.push({qin,1});
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]) ans++;
	return ans;
}
int main()
{
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	cin>>n>>m;
	for(int i=1,a,b;i<=m;i++)
	{
		cin>>a>>b;
		add(a,b);
	}
	for(int i=1;i<=n;i++)
		cout<<bfs(i)<<endl;
}
