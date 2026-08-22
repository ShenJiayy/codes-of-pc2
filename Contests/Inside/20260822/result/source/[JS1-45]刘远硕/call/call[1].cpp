#include<bits/stdc++.h>
using namespace std;
#define int long long
const int md=998244353;
int  n,m,q,a[100020],tr[400020],lz[400020];
struct OP{
    int t,p,v;
    vector<int> c;
}op[100020];
void pushdown (int id){
    if (lz[id]==1) return ;
    tr[id*2]=(tr[id*2]*lz[id])%md;
    tr[id*2+1]=(tr[id*2+1]*lz[id])%md;
    lz[id*2]=(lz[id*2]*lz[id])%md;
    lz[id*2+1]=(lz[id*2+1]*lz[id])%md;
    lz[id]=1;
}
void build(int id,int l,int r){
    lz[id]=1;
    if (l==r) {
        tr[id]=a[l]%md;
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}
void update(int id,int l,int r,int x,int y){
    if (l==r){
        tr[id]=(tr[id]+y)%md;
        return ;
    }
    pushdown(id);
    int mid=(l+r)/2;
    if (x<=mid) update(id*2,l,mid,x,y);
    else update(id*2+1,mid+1,r,x,y);
} 
void query(int id,int l,int r){
    if (l==r) {
        cout<<tr[id]<<" ";
        return ;
    }
    pushdown(id);
    int mid=(l+r)/2;
    query(id*2,l,mid);
    query(id*2+1,mid+1,r);
}
void UPD(int sdf){
    // cout<<sdf<<" "<<op[sdf].t<<" "<<op[sdf].p<<" "<<op[sdf].v<<"\n";
    if (op[sdf].t==1) update(1,1,n,op[sdf].p,op[sdf].v);
    else if (op[sdf].t==2) lz[1]=(lz[1]*op[sdf].v)%md;
    else {for (auto r : op[sdf].c) UPD(r);}
}
signed main(){
    freopen("call.in","r",stdin);
    freopen("call.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>m;
    for (int i=1;i<=m;i++) {
        int c;
        cin>>op[i].t;
        if (op[i].t==1) cin>>op[i].p>>op[i].v;
        else if (op[i].t==2) cin>>op[i].v;
        else {
            cin>>c;
            while(c--){
                int p;
                cin>>p;
                op[i].c.push_back(p);
            }
        }
    }
    cin>>q;
    while(q--){
        int sdf;
        cin>>sdf;
        UPD(sdf);
    }
    query(1,1,n);
    return 0;
}