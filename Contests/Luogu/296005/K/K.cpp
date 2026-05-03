#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 100;
int v[N + 5], t, n, m;

// int T1() {
//     cout << m;
// }

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("1/in.in", "r", stdin);
    #endif
    cin >> t >> n >> m;
    for (int i = 1; i <= t; i ++)
        cin >> v[i];
    /*
    两种情况
    t=1 赚差价
    n=1 一个股票看涨跌
    */
    cout << m;
    return 0;
}