#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
const int N=200001;
int t,n,u,v,w,head[N],numE=0,d[N],du[N],dp[N],ans,s;
struct Edge{
    int next,to,dis;
}e[2*N];
void addEdge(int from,int to,int dis){
    e[++numE].next=head[from];
    e[numE].to=to;
    e[numE].dis=dis;
    head[from]=numE;
}
int dfs_(int x,int l){
    int p=0;d[x]=0;
    for(int j=head[x];j;j=e[j].next){
        int v=e[j].to;
        if(v==l)continue;
        p+=min(e[j].dis,dfs_(v,x));
    }
    if(du[x]!=1)return d[x]=p; 
    else return e[head[x]].dis;
}
void dfs(int x,int l){
    for(int j=head[x];j;j=e[j].next){
        int v=e[j].to;
        if(v==l)continue;
        if(du[x]==1)dp[v]=e[j].dis+d[v];
        else dp[v]=d[v]+min(e[j].dis,dp[x]-min(e[j].dis,d[v]));
        ans=max(ans,dp[v]);
        dfs(v,x);
    }
}
int main() {
    scanf("%d",&t);
    while(t--){
        memset(head,0,sizeof(head));
        memset(d,0,sizeof(d));
        memset(dp,0,sizeof(dp));
        memset(du,0,sizeof(du));
        numE=0;ans=0;
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);addEdge(v,u,w);
            du[u]++;du[v]++;
        }
        dp[1]=dfs_(1,-1);
        dfs(1,-1);
        printf("%d\n",max(dp[1],ans));
    }
    return 0;
}