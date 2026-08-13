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
const int Maxn = 5e5+10;
const int Inf = 0x7f7f7f7f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 1e9+7;
const double eps = 1e-7;

int n, Ans;
pii p[Maxn];
array<int,3> a[Maxn];
bool f[Maxn];
int c[Maxn];

int lowbit(int x){return x&(-x);}
void add(int x){
    while( x <= n ){
        c[x]++;
        x += lowbit(x);
    }
}
int sum(int x){
    int Sum = 0;
    while( x > 0 ){
        Sum += c[x];
        x -= lowbit(x);
    }
    return Sum;
}

void solve(bool st){
    vector<int> v;
    for(int i=1;i<=n;i++){
        if( st )  a[i] = {-p[i].first, p[i].first-p[i].second, i};
        else a[i] = {p[i].first, -p[i].first-p[i].second, i};
        v.push_back(a[i][1]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.ed);
    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++)  c[i] = 0;
    for(int i=1;i<=n;i++){
        int p = lower_bound(all(v), a[i][1]) - v.bg + 1;
        if( sum(p) != 0 )  f[a[i][2]] = false;
        add(p);
    }
}

int main(){
    // freopen("ad.in","r",stdin);
    // freopen("ad.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
        f[i] = true;
    }
    solve(0), solve(1);
    for(int i=1;i<=n;i++)  Ans += f[i];
    // disp(f, 1, n);
    cout<<Ans<<endl;
    return 0;
}