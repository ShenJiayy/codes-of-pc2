#include <bits/stdc++.h>
using namespace std;
#define local
int state[128];
signed main() {
    #ifdef local
        freopen("in.in", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        char x;
        cin >> x;
        state[x] = 1;
    }
    for (int i = 1; i <= m; i ++) {
        char x;
        cin >> x;
        if (state[x] == 1)
            state[x] = 0;
        else
            state[x] = 2;
    }
    int q;
    cin >> q;
    while (q --) {
        string x;
        cin >> x;
        int typ = 0;
        for (char c : x)
            if (state[c])
                typ = state[c];
        if (typ == 1)
            cout << "Takahashi\n";
        else if (typ == 2)
            cout << "Aoki\n";
        else
            cout << "Unknown\n";
    }
    return 0;
}