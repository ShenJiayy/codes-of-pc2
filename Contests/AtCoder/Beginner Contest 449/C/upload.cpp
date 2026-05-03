#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
char s[N + 5];
vector<int> show[128];
signed main() {
    int n, l, r, cnt = 0;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i ++) {
        cin >> s[i];
        show[s[i]].push_back(i);
    }
    for (int i = 1; i <= n; i ++) {
        // for (int j = i + l; j <= min(i + r, n); j ++)
            // if (s[i] == s[j])
                // cnt ++;
        int st = lower_bound(show[s[i]].begin(), show[s[i]].end(), i + l) - show[s[i]].begin(), ed = upper_bound(show[s[i]].begin(), show[s[i]].end(), i + r) - show[s[i]].begin();
        cnt += ed - st;
    }
    cout << cnt;
    return 0;
}