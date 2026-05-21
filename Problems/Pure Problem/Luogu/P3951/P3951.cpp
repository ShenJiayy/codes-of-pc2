#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e8;
bool vis[N + 5];

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int a, b;
    cin >> a >> b;
    // ab - a - b
    cout << a * b - a - b;
    return 0;
}