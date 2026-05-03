#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    int curr = 1;
    for (int i = 1; i <= m; i ++)
        if (curr <= n) curr += 2;
        else {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}