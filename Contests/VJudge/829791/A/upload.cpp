#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2.5e5;
struct Node {
    int id, x, y;
} a[N + 5];
bool cmp1(Node x, Node y) {
    if (x.x != y.x)
        return x.x < y.x;
    return x.y < y.y;
}
bool cmp2(Node x, Node y) {
    if (x.y != y.y)
        return x.y < y.y;
    return x.x < y.x;
}
bool cmp3(Node x, Node y) {
    return x.id < y.id;
}
signed main() {
    a[0] = {0, 0, 0};
	int n;
    cin >> n;
    int ans = 9e18;
    int sx = 0, sy = 0, np, nq;
    for (int i = 1; i <= n; i ++) {
        char c;
        cin >> c;
        if (c == 'N')
            sx ++;
        if (c == 'E')
            sy ++;
        if (c == 'S')
            sx --;
        if (c == 'W')
            sy --;
        a[i] = {i, sx, sy};
    }
    sort(a + 1, a + n + 1, cmp1);
    for (int i = 1; i <= n; i ++) {
        if (a[i].x != a[i - 1].x) continue;
        if (abs(a[i].id - a[i - 1].id) == 1) continue;
        int yc = abs(a[i].y - a[i - 1].y);
        int p = a[i].id, q = a[i - 1].id;
        if (p > q) swap(p, q);
        if (ans > yc) 
            ans = yc, np = p, nq = q;
        else if (ans == yc)
            if (/*a[p].id*/)
    }
    return 0;
}
