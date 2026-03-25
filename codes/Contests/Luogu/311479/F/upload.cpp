#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct Node {
    int l, r, k;
} a[N + 5];
bool cmp(Node x, Node y) {
    if (x.r != y.r)
        return x.r < y.r;
    return x.l < y.l;
}
int p[N + 5];
map<int, bool> flg;
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= k; i ++)
        cin >> a[i].l >> a[i].r >> a[i].k;
    sort(a + 1, a + k + 1, cmp);
    for (int i = 1; i <= k; i ++) {
        // 写一个O(knlogn)，到时候去补成O(klogn)
        for (int j = a[i].r - a[i].k + 1; j <= a[i].r; j ++) {
            if (flg.count(j) == 0)
                flg[j] = 1;
        }
    }
    cout << n - flg.size() << endl;
    flg.clear();
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}