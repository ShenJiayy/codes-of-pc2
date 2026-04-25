#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e6;
char ans[M + 5];
int a[M + 5];
int n, m;
bool dfs(int l, int r, int s, int t) {
    for (int id = 1; id < n; id ++) {
        if (s - 1 > l && a[l] == a[s - 1]) {
            ans[id] = 'L', ans[m - id] = 'L';
            l ++, s --;
        }
        else if (t < r && a[t + 1] == a[l]) {
            ans[id] = 'L', ans[m - id] = 'R';
            l ++, t ++;
        }
        else if (s > l && a[r] == a[s - 1]) {
            ans[id] = 'R', ans[m - id] = 'L';
            r --, s --;
        }
        else if (t + 1 < r && a[r] == a[t + 1]) {
            ans[id] = 'R', ans[m - id] = 'R';
            r --, t ++;
        }
        else return 0;
    }
    return 1;
}
void solve() {
    cin >> n;
    m = n * 2 - 1;
    for (int i = 0; i <= m; i ++)
        cin >> a[i];
    memset(ans, 0, sizeof ans);
    ans[m] = 'L';
    ans[0] = 'L';
    int pos = 1;
    while (a[pos] != a[0]) pos ++;
    if (dfs(1, m, pos, pos)) {
        for (int i = 0; i <= m; i ++)
            cout << ans[i];
        cout << endl;
        return ;
    }
    ans[0] = 'R';
    pos = 0;
    while (a[pos] != a[m]) pos ++;
    if (dfs(0, m - 1, pos, pos)) {
        for (int i = 0; i <= m; i ++)
            cout << ans[i];
        cout << endl;
        return ;
    }
    cout << -1 << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) solve();
    return 0;
}