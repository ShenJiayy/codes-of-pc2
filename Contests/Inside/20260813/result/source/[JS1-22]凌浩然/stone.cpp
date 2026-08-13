#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[500005];
bool xz2=true;
vector<ll> vec;
map<ll,ll> mp;
int main(){
    freopen("stone.in","r",stdin);
    freopen("stone.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]>2) xz2=false;
    }
    if(n<=2000){
        for(ll i=1;i<=n;++i){
            ll j=i-1;
            for(;j>=1;--j){
                if(a[j]==a[i]) break;
            }
            for(;j<=i&&j!=0;++j){
                a[j]=a[i];
            }
        }
        for(ll i=1;i<=n;++i){
            cout<<a[i]<<"\n";
        }
        return 0;
    }
    if(xz2){
        //找到a[1]最后出现的位置
        ll i=n;
        for(;i>=1;--i){
            if(a[i]==a[1]) break;
        }
        for(ll j=1;j<=i;++j){
            cout<<a[1]<<"\n";
        }
        for(ll j=i+1;j<=n;++j){
            cout<<(a[1]==1?2:1)<<"\n";
        }
        return 0;
    }

    for(ll i=1;i<=n;++i){
        mp[a[i]]=i;
    }
    vec.push_back(1);
    while(1){
        if(mp[a[vec.back()]]==n){
            vec.push_back(n+1);
            break;
        }
        vec.push_back(mp[a[vec.back()]]+1);
    }
    for(ll i=0;i<(ll)vec.size();++i){
        for(ll j=0;j<vec[i+1]-vec[i];++j){
            cout<<a[vec[i]]<<"\n";
        }
    }
    return 0;
}
