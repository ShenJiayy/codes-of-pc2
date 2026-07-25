#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int a[N + 5], f[N + 5], ba[N + 5];
bool vis[N + 5];
struct Query {
    int opt, val;
} qs[N + 5];
void init(int n) {
    for (int i = 1; i <= n; i ++)
        f[i] = i;
}
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
    else vis[ftx] = 1;
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i], ba[i] = a[i];
    int T;
    cin >> T;
    for (int i = 1; i <= T; i ++) {
        cin >> qs[i].opt >> qs[i].val;
        if (qs[i].opt == 2)
            a[qs[i].val] = 0;
    }
    init(n);
    for (int i = 1; i <= n; i ++)
        if (a[i])
            merge(i, a[i]);
    deque<int> ans;
    for (int i = T; i >= 1; i --) {
        if (qs[i].opt == 1)
            if (vis[find(qs[i].val)])
                ans.push_front(-1);
            else ans.push_front(find(qs[i].val));
        else
            merge(qs[i].val, ba[qs[i].val]);
    }
    for (int val : ans)
        if (val == -1)
            cout << "CIKLUS\n";
        else
            cout << val << endl;
    return 0;
}