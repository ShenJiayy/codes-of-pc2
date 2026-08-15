#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=2e5+10;
struct Mitsuha{
    int v,id;
}c[inf];
inline bool cmp1(Mitsuha x,Mitsuha y){
    return x.v>y.v;
}
inline bool cmp2(int x,int y){
    return x>y;
}
int n,b[inf],a[inf],mxn1[inf],mxn2[inf],mp[inf],d[inf];
signed main(){
    freopen("tie.in","r",stdin);
    freopen("tie.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    {
        for(int i=1;i<=n+1;i++) cin>>c[i].v,c[i].id=i;
        sort(c+1,c+n+2,cmp1);
        for(int i=1;i<=n+1;i++) a[i]=c[i].v,mp[c[i].id]=i;
        for(int i=1;i<=n;i++) cin>>d[i];
        sort(d+1,d+n+1,cmp2);
        for(int i=1;i<=n;i++) b[i]=d[i];
        for(int i=1;i<=n;i++) mxn1[i]=max(mxn1[i-1],a[i]-b[i]);
        for(int i=n;i>=1;i--) mxn2[i]=max(mxn2[i+1],a[i+1]-b[i]);
        // for(int i=1;i<=n+1;i++) cout<<a[i]<<' ';
        // cout<<'\n';
        // for(int i=1;i<=n+1;i++) cout<<mp[i]<<' ';
        // cout<<'\n';
        // for(int i=1;i<=n;i++) cout<<b[i]<<' ';
        // cout<<'\n';
        // for(int i=1;i<=n;i++) cout<<mxn1[i]<<' ';
        // cout<<'\n';
        // for(int i=1;i<=n;i++) cout<<mxn2[i]<<' ';
        // cout<<'\n';
    }
    for(int i=1;i<=n+1;i++) cout<<max(mxn1[mp[i]-1],mxn2[mp[i]])<<' ';
    return 0;
}
