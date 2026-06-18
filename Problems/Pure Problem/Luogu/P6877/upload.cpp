#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], b[N + 5], ba[N + 5];
signed main() {
	int n;
    cin >> n;
    int m = n + 1;
    for (int i = 1; i <= m; i ++)
        cin >> ba[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    for (int k = 1; k <= m; k ++) {
        for (int i = 1, curr = 0; i <= m; i ++)
            if (i != k)
                a[++ curr] = ba[i];
        sort(a + 1, a + n + 1);
        int maxn = 0;
        for (int i = 1; i <= n; i ++)
            maxn = max(maxn, max(0ll, a[i] - b[i]));
        cout << maxn << " ";
    }
    
    return 0;
}