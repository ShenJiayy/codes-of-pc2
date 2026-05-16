#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> st[N + 5], ed[N + 5];
struct Node {
    int l, r;
} a[N + 5];
bool solve(int s, int t) {
    
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
        solve(s, t);
    }
    return 0;
}