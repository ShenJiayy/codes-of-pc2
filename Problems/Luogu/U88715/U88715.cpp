#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200000;
int l1u[N + 5], l1d[N + 5], l2u[N + 5], l2d[N + 5], s[N + 5], n, a[N + 5];

int lowbit(int x) {
    return x & -x;
}

void AddNum(int p, int d) {
    for (; p <= n; p += lowbit(p))
        s[p] += d;
}

int GetNum(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p))
        sum += s[p];
    return sum;
}

signed main() {
    freopen("in.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        // l1u[i]表示从左往右数，比a[i]大的个数
        // l1d[i]表示从左往右数，比a[i]小的个数
        l1d[i] = GetNum(a[i] - 1);
        l1u[i] = GetNum(n) - GetNum(a[i]);
        AddNum(a[i], 1);
    }
    memset(s, 0, sizeof s);
    for (int i = n; i >= 1; i --) {
        // l2u[i]表示从右往左数，比a[i]大的个数
        // l1d[i]表示从右往左数，比a[i]小的个数
        l2d[i] = GetNum(a[i] - 1);
        l2u[i] = GetNum(n) - GetNum(a[i]);
        AddNum(a[i], 1);
    }
    int ansd = 0, ansu = 0;
    for (int i = 2; i < n; i ++)
        ansd += l1u[i] * l2u[i], ansu += l1d[i] * l2d[i];
    cout << ansd << " " << ansu;
    return 0;
}