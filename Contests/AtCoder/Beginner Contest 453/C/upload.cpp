#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
int a[N + 5], n, ans;
bool drtrt[N + 5];
void dfs(int id) {
    if (id > n) {
        int cnt = 0;
        double pos = 0.5;
        for (int i = 1; i <= n; i ++) {
            double bpos = pos;
            if (drtrt[i])
                pos += a[i];
            else pos -= a[i];
            if (bpos > 0 && pos < 0 || bpos < 0 && pos > 0) cnt ++;
        }
        ans = max(ans, cnt);
        return ;
    }
    drtrt[id] = 1;
    dfs(id + 1);
    drtrt[id] = 0;
    dfs(id + 1);
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1);
    cout << ans;
    return 0;
}