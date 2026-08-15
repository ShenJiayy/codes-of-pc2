#include<bits/stdc++.h>
using namespace std;
constexpr int inf=2e5+10;
struct Hina{
    int nxt,lst;
    char v;
};
struct Rukia{
    Hina a[inf];
    int cnt,stt=1,lss=1,sz;
    inline void restart(){
        for(int i=0;i<inf;i++) a[i].v='!';
    }
    inline int size(){
        return sz;
    }
    inline bool empty(){
        return !(bool)(size());
    }
    inline bool insert(int x,char y)/*在id为x的值后面插入y*/{
        if(x==lss) lss=x+1;
        sz++;
        a[++cnt].nxt=a[x].nxt,a[cnt].lst=x,a[a[x].nxt].lst=cnt,a[x].nxt=cnt,a[cnt].v=y;
        return 1;
    }
    inline bool del(int x){
        if(x==stt) stt=a[x].nxt;
        if(x==lss) lss=a[x].lst;
        a[x].v='!',a[a[x].lst].nxt=a[x].nxt,a[a[x].nxt].lst=a[x].lst,sz--;
        return 1;
    }
    inline void push_back(char x){
        insert(size(),x);
        return;
    }
}List,llist;
int n,k;
char tt;
inline int slv(){
    llist=List;
    // for(int j=llist.stt;llist.a[j].v!='!';j=llist.a[j].nxt) cout<<llist.a[j].v;
    // cout<<'\n';
    int i,cnt=0,ans=0;
    for(i=llist.stt;llist.a[i].v!='!';i=llist.a[i].nxt){
        if(cnt==k) break;
        if(llist.a[i].v!='J') ans++,llist.del(i);
        else cnt++;
    }
    if(cnt!=k) return INT_MAX;
    cnt=0;
    for(;llist.a[i].v!='!';i=llist.a[i].nxt){
        if(cnt==k) break;
        if(llist.a[i].v!='O') ans++,llist.del(i);
        else cnt++;
    }
    if(cnt!=k) return INT_MAX;
    cnt=0;
    for(;llist.a[i].v!='!';i=llist.a[i].nxt){
        if(cnt==k) break;
        if(llist.a[i].v!='I') ans++,llist.del(i);
        else cnt++;
    }
    if(cnt!=k) return INT_MAX;
    return ans;
}
int main(){
    freopen("jjooii.in","r",stdin);
    freopen("jjooii.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    List.restart();
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>tt,List.push_back(tt);
    for(int i=List.stt;List.a[i].v!='!';i=List.a[i].nxt){
        if(List.a[i].v=='J') break;
        else List.del(i);
    }
    for(int i=List.lss;List.a[i].v!='!';i=List.a[i].lst){
        if(List.a[i].v=='I') break;
        else List.del(i);
    }
    int mxn=INT_MAX;
    mxn=min(mxn,slv());
    if(mxn==INT_MAX){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n-k*3;i++){
        List.del(List.stt),mxn=min(mxn,slv());
        // for(int j=List.stt;List.a[j].v!='!';j=List.a[j].nxt) cout<<List.a[j].v;
        // cout<<'\n'<<List.stt<<' '<<List.size()<<' '<<mxn<<'\n';
    }
    cout<<mxn;
    return 0;
}
