#include<bits/stdc++.h>
using namespace std;
int h,w,q,xx[505][505];
bool vis[505][505];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>h>>w>>q;
    while(q--){
        int Q;
        cin>>Q;
        if(Q==1){
            int x,y,c;
            cin>>x>>y>>c;
            if(!vis[x][y]) xx[x][y]=c;
            if(!vis[x+1][y]) xx[x+1][y]=c;
            if(!vis[x][y+1]) xx[x][y+1]=c;
            if(!vis[x+1][y+1]) xx[x+1][y+1]=c;
        }
        if(Q==2){
            int x,y;
            cin>>x>>y;
            vis[x][y]=vis[x+1][y]=vis[x][y+1]=vis[x+1][y+1]=true;
        }
    }
    for(int i=1;i<=h;++i){
        for(int j=1;j<=w;++j){
            cout<<xx[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
