#include<bits/stdc++.h>
using namespace std;
#define maxn 200005

struct SegT
{
    struct node
    {
        int l=0, r=0, ans=0;
        node operator+(node b) {return {l, b.r, ans+b.ans-(r&&r==b.l)};}
        void operator=(int b) {l=r=ans=b;}
    }tr[maxn<<2];

    #define lc   (x<<1)
    #define rc   (x<<1|1)
    #define mid  ((l+r)>>1)
    #define lson lc, l, mid
    #define rson rc, mid+1, r
    #define rt   1, 1, n

    void push_up(int x) {tr[x]=tr[lc]+tr[rc];}

    void modify(int x, int l, int r, int p)
    {
        if(l==r) return tr[x]=1;
        if(p<=mid) modify(lson, p);
        if(p>mid)  modify(rson, p);
        push_up(x);
    }

    node query(int x, int l, int r, int L, int R)
    {
        if(L<=l&&r<=R) return tr[x];
        if(R<=mid) return query(lson, L, R);
        if(L>mid)  return query(rson, L, R);
        return query(lson, L, R)+query(rson, L, R);
    }
}tr; // 线段树部分

vector<tuple<int, int, int, int>> qrs; // 储存离线询问
vector<int> adds[maxn] /*存储每次新加入的节点*/, hgt;
int lis[maxn], ans[maxn];
bool cmp();
int main()
{
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>lis[i];
    for(int i=1, l, r, x;i<=q;i++)
        cin>>l>>r>>x, 
        qrs.emplace_back(x, l, r, i), 
        hgt.emplace_back(x);
    // sort(qrs.begin(), qrs.end(), greater());
    // sort(hgt.begin(), hgt.end(), greater());
    for(int i=1;i<=n;i++) 
        adds[upper_bound(hgt.begin(), hgt.end(), lis[i], cmp)-hgt.begin()+1].emplace_back(i); // 向桶内添加节点
    int cnt=1;
    for(auto [h, l, r, i]:qrs)
    {
        for(auto v:adds[cnt++]) tr.modify(rt, v); 
        ans[i]=tr.query(rt, l, r).ans; // 先改再查
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
}
