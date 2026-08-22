#include <bits/stdc++.h>

#define ed end()
#define bg begin()
#define mp make_pair
#define pb push_back
#define all(x) x.bg,x.ed
#define newline puts("")
#define si(x) ((int)x.size())
#define DEBUG
#define d1(x) std::cout << #x " = " << (x) << std::endl
#define d2(x, y) std::cout << #x " = " << (x) << " ," #y " = " << (y) << std::endl
#define disp(arry, fr, to) \
    { \
        std::cout << #arry " : "; \
        for(int _i = fr; _i <= to; _i++) std::cout << arry[_i] << " "; \
        std::cout << std::endl; \
    }

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int Maxn = 1e5+10;
const int Inf = 0x7f7f7f7f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 998244353;
const double eps = 1e-7;

inline int add(const int x, const int y){
    return x+y < Mod ? x+y : x+y-Mod;
}
inline int sub(const int x, const int y){
    return x-y >= 0 ? x-y : x-y+Mod;
}
inline int mul(const int x, const int y){
    return 1ll*x*y%Mod;
}

inline int mypow(int a, int b){
    int ret = 1;
    while( b > 0 ){
        if( b&1 )  ret = mul(ret, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ret;
}

int n, m, Q, a[Maxn];
vector<int> G[Maxn], G2[Maxn];
int Out[Maxn], In[Maxn], t[Maxn], num[Maxn];

struct Node{
    int op, x, v;
}b[Maxn];

void Gett(){
    fill(t+0, t+1+m, 1);
    queue<int> q;
    for(int i=0;i<=m;i++){
        if( Out[i] )  continue;
        if( b[i].op == 2 )  t[i] = b[i].v;
        q.push(i);
    }
    while( !q.empty() ){
        int u = q.front();  q.pop();
        for(auto v:G2[u]){
            t[v] = 1ll*t[v]*t[u]%Mod;
            Out[v]--;
            if( !Out[v] )  q.push(v);
        }
    }
    // disp(t, 0, m);
}

void topo(){
    queue<int> q;
    for(int i=0;i<=m;i++){
        if( !In[i] )  q.push(i);
    }
    num[0] = 1;
    while( !q.empty() ){
        int u = q.front(), tmp = 1;  q.pop();
        for(auto v:G[u]){
            num[v] = add(num[v], 1ll*tmp*num[u]%Mod);
            tmp = 1ll*tmp*t[v]%Mod;
            In[v]--;
            if( !In[v] )  q.push(v);
        }
    }
    // disp(num, 1, m);
    for(int i=1;i<=n;i++)  a[i] = 1ll*a[i]*t[0]%Mod;
    // disp(a, 1, n);
    for(int i=1;i<=m;i++){
        if( b[i].op == 1 )  a[b[i].x] = (a[b[i].x] + 1ll*b[i].v*num[i])%Mod;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("call.in","r",stdin);
    // freopen("call.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>b[i].op;
        if( b[i].op == 1 )  cin>>b[i].x>>b[i].v;
        else if( b[i].op == 2 )  cin>>b[i].v;
        else {
            cin>>b[i].x;
            Out[i] = b[i].x;
            for(int j=1,p;j<=b[i].x;j++){
                cin>>p;
                In[p]++;
                G[i].push_back(p);
                G2[p].push_back(i);
            }
            reverse(all(G[i]));
        }
    }
    cin>>Q;
    Out[0] = Q;
    for(int i=1,x;i<=Q;i++){
        cin>>x;
        G[0].push_back(x);
        G2[x].push_back(0);
        In[x]++;
    }
    reverse(all(G[0]));
    Gett();
    topo();
    for(int i=1;i<=n;i++){
        cout<<a[i];
        if( i != n )  cout<<' ';
    }
    return 0;
}