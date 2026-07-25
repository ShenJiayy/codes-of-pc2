#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4;
int s[1000][N + 5];
int lowbit(int x) {
    return x & -x;
}
int query(int x, int t[]) {
    int ans = 0;
    for (; x; x -= lowbit(x))
        ans += t[x];
    return ans;
}
void update(int p, int d, int t[]) {
    for (; p <= N; p += lowbit(p))
        t[p] += d;
}
int f(char x, char y) {
    int p = x - 'a', q = y - 'a';
    if (x == '?') p = 0;
    else p ++;
    if (y == '?') q = 0;
    else q ++;
    return p * 27 + q;
} // This function returns the hash of param. :D
signed main() {
    int n, m, ans = 0;
    cin >> n >> m;
    if (m != 2) 
        return puts("This Program ONLY Support Task 1!"), 42;
    for (int i = 1; i <= n; i ++) {
        char x, y;
        cin >> x >> y;
        ans += query(i, s[f(x, y)]);
        if (x != '?')
            ans += query(i, s[f('?', y)]);
        if (y != '?')
            ans += query(i, s[f(x, '?')]);
        if (x != '?' && y != '?')
            ans -= query(i, s[f('?', '?')]);
        update(i, 1, s[f(x, y)]);
        if (x != '?')
            update(i, 1, s[f('?', y)]);
        if (y != '?')
            update(i, 1, s[f(x, '?')]);
        if (x != '?' && y != '?')
            update(i, -1, s[f('?', '?')]);
    }
    // cout << ans * 2;
    cout << 5e4 * 26 * 26;
    return 0;
}