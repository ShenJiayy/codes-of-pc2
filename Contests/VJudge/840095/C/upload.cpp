#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int t[N + 5], n;
struct Query {
    int v, c;
} qs[N + 5];
inline int lowbit(int x) { return x & -x; }
inline int query(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p))
        sum += t[p];
    return sum;
}
inline void update(int p, int d) {
    for (; p <= N; p += lowbit(p))
        t[p] += d;
}
int find(int x) {
    int l = 1, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (query(mid) >= (x + 1) / 2)
            r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
signed main() {
    cin >> n;
    set<int> vals;
    for (int i = 1; i <= n; i ++) {
        cin >> qs[i].v >> qs[i].c;
        vals.insert(qs[i].v);
    }
    int cnt = 0;
    map<int, int> mp, mmp;
    for (int val : vals)
        cnt ++, mp[val] = cnt, mmp[cnt] = val;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        sum += qs[i].c;
        update(mp[qs[i].v], qs[i].c);
        cout << mmp[find(sum)] << endl;
    }
    return 0;
}