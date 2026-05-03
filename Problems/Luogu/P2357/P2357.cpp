#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5;
int s[N + 5], n, s2[N + 5], fst;
int lowbit(int x) {
    return x & -x;
}
void add(int p, int d) {
    for (int i = p; i <= n; i += lowbit(i))
        s[i] += d, s2[i] += d * p;
}
int GetSum(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += s[i] * (x + 1) - s2[i];
    return sum;
}

signed main() {
    freopen(".\\inputs\\1.txt", "r", stdin);
    int q, lst = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        add(i, x - lst);
        lst = x;
    }
    while (q --) {
        int op, l, r, k;
        cin >> op;
        switch (op) {
            case 1:
                cin >> l >> r >> k;
                add(l, k);
                add(r + 1, -k);
                break;
            case 2:
                cin >> k;
                fst += k;
                break;
            case 3:
                cin >> k;
                fst -= k;
                break;
            case 4:
                cin >> l >> r;
                cout << GetSum(r) - GetSum(l - 1) + (l == 1) * fst << endl;
                break;
            case 5:
                cout << GetSum(1) + fst << endl;
                break;
            default:
                break;
        }

    }
    return 0;
}