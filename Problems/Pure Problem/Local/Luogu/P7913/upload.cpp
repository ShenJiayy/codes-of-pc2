#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f1[N + 5], f2[N + 5];
struct Node {
    int l, r; // t id
} a[N + 5];
bool operator < (Node x, Node y) {
    return x.l > y.l;
}
bool cmp(Node x, Node y) {
    return x.l < y.l;
}
void solve(int n, int m, int s[]) {
    priority_queue<Node> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    for (int i = 1; i <= m; i ++) 
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= n; i ++) 
        q2.push(i);
    for (int i = 1; i <= m; i ++) {
        while (!q1.empty() && q1.top().l <= a[i].l)
            q2.push(q1.top().r), q1.pop();
        if (!q2.empty()) {
            s[q2.top()] ++;
            q1.push({a[i].r, q2.top()});
            q2.pop();
        }
    }
    s[0] = 0;
    for (int i = 1; i <= n; i ++)
        s[i] += s[i - 1];
}
signed main() {
	int n, p, q;
    cin >> n >> p >> q;
    solve(n, p, f1);
    solve(n, q, f2);
    int ans = 0;
    for (int i = 0; i <= n; i ++)
        ans = max(ans, f1[i] + f2[n - i]);
    cout << ans;
    return 0;
}
