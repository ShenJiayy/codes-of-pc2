#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i ++)
        cout << '#';
    cout << endl;
    for (int i = 2; i < n; i ++) {
        cout << '#';
        for (int j = 2; j < m; j ++)
            cout << ".";
        cout << '#' << endl;
    }
    for (int i = 1; i <= m; i ++)
        cout << '#';
    cout << endl;
    return 0;
}