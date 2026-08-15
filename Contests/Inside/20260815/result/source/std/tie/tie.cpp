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
const int Maxn = 2e5+10;
const int Inf = 0x7f7f7f7f;
const ll Inf_ll = 1ll*Inf*Inf;
const int Mod = 1e9+7;
const double eps = 1e-7;

int n;
pii a[Maxn];
int pre[Maxn], suf[Maxn], b[Maxn], Ans[Maxn];

int main(){
    freopen("tie.in","r",stdin);
    freopen("tie.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n+1;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    for(int i=1;i<=n;i++)  cin>>b[i];
    sort(a+1, a+2+n), sort(b+1, b+1+n);
    for(int i=1;i<=n;i++)  pre[i] = max(pre[i-1], max(a[i].first-b[i], 0));
    for(int i=n;i>=1;i--)  suf[i+1] = max(suf[i+2], max(a[i+1].first-b[i], 0));
    for(int i=1;i<=n+1;i++)  Ans[a[i].second] = max(pre[i-1], suf[i+1]);
    for(int i=1;i<=n+1;i++)  cout<<Ans[i]<<" ";
    return 0;
}