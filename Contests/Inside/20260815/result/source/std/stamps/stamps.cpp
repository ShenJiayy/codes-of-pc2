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
const int Maxn = 440;
const int Inf = 0x3f3f3f3f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 1e9+7;
const double eps = 1e-7;

int n, m, L;
int a[Maxn], t[Maxn];
ll f[402][402][210][2];

int main(){
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>L;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n+1] = a[i] + L;
    }
    for(int i=1;i<=n;i++){
        cin>>t[i];
        t[i+n+1] = t[i];
    }
    a[n+1] = L;
    m = 2*n+1;
    // disp(a, 1, m);
    // disp(t, 1, m);
    memset(f, 0x3f,  sizeof(f));
    f[n+1][n+1][0][0] = f[n+1][n+1][0][1] = 0;
    int ans = 0;
    for(int len=2;len<=n+1;len++){
        for(int l=1;l+len-1<=m;l++){
            int r = l+len-1;
            if( n+1 < l || r < n+1 )  continue;
            for(int k=0;k<=n+1;k++){
                for(int p1=0;p1<=1;p1++) for(int p3=0;p3<=1;p3++){
                    int pos = a[l], tim = t[l], pl = l+1, pr = r;
                    if( p1 ) pos = a[r], tim = t[r];
                    if( p1 )  pl = l, pr = r-1;
                    int posf = a[pl];
                    if( p3 )  posf = a[pr];
                    if( abs(posf-pos) == 0 )  continue;
                    if( f[pl][pr][k][p3] + abs(posf-pos) <= tim )
                        f[l][r][k+1][p1] = min(f[l][r][k+1][p1], f[pl][pr][k][p3] + abs(posf-pos));
                    else 
                        f[l][r][k][p1] = min(f[l][r][k][p1], f[pl][pr][k][p3] + abs(posf-pos));
                }
                
                if( f[l][r][k][0] < Inf_ll || f[l][r][k][1] < Inf_ll )  ans = max(ans, k);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
4 10000 
1 2000 8000 9999
1000000000 3999 3999 1000000000
*/