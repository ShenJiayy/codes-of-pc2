#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct s{
    ll h,id,ans;
}a[500005];
ll n,b[500005];
bool cmp1(s a,s b){
    return a.h<b.h;
}
bool cmp2(s a,s b){
    return a.id<b.id;
}
int main(){
    freopen("tie.in","r",stdin);
    freopen("tie.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n+1;++i){
        cin>>a[i].h;
        a[i].id=i;
    }
    for(ll i=1;i<=n;++i){
        cin>>b[i];
    }
    sort(a+1,a+n+2,cmp1);
    sort(b+1,b+n+1);
    for(ll i=1;i<=n;++i){
        a[n+1].ans=max(max(a[i].h-b[i],0LL),a[n+1].ans);
    }
    for(ll i=n;i>=1;--i){
        a[i].ans=max(a[i+1].ans,max(a[i+1].h-b[i],0LL));
    }
    sort(a+1,a+n+2,cmp2);
    for(ll i=1;i<=n+1;++i){
        cout<<a[i].ans<<" ";
    }
    return 0;
}
