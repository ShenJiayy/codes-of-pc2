#include<bits/stdc++.h>
using namespace std;
struct s{
    int x,y;
}seg[500005];
int n,m,ans=2147483647;
int main(){
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>seg[i].x>>seg[i].y;
    }
    if(n<=20){
        for(int i=0;i<(1<<n);++i){
            int mcnt=0;
            for(int j=0;j<n;++j){
                mcnt+=(i&(1<<j))>0;
            }
            if(mcnt!=m) continue;
            else{
                int l=0,r=2147483647,maxmm=0,minmm=2147483647;
                bool flag=true;
                for(int j=0;j<n;++j){
                    if((i&(1<<j))==0) continue;
                    maxmm=max(seg[j+1].y-seg[j+1].x,maxmm);
                    minmm=min(seg[j+1].y-seg[j+1].x,minmm);
                    if(max(l,seg[j+1].x)>min(r,seg[j+1].y)){
                        flag=false;
                        break;
                    }
                    else{
                        l=max(l,seg[j+1].x);
                        r=min(r,seg[j+1].y);
                    }
                }
                if(flag) ans=min(ans,maxmm-minmm);
            }
        }
        if(ans==2147483647) ans=-1;
        cout<<ans;
        return 0;
    }
    return 0;
}
