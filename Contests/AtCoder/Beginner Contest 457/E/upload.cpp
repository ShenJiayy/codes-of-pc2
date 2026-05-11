#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> st[N + 5], ed[N + 5];
bool solve(int s, int t) {
    int fstmax = upper_bound(st[s].begin(), st[s].end(), t) - st[s].begin() - 1;
    int scdmin = lower_bound(ed[t].begin(), ed[t].end(), s) - ed[t].begin();
    // 第一个可选1~fstmax 第二个可选scdmin~n
    
}
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        int l, r;
        cin >> l >> r;
        st[l].push_back(r);
        ed[r].push_back(l);
    }
    for (int i = 1; i <= n; i ++)
        sort(st[i].begin(), st[i].end());
    for (int i = 1; i <= n; i ++)
        sort(ed[i].begin(), ed[i].end());
    int T;
    cin >> T;
    while (T --) {
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) ? "Yes\n" : "No\n";
    }
    return 0;
}