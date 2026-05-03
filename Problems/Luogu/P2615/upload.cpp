#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 45;
int table[N + 5][N + 5];
signed main() {
    int n;
    cin >> n;
    int l, c;
    for (int i = 1; i <= n * n; i ++) {
        if (i == 1)
            l = 1, c = (n + 1) / 2;
        else if (l == 1 && c != n) 
            l = n, c ++;
        else if (c == n && l != 1)
            c = 1, l --;
        else if (l == 1 && c == n)
            l ++;
        else {
            if (!table[l - 1][c + 1])
                l --, c ++;
            else
                l ++;
        }
        table[l][c] = i;
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++)
            cout << table[i][j] << " ";
        cout << endl;
    }
    return 0;
}
