#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int  n,m,c,k,a[100020],qp,pq,tmp,tmmp;
signed main(){
    freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
    cin>>n>>m>>c>>k;
    for (int i=1;i<=n;i++) {
        cin>>tmp;
        pq|=tmp;
    }
    for (int i=1;i<=m;i++){
        cin>>tmp>>tmmp;
        qp|=(1<<tmp);
    }
    cout<<(1<<(k-__builtin_popcount((pq&qp)^qp)))-n;
    return 0;
}