#include<bits/stdc++.h>
using namespace std;
const int maxN=3e5;
vector<int> ed[maxN+10];
int vis[maxN+10][3],tot;
int n,m;
struct node
{
    int id;
    int pos;
};

queue<node> q;
void bfs(int start){
	node x;
    x.id=start,x.pos=1;
    q.push(x);
    while(!q.empty()){
        int now=q.front().id,pos=q.front().pos;
        //cout<<now<<" ";
        q.pop();
        if(pos>n) continue;
        vis[now][pos%2]=1;
        if(!vis[now][2]){
            tot--;
            vis[now][2]=1;
        }
        for(int i=0;i<ed[now].size();i++){
            int nxt=ed[now][i];
            if(!vis[nxt][(pos+1)%2]){
                if((pos%2==1&&now<nxt)||(pos%2==0&&now>nxt)){
                    node nx;
                    nx.id=nxt,nx.pos=pos+1;
                    q.push(nx);
                }
            }
        }
    }
}
int main(){
    freopen("e.in","r",stdin);
    freopen("e.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		tot=n;
		memset(vis,0,sizeof(vis));
		bfs(i);
		cout<<tot<<"\n";
	}
    return 0;
}

