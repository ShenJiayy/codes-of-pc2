#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000, M = 1e6;
int c[N + 5];
struct Dish {
    int c, l;
} a[N + 5];
bool cmp(Dish x, Dish y) {
    return x.c < y.c;
}
vector<int> v[N + 5];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cin >> c[i];
    for (int i = 1; i <= n; i ++)
        cin >> a[i].c >> a[i].l;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        v[a[i].c].push_back(a[i].l);
    int tot = 0;
    for (int i = 1; i <= m; i ++) {
        sort(v[i].begin(), v[i].end(), greater<int>());
        int sum = 0;
        for (int x : v[i])
            if (sum < c[i])
                sum += x;
            else break;
        tot += min(sum, c[i]);
    }
    cout << tot;
    return 0;
}