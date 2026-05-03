#include <bits/stdc++.h>
using namespace std;
#define int long long
#define local

signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s)
        if (c == 'i' || c == 'j')
            cnt ++;
    cout << cnt;
    return 0;
}