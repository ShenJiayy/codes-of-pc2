#include<bits/stdc++.h>
#define PII pair<int,int>
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const int N=2000;
int n,m,siz[N+10];
ll f[N+10][N+10];
vector<PII>g[N+10];
void dfs(int x,int fa)
{
    siz[x]=1;
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i].first;
        if(y==fa) continue;
        dfs(y,x);
        siz[x]+=siz[y];
        int w=g[x][i].second;
        for(int j=max(siz[x],m);j>=0;j--)
            for(int k=max(j-siz[x]+siz[y],0);k<=min(j,siz[y]);k++)
                f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]+1ll*w*k*(m-k)+1ll*w*(siz[y]-k)*(n-m-siz[y]+k));
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    m=min(m,n-m);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        g[u].pb(mkp(v,w));
        g[v].pb(mkp(u,w));
    }
    dfs(1,0);
    printf("%lld\n",f[1][m]);
    return 0;
}
