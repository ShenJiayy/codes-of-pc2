#include<bits/stdc++.h>
using namespace std;
const int MAX=300001;
int head[MAX],nxt[MAX],to[MAX],cnt,q[3000001],vis[MAX],vi[MAX];
int add(int u,int v){
	to[++cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		int h=0,e=0;
		q[++e]=i;
		vi[i]=1;
		vis[i]=1;
		while(h<e){
			int u=q[++h];
			for(int j=head[u];j!=0;j=nxt[j]){
				if(vis[to[j]]==0){
					if(j<to[j]&&j%2==1){
						vis[to[j]]=1;
						q[++e]=to[j];
						vi[to[j]]=1;
						//cout<<j<<"->"<<to[j]<<endl;
					}
					if(j>to[j]&&j%2==0){
						vis[to[j]]=1;
						q[++e]=to[j];
						vi[to[j]]=1;
						//cout<<j<<"->"<<to[j]<<endl;
					}
				}
			}
			//cout<<h<<" "<<e<<endl;
		}
		memset(q,0,sizeof(0));
		memset(vis,0,sizeof(0));
		int ans=0;
	    for(int i=1;i<=n;i++){
		    if(vi[i]==0) ans++;
	    }
	    cout<<ans<<endl;
	    memset(vi,0,sizeof(0));
	}
} 
