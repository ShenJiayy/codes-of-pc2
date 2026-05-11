#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> a[N + 5];
int c[N + 5], len[N + 5], ed[N + 5];
signed main() {
	int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> len[i];
        a[i].resize(len[i]);
        for (int j = 0; j < len[i]; j ++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    // a[i] * c[i]
    for (int i = 1; i <= n; i ++)
        ed[i] = ed[i - 1] + len[i] * c[i];
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (ed[mid] >= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    k -= ed[ans - 1];
    k --;
    // 1 2 3 4 5 6 7 8 9 ...
    k += len[ans];
    k %= len[ans];
    cout << a[ans][k];
    return 0;
}
