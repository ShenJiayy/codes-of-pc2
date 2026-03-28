#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e4, M = 1e5;
int a[N + 5], n, ld[N + 5], ru[N + 5], rd[N + 5], s[N + 5];
struct Node {
    int a, i;
} b[N + 5];
bool cmp(Node x, Node y) {
    return x.a < y.a;
}

int lowbit(int x) {
    return x & -x;
}

void AddNum(int p, int d) {
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
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++)
        scanf(" %lld", &b[i].a), b[i].i = i;
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        if (b[i].a != b[i - 1].a || i == 1)
            a[b[i].i] = i;
        else
            a[b[i].i] = a[b[i - 1].i];
    }
    for (int i = 1; i <= n; i ++) {
        ld[i] = GetSum(a[i] - 1);
        AddNum(a[i], 1); 
    }
    memset(s, 0, sizeof s);
    for (int i = n; i >= 1; i --) {
        ru[i] = GetSum(n - a[i]);
        AddNum(n - a[i] + 1, 1); 
    }
    int ans = 0;
    for (int i = 2; i < n; i ++)
        ans += ld[i] * ru[i];
    cout << ans;
    return 0;
}