#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n,m,q,f;
long long a[100005];
struct Node
{
	int t,p,v,c,cg[105];
}g[100005];

void t1(int p,int v)
{
	a[p] = (a[p]+v)%mod;
}
void t2(int v)
{
	for(int i = 1;i <= n;i++)
		a[i] = a[i]*v%mod;
}
void t3(int c,int id)
{
	for(int i = 1;i <= c;i++)
	{
		if(g[g[id].cg[i]].t == 1) t1(g[g[id].cg[i]].p,g[g[id].cg[i]].v);
		else if(g[g[id].cg[i]].t == 2) t2(g[g[id].cg[i]].v);
		else t3(g[g[id].cg[i]].c,g[id].cg[i]);
	}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	cin >> m;
	for(int i = 1;i <= m;i++)
	{
		cin >> g[i].t;
		if(g[i].t == 1) cin >> g[i].p >> g[i].v;
		else if(g[i].t == 2) cin >> g[i].v;
		else 
		{
			cin >> g[i].c;
			for(int j = 1;j <= g[i].c;j++) cin >> g[i].cg[j];
		}
	}
	cin >> q;
	while(q--)
	{
		cin >> f;
		if(g[f].t == 1) t1(g[f].p,g[f].v);
		else if(g[f].t == 2) t2(g[f].v);
		else t3(g[f].c,f);
	}
	for(int i = 1;i <= n;i++) cout << a[i] << " ";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
