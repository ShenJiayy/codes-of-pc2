#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int Q = 2e5, N = 4e5 + 5;
pii ql[Q + 5];
int t[N + 5];
int idx = 0;
int lowbit(int x) { return x & -x; } 
void update(int p, int d) { 
    for (; p <= N; p += lowbit(p)) 
        t[p] += d; 
}
int query(int p) { 
    int ret = 0; 
    for (; p; p -= lowbit(p)) 
        ret += t[p]; 
    return ret; 
}
int find(int id) {
    int l = 1, r = N, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (query(mid) >= id)
            ans = mid, r = mid - 1;
        else l = mid + 1;
        // cerr << l << " " << r << " " << ans << endl;
    }
    return ans;
}
signed main() {
    map<int, int> nmp, mp, fmp;
    int x, T;
    cin >> x >> T;
    nmp[x] ++;
    ql[0] = {x, 0};
    for (int i = 1; i <= T; i ++) {
        int y;
        cin >> x >> y;
        nmp[x] ++, nmp[y] ++;
        ql[i] = {x, y};
    }
    // 先离散化
    for (auto kv : nmp) 
        idx ++,
        mp[kv.first] = idx,
        fmp[idx] = kv.first;
    update(mp[ql[0].first], 1);
    for (int i = 1; i <= T; i ++) {
        int y = mp[ql[i].second];
        x = mp[ql[i].first];
        update(x, 1);
        update(y, 1);
        cout << fmp[find(i + 1)] << endl;
    }
    return 0;
}
