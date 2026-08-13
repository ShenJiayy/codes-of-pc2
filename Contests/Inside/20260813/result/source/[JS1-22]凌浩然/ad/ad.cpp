#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n;
bool xz1=true;
struct kkksc03{
    ll p,e;
}axt[500005];
int main(){
    freopen("ad.in","r",stdin);
    freopen("ad.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>axt[i].p>>axt[i].e;
        if(axt[i].e!=axt[1].e){
            xz1=false;
        }
    }
    if(xz1){
        set<ll> st;
        for(ll i=1;i<=n;++i){
            st.insert(axt[i].p);
        }
        cout<<st.size();
        return 0;
    }
    return 0;
}
