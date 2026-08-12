#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, M = 4e5;
int a[N + 5];
struct Query {
    int l, r, x;
} qs[N + 5];
namespace s1 {
    int solve(int n, int T) {
        for (int i = 1; i <= T; i ++) {
            vector<int> v;
            for (int j = qs[i].l; j <= qs[i].r; j ++)
                if (a[j] > qs[i].x)
                    v.push_back(j);
            v.push_back(0);
            int cnt = 0;
            for (int j = 1; j < v.size(); j ++)
                if (v[j] != v[j - 1] + 1)
                    cnt ++;
            cout << cnt << endl;
        }
        return 0;
    }
}
namespace s2 {
    int t[M + 5];
    inline int lowbit(int x) { return x & -x; }
    inline void update(int p, int d) { 
        for (; p <= M; p += lowbit(p)) 
            t[p] += d; 
    }
    inline int query(int p) {
        int ret = 0;
        for (; p; p -= lowbit(p))
            ret += t[p];
        return ret;
    }
    int solve(int n, int T) {
        set<int> tmp;
        map<int, int> mp;
        for (int i = 1; i <= n; i ++)
            tmp.insert(a[i]);
        for (int t = 1; t <= T; t ++)
            tmp.insert(qs[t].x);
        int curr = 0;
        for (int val : tmp)
            mp[val] = ++ curr;
        
        for (int i = 1; i <= n; i ++)
            update(mp[a[i]], 1);
        for (int i = 1; i <= T; i ++) 
            cout << n - query(mp[qs[i].x]) << endl;
        return 0;
    }
}
namespace s3 {
    int solve(int n, int T) {
        int minpos = min_element(a + 1, a + n + 1) - a;
        for (int t = 1; t <= T; t ++) {
            if (qs[t].x < a[minpos]) {
                puts("1");
                continue;
            }
            int maxn = max(a[qs[t].l], a[qs[t].r]);
            if (qs[t].x > maxn) {
                puts("0");
                continue;
            }
            if (qs[t].r < minpos || qs[t].l > minpos) {
                puts("1");
                continue;
            }
            int minn = min(a[qs[t].r], a[qs[t].l]);
            if (minn > qs[t].x)
                puts("1");
            else puts("2");
        }
        return 0;
    }
}
int getcase(int n, int T) {
    if (n <= 2000)
        return 1;
    bool f2 = 1;
    for (int i = 1; i <= n; i ++)
        f2 &= qs[i].l == 1 && qs[i].r == n;
    if (f2) return 2;
    return 3;
}
signed main() {
    freopen("zatopljenje.in", "r", stdin);
    freopen("zatopljenje.out", "w", stdout);
    int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int t = 1; t <= T; t ++)
        cin >> qs[t].l >> qs[t].r >> qs[t].x;
    int cs = getcase(n, T);
    if (cs == 1)
        return s1::solve(n, T);
    if (cs == 2)
        return s2::solve(n, T);
    if (cs == 3)
        return s3::solve(n, T);
    return 0;
}