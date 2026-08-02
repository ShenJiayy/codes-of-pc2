#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int c[N + 5], a[N + 5];
vector<int> vals[N + 5], all;
int t[N + 5];
inline int lowbit(int x) { return x & -x; }
inline int query(int p) { int ans = 0; for (; p; p -= lowbit(p)) ans += t[p]; return ans; }
inline void update(int p, int d) { for (; p <= N; p += lowbit(p)) t[p] += d; }
inline int getans(vector<int> v) {
    int ret = 0;
    reverse(v.begin(), v.end());
    for (auto val : v) {
        ret += query(val - 1);
        update(val, 1);
    }
    for (auto val : v) 
        update(val, -1);
    return ret;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> c[i];
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        vals[c[i]].push_back(a[i]);
        all.push_back(a[i]);
    }
    int ans = getans(all);
    for (int i = 1; i <= n; i ++)
        if (!vals[i].empty())
            ans -= getans(vals[i]);
    cout << ans;
    return 0;
}
