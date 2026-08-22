#include <bits/stdc++.h>

#define ed end()
#define bg begin()
#define mp make_pair
#define pb push_back
#define all(x) x.bg,x.ed
#define newline puts("")
#define si(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int Maxn = 1e6+10;
const int Inf = 0x7f7f7f7f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 1e9+7;
const double eps = 1e-7;

int n, a[Maxn];
vector<pii> vp;

struct res{
    int cnt;
    bitset<2020> b;
};

res solve(vector<pii> s) {
    sort(all(s));
    int len = s.size();
    res ret;
    ret.b.reset();
    if( len == 1 ){
        ret.cnt = 1;
        ret.b.set(s[0].second);
        return ret;
    }
    pii L = s.front(), R = s.back();
    vector<pii> nxt;
    for(int i=1;i+1<len;i++){
        nxt.push_back(s[i]);
    }
    nxt.push_back({R.first - L.first, R.second});
    res st = solve(nxt);
    if( st.b[R.second] )  return st;
    else{
        ret.cnt = len;
        for(auto p:s)  ret.b.set(p.second);
        return ret;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int T;
    cin>>T>>n;
    for(int i=1;i<=n;i++)  cin>>a[i], vp.push_back({a[i], i});
    cout<<solve(vp).cnt<<'\n';
    for(int i=2,m;i<=T;i++){
        cin>>m;
        vp.clear();
        for(int j=1,x,v;j<=m;j++){
            cin>>x>>v;
            a[x] = v;
        }
        for(int j=1;j<=n;j++)  vp.push_back({a[j], j});
        cout<<solve(vp).cnt<<'\n';
    }
    return 0;
}