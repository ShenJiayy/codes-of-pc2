#include<bits/stdc++.h>
using namespace std;
const int inf=510;
int h,w,q,op,x,y,c,color[inf][inf];
bool mask[inf][inf];
int main(){
    freopen("mask.in","r",stdin);
    freopen("mask.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>h>>w>>q;
    while(q--){
        cin>>op>>x>>y;
        if(op-1) mask[x][y]=mask[x+1][y]=mask[x][y+1]=mask[x+1][y+1]=1;
        else cin>>c,color[x][y]=mask[x][y]?color[x][y]:c,color[x+1][y]=mask[x+1][y]?color[x+1][y]:c,color[x][y+1]=mask[x][y+1]?color[x][y+1]:c,color[x+1][y+1]=mask[x+1][y+1]?color[x+1][y+1]:c;
    }
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++) cout<<color[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
