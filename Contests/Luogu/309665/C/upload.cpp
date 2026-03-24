#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int f[N + 5];
bool vis[N + 5];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    memset(vis, 1, sizeof vis);
    vis[0] = vis[1] = 0;
    int a, b, p;
    cin >> a >> b >> p;
    for (int i = a; i <= b; i ++)
        f[i] = i;
    int cnt = b - a + 1;
    for (int i = 2; i <= b; i ++)
        if (vis[i]) {
            if (i >= p) 
                for (int j = 2 * i; j <= b; j += i) {
                    vis[j] = 0;
                    if (j - i >= a && find(j) != find(j - i))
                        f[find(j)] = find(j - i), cnt --;
                }
            else
                for (int j = 2 * i; j <= b; j += i)
                    vis[j] = 0;
        }
    cout << cnt;
    return 0;
}