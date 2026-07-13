#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    string s, t;
    cin >> s >> t;
    s += s;
    int ans = s.find(t);
    if (ans == string::npos)
        cout << -1;
    else cout << ans;
    cout << endl;
}
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}