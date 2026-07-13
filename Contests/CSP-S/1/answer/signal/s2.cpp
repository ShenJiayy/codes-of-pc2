#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200000;
struct Node {
    string opt;
    int u, v;
} a[N + 5];
int dfs(int id) {
    if (a[id].opt == "IN") return a[id].u;
    if (a[id].opt == "NEG") return -dfs(a[id].u);
    if (a[id].opt == "MIN") return min(dfs(a[id].u), dfs(a[id].v));
    if (a[id].opt == "MAX") return max(dfs(a[id].u), dfs(a[id].v));
    if (a[id].opt == "ADD") return dfs(a[id].u) + dfs(a[id].v);
    return 0;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].opt >> a[i].u;
        if (a[i].opt != "NEG") cin >> a[i].v;
    }
    for (int i = 1; i <= n; i ++) {
        if (a[i].opt != "IN") continue;
        swap(a[i].u, a[i].v);
        cout << dfs(1) << " ";
        swap(a[i].u, a[i].v);
    }
    cout << endl;
}
signed main() {
    freopen("signal.in", "r", stdin);
    freopen("signal.out", "w", stdout);
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}