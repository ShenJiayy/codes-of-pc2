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
const int Mod = 1e9+7;
const double eps = 1e-7;

int n, k;
string s;
vector<int> v[3];

int main(){
    freopen("jjooii.in","r",stdin);
    freopen("jjooii.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){
        if( s[i] == 'J' )  v[0].push_back(i+1);
        else if( s[i] == 'O' )  v[1].push_back(i+1);
        else v[2].push_back(i+1);
    }
    int ans = Inf;
    for(int l=0;l<si(v[0]);l++){
        if( l+k > si(v[0]) )  break;
        int posO = lower_bound(all(v[1]), v[0][l+k-1]) - v[1].begin();
        if( posO+k > si(v[1]) )  break;
        int posI = lower_bound(all(v[2]), v[1][posO+k-1]) - v[2].begin();
        if( posI+k > si(v[2]) )  break;
        ans = min(ans, v[2][posI+k-1]-v[0][l]+1 - 3*k);
    }
    if( ans == Inf )  cout<<"-1\n";
    else cout<<ans<<'\n';
    return 0;
}