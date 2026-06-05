#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int p[N + 5], d[N + 5], s[N + 5];
struct Train {
    int a, b, c;
} a[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> p[i];
    for (int i = 2; i <= m; i ++) {
        int u = p[i - 1], v = p[i];
        if (u > v) swap(u, v);
        d[u] ++, d[v] --;
    }
    for (int i = 1; i < n; i ++)
        s[i] = s[i - 1] + d[i];
    for (int i = 1; i < n; i ++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    int sum = 0;
    for (int i = 1; i < n; i ++) {
        // <C_1> 选择a[i].a * cnt
        int c1 = a[i].a * s[i];
        // <C_2> 选择a[i].c + a[i].b * cnt
        int c2 = a[i].b * s[i] + a[i].c;
        sum += min(c1, c2);
    }
    cout << sum;
    return 0;
}
