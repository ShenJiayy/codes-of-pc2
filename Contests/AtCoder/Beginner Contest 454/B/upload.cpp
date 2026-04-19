#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 100;
int a[N + 5], mp[N + 5];
const string out[2] = {"No\n", "Yes\n"};
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        mp[a[i]] ++;
    bool ans1 = 1, ans2 = 1;
    for (int i = 1; i <= m; i ++){
        if (mp[i] > 1)
            ans1 = 0;
        if (mp[i] < 1)
            ans2 = 0;
    }
    cout << out[ans1] << out[ans2];
    return 0;
}