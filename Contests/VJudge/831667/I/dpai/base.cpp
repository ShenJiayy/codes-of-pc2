#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
int a[N + 5];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int T = n;
    while (T --) {
        int l, r;
        cin >> l >> r;
        map<int, int> mp;
        for (int i = l; i <= r; i ++)
            mp[a[i]] ++;
        int ans = 9e18, cnt = 0;
        for (auto kv : mp)
            if (kv.second > cnt || kv.second == cnt && kv.first < ans)
                ans = kv.first, cnt = kv.second;
        cout << ans << endl;
    }
    return 0;
}

// Windows: %random%
// Linux: head -20 /dev/random | cksum | cut -c 1-10