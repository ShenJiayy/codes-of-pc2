#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4000;
int a[N + 5], b[N + 5], f[N + 5], bak[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++) {
        int vl = 0;
        if (b[0] < a[0])
            vl = bak[0] + 1;
        for (int j = 1; j <= n; j ++) {
            if (a[i] == b[j]) f[j] = vl + 1;
            else f[j] = bak[j];
            if (b[j] < a[i]) vl = max(vl, bak[j]);
        }
        memcpy(bak, f, sizeof f);
    }
    cout << *max_element(f + 1, f + n + 1);
    return 0;
}