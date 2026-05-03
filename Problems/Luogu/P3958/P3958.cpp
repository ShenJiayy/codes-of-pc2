#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e3;
struct Pos {
    int x, y, z;
} a[N + 5];
int f[N + 5];
int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
void init(int n) {
    for (int i = 1; i <= n; i ++)
        f[i] = i;
}
int calc(Pos x, Pos y) {
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y) + (x.z - y.z) * (x.z - y.z);
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int T;
    cin >> T;
    while (T --) {
        int n, h, r;
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i ++)
            cin >> a[i].x >> a[i].y >> a[i].z;
        init(n);
        vector<int> getdown, getup;
        for (int i = 1; i <= n; i ++) {
            if (a[i].z + r >= h)
                getup.push_back(i);
            if (a[i].z - r <= 0)
                getdown.push_back(i);
            for (int j = 1; j <= i; j ++) {
                if ((a[j].x - a[i].x) * (a[j].x - a[i].x) + (a[j].y - a[i].y) * (a[j].y - a[i].y) > 4 * r * r)
                    continue; // It's impossible.
                if (calc(a[i], a[j]) <= 4 * r * r) {
                    int fti = find(i), ftj = find(j);
                    f[fti] = ftj;
                }
            }
        }
        bool ans = 0;
        for (int top : getup) {
            for (int bottom : getdown)
                if (find(top) == find(bottom)) {
                    ans = 1;
                    break;
                }
            if (ans)
                break;
        }
        cout << (ans?"Yes\n":"No\n");
    }
    return 0;
}