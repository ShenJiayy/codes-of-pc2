#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define judge
const int N = 1e5;
int p[N + 5], s[N + 5];
signed main() {
    #ifdef judge
        freopen("tjelesni.in", "r", stdin);
        freopen("tjelesni.out", "w", stdout);
    #endif
    int n, q, m;
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i ++)
        cin >> p[i];
    while (q --) {
        int l, r;
        cin >> l >> r;
        // 把l~r的数按第一小 第一大 第二小 第二大 …… 排放
        for (int i = 0; i <= r - l; i ++)
            s[i] = p[i + l];
        sort(s, s + r - l + 1);
        int front = 0, tail = r - l;
        for (int i = 0; i <= r - l; i ++) {
            int v;
            if (i % 2 == 0) v = s[front ++];
            else v = s[tail --];
            p[i + l] = v;
        }
    }
    int pos = 0;
    for (int i = 1; i <= n; i ++)
        if (p[i] == m)
            pos = i;
    cout << pos;
    return 0;
}
