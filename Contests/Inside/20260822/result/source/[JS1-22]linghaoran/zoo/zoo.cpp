#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,m,c,k,a[1000005],cnt;
bool r[75],s[75];
int main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>c>>k;
    for(ull i=1;i<=n;++i){
        cin>>a[i];
    }
    for(ull i=1;i<=m;++i){
        ull a,b;
        cin>>a>>b;
        r[a]=true;
    }

    for(ull i=1;i<=n;++i){
        for(ull j=0;j<k;++j){
            if(a[i]&(1ULL<<j)){
                s[j]=true;
            }
        }
    }
    for(ull i=0;i<k;++i){
        if(r[i]&&!s[i]) ++cnt;
    }
    

    if(k==64&&cnt==0){
        if(n==0) cout<<"18446744073709551616";
        else cout<<(18446744073709551615ULL-(n-1));
    }
    else cout<<ull((1ULL<<(k-cnt))-n);

    return 0;
}
