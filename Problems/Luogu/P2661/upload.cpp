#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int f[N + 5], fr[N + 5];
int find(int id) {
    if (f[id] != id) {
        int cf = f[id];
        f[id] = find(f[id]);
        fr[id] += fr[cf];
    }
    return f[id];
}
int ans = 9e18;
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
        fr[x] = fr[y] + 1;
    }
    else
        ans = min(ans, fr[x] + fr[y] + 1);
}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        f[i] = i;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        merge(i, x);
    }
    cout << ans;
    return 0;
}
