#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int s[N + 5], n, s2[N + 5];
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

int main() {
    freopen(".\\inputs\\1.txt", "r", stdin);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        add(i, x);
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
                l = r = 1;
                cin >> k;
                add(l, k);
                add(r + 1, -k);
                break;
            case 3:
                l = r = 1;
                cin >> k;
                k = -k;
                add(l, k);
                add(r + 1, -k);
                break;
            case 4:
                cin >> l >> r;
                cout << GetSum(r) - GetSum(l - 1) << endl;
                break;
            case 5:
                l = r = 1;
                cout << GetSum(r) - GetSum(l - 1) << endl;
                break;
            default:
                break;
        }

    }
    return 0;
}