#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[15], n, r;
bool vis[15];
void dfs(int id) {
    if (id > r) {
        for (int i = 1; i <= r; i ++) cout << a[i];
        cout << endl;
        return ;
    }
    for (int i = 1; i <= n; i ++)
        if (!vis[i]) {
            vis[i] = 1;
            a[id] = i;
            dfs(id + 1);
            vis[i] = 0;
        }
}
signed main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}
