#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5;
int s[N + 5], n, b[N + 5];
struct Node { int a, i; } a[N + 5];

bool cmp(Node x, Node y) {
    if (x.a != y.a)
        return x.a < y.a;
    return x.i < y.i;
}
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
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].a, a[i].i = i;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        b[a[i].i] = i;
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        AddNum(b[i], 1);
        sum += i - GetNum(b[i]);
    }
    cout << sum;
    return 0;
}