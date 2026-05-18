#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e5;
vector<int> st[N + 5], ed[N + 5];
pii a[N + 5];
map<pii, int> mp;
bool cmp(pii x, pii y) {
    if (x.first == y.first)
        return x.second > y.second;
    return x.first < y.first;
}
int t[N + 5];
int lowbit(int x) { return x & -x; }
void update(int p, int d) { for (; p <= N; p += lowbit(p)) t[p] += d; }
int query(int p) { int ret = 0; for (; p; p -= lowbit(p)) ret += t[p]; return ret; }
int cnt[N + 5];
bool solve(int s, int t) {
    if (mp.count({s, t})) {
        int pos = mp[{s, t}];
        return cnt[pos] > 0;
    }
    int x = upper_bound(st[s].begin(), st[s].end(), t) - st[s].begin() - 1;
    int y = lower_bound(ed[t].begin(), ed[t].end(), s) - ed[t].begin();
    if (x >= 0 && y < ed[t].size()) {
        x = st[s][x], y = ed[t][y];
        return y <= x + 1;
    }
    return 0;
}
const string ans[2] = {"No\n", "Yes\n"};
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++) {
        cin >> a[i].first >> a[i].second;
        st[a[i].first].push_back(a[i].second);
        ed[a[i].second].push_back(a[i].first);
        mp[a[i]] ++;
    }
    for (int i = 1; i <= n; i ++)
        sort(st[i].begin(), st[i].end());
    for (int i = 1; i <= n; i ++)
        sort(ed[i].begin(), ed[i].end());
    sort(a + 1, a + m + 1, cmp);
    for (int i = m; i >= 1; i --)
        mp[a[i]] = i;
    for (int i = m; i >= 1; i --) {
        cnt[i] = query(a[i].second);
        update(a[i].second, 1);
    }
    int T;
    cin >> T;
    while (T --) {
        int s, t;
        cin >> s >> t;
        cout << ans[solve(s, t)];
    }
    return 0;
}