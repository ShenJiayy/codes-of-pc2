#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define judge
const int N = 5e5;
struct pict {
    int size, value;
} a[N + 5];
bool cmpsize(pict x, pict y) {
    return x.size < y.size;
}
int s[N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].size >> a[i].value;
    sort(a + 1, a + n + 1, cmpsize);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] + a[i].value;
    int ans1 = -9e18, ans2 = -9e18;
    // (s[i] - a[i].size) - (s[j - 1] - a[j].size)
    for (int i = 1; i <= n; i ++) {
        ans2 = max(ans2, -(s[i - 1] - a[i].size));
        ans1 = max(ans1, s[i] - a[i].size + ans2);
    }
    cout << ans1;
    return 0;
}
