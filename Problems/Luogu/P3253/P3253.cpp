#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100000;
int s[N + 5], n;
struct Node { int a, i; } a[N + 5];
bool cmp(Node x, Node y) {
    return x.a > y.a;
}

int lowbit(int x) {
    return x & -x;
}
void AddSum(int p, int d) {
    for (; p <= n; p += lowbit(p))
        s[p] += d;
}
int GetSum(int p) {
    int sum = 0;
    for (; p; p -= lowbit(p))
        sum += s[p];
    return sum;
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n1, n2;
    cin >> n1 >> n2;
    n = n1 + n2;
    for (int i = n1; i >= 1; i --)
        cin >> a[i].a, a[i].i = i;
    for (int i = n1 + 1; i <= n1 + n2; i ++)
        cin >> a[i].a, a[i].i = i;
    for (int i = 1; i <= n; i ++)
        AddSum(i, 1);
    sort(a + 1, a + n + 1, cmp);
    int p1 = n1, p2, ans = 0;
    for (int i = 1; i <= n; i ++) {
        p2 = a[i].i;
        /*
        p1被用作堆1头
        p2被用作正在修改位
        */
        if (p1 < p2) {
            ans += GetSum(p2 - 1) - GetSum(p1);
            p1 = p2 - 1;
            AddSum(p2, -1);
        }
        else {
            ans += GetSum(p1) - GetSum(p2);
            p1 = p2;
            AddSum(p2, -1);
        }
    }
    cout << ans;
    return 0;
}