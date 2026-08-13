#include <bits/stdc++.h>
using namespace std;
#define int long long
#define judge
const int N = 5e5;
struct pict {
    int size, value;
} a[N + 5];
bool cmpsize(pict x, pict y) {
    return x.size < y.size;
}
int s[N + 5];
signed main() {
    #ifdef judge
        freopen("art.in", "r", stdin);
        freopen("art.out", "w", stdout);
    #else
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        freopen("data.log", "w", stderr);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].size >> a[i].value;
    // bs + amin - amax
    sort(a + 1, a + n + 1, cmpsize);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i].value;
    int ans = 0;
    for (int st = 1; st <= n; st ++)
        for (int ed = st; ed <= n; ed ++) 
            ans = max(ans, s[ed] - s[st - 1] + a[st].size - a[ed].size);
    cout << ans;
    return 0;
}
