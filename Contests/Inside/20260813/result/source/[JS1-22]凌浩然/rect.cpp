#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,cnt;
ll presum(vector<vector<ll>>& pre,ll a,ll b,ll c,ll d){
    if(b==0||d==0) return 0;
    return pre[b][d]-pre[a-1][d]-pre[b][c-1]+pre[a-1][c-1];
}
int main(){
    freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    vector<vector<ll>> vec1(n+5,vector<ll>(m+5));
    vector<vector<ll>> vec1_presum(n+5,vector<ll>(m+5));
    vector<vector<ll>> vec2(m+5,vector<ll>(n+5));
    vector<vector<ll>> vec2_presum(m+5,vector<ll>(n+5));
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<=m;++j){
            cin>>vec1[i][j];
            vec1_presum[i][j]=vec1_presum[i-1][j]+vec1_presum[i][j-1]-vec1_presum[i-1][j-1]
            +vec1[i][j];
        }
    }
    if(n<=30&&m<=30){
        for(ll i=1;i<=n;++i){
            for(ll j=i;j<=n;++j){
                for(ll k=1;k<=m;++k){
                    for(ll l=k;l<=m;++l){
                        if(presum(vec1_presum,i,j,k,l)==(l-k+1)*(j-i+1)){
                            ++cnt;
                        }
                    }
                }
            }
        }
        cout<<cnt;
        return 0;
    }
    if(n>m){
        for(ll i=1;i<=n;++i){
            for(ll j=1;j<=m;++j){
                vec2[j][i]=vec1[i][j];
            }
        }
		for(ll i=1;i<=m;++i){
            for(ll j=1;j<=n;++j){
                vec2_presum[i][j]=vec2_presum[i-1][j]+vec2_presum[i][j-1]-vec2_presum[i-1][j-1]
            +vec2[i][j];
            }
        } 
    }

    if(n<=m){
        //固定行区间
        
        for(ll i=1;i<=n;++i){
            for(ll j=i;j<=n;++j){
                unordered_map<ll,ll> ump; //预处理前缀和中每个数出现的次数
                for(int k=0;k<=m;++k){
                    ++ump[presum(vec1_presum,i,j,1,k)];
                    if(k>0){
                        cnt+=ump[(j-i+1)*k-presum(vec1_presum,i,j,k,k)];
                    }
                }
            }
        }
    }
    else{
        swap(n,m);
        for(ll i=1;i<=n;++i){
            for(ll j=i+1;j<=n;++j){
                unordered_map<ll,ll> ump; //预处理前缀和中每个数出现的次数
                for(int k=0;k<=m;++k){
                    ++ump[presum(vec2_presum,i,j,1,k)];
                    if(k>0){
                        cnt+=ump[(j-i+1)*k-presum(vec2_presum,i,j,k,k)];
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
