#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local
const int N = 2e5;
int s[N + 5], n, a[N + 5];
int lowbit(int x) {
    return x & -x;
}
void AddNum(int p, int d) {
    while (p <= N) {
        s[p] += d;
        p += lowbit(p);
    }
}
int GetNum(int p) {
    int ans = 0;
    while (p) {
        ans += s[p];
        p -= lowbit(p);
    }
    return ans;
}
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        AddNum(i, +a[i]);
    }
    while (q --) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            AddNum(x, -a[x] + +a[x+1]);
            AddNum(x+1, -a[x+1] + +a[x]);
            swap(a[x], a[x + 1]);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << GetNum(r) - GetNum(l - 1) << endl;
        }
    }
    return 0;
}
// 102 83