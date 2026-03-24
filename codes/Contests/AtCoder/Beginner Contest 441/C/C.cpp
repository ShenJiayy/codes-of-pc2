#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local
const int N = 3e5;
int a[N + 5], s[N + 5];
bool cmp(int x, int y) { return x > y; }
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i];
    // 至少选n-k+1个，否则就会寄
    for (int i = n - k + 1; i <= n; i ++) {
        // 按最不利来想
        if (s[i] - s[n - k] >= x) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}