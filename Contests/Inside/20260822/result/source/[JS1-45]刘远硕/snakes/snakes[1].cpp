#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,T,a[1000020],ans=0,mx,mi,mxid,miid,vis[1000020];
void mxmi(){
    mx=-1,mi=1000000002;
    for (int i=1;i<=n;i++) {
        if (a[i]==-1) continue;
        if (a[i]>=mx) mx=a[i],mxid=i;
        if (a[i]<mi) mi=a[i],miid=i;
    }
}
int dfs(int now,int eat){
    if (now==eat){
        ans=1;
        return -1;
    }
    if (vis[eat]!=0) return eat;
    vis[now]=1;
    int tmp=mi;
    a[now]-=tmp;
    a[eat]=-1;
    mxmi();
    int res=dfs(mxid,miid);
    vis[now]=0;
    a[now]+=tmp;
    a[eat]=tmp;
    if (res==-1) return -1;
    else if (now==res) {
        ans=0;
        for (int i=1;i<=n;i++) if (a[i]!=-1) ans++;
        return 0;
    }
    return res;
}
void solve(){
    ans=0;
    memset(vis,0,sizeof vis);
    mxmi();
    dfs(mxid,miid);
    cout<<ans<<"\n";
}
signed main(){
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    cin>>T;
    T--;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    solve();
    while(T--){
        cin>>k;
        while(k--){
            int p,q;
            cin>>p>>q;
            a[p]=q;
        }
        solve();
    }
    return 0;
}