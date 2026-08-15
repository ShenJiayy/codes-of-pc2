#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,ans=1LL<<30,presum1[500005],presum2[500005],presum3[500005];
string s;
vector<ll> o;

int main(){
    freopen("jjooii.in","r",stdin);
    freopen("jjooii.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k>>s;
    for(ll i=0;i<n;++i){
        presum1[i+1]=presum1[i];
        presum2[i+1]=presum2[i];
        presum3[i+1]=presum3[i];
        if(s[i]=='J') ++presum1[i+1];
        if(s[i]=='O') ++presum2[i+1];
        if(s[i]=='I') ++presum3[i+1];
        if(s[i]=='O'){
            o.emplace_back(i);
        }
    }
    
    if((ll)o.size()<k){
        cout<<-1;
        return 0;
    }
    
    for(ll i=0,j=k-1;i<(ll)o.size()&&j<(ll)o.size();++i,++j){
        ll lbo=lower_bound(presum1,presum1+n+1,presum1[o[i]]-k+1)-presum1;
        ll rbo=lower_bound(presum3,presum3+n+1,presum3[o[j]+1]+k)-presum3;
        if(lbo!=0&&rbo!=n+1){
            ans=min(ans,rbo-lbo+1-k*3);
        }
    }
    if(ans==1LL<<30) ans=-1;
    cout<<ans;
    return 0;
}
