#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N * 2 + 5];
char ans[N *2 + 5];
bool dfs(int id, int l, int r, int s, int t) {

}
void solve() {
    int n;
    scanf("%lld", n);
    int m = 2 * n;
    for (int i = 1; i <= m; i ++) scanf("%lld", a+i);
    memset(ans, 0, sizeof ans);
    ans[m] = 'L';
    ans[1] = 'L'; int p = 2;
    while (a[p] != a[1]) p ++;
    if (dfs(1, 1, m, p, p)) {
        puts(ans); return ;
    }
    ans[1] = 'L', p = 2;
    while (a[p] != a[1]) p ++;
    if (dfs(1, 1, m, p, p)) {
        puts(ans); return ;
    }
    puts("-1");
}
signed main() {
	int T;
    cin >> T;
    while (T --) solve();
    return 0;
}