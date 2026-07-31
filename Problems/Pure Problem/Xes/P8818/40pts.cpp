#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
int a[N + 5], b[N + 5];
int amin[N + 5][N + 5], amax[N + 5][N + 5], bmin[N + 5][N + 5], bmax[N + 5][N + 5];
void init(int n, int m) {
    memset(amin, 0x3f, sizeof amin);
    memset(amax, 0xcf, sizeof amax);
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)
            amin[i][j] = min(amin[i][j - 1], a[j]),
            amax[i][j] = max(amax[i][j - 1], a[j]);
    memset(bmin, 0x3f, sizeof bmin);
    memset(bmax, 0xcf, sizeof bmax);
    for (int i = 1; i <= m; i ++)
        for (int j = i; j <= m; j ++)
            bmin[i][j] = min(bmin[i][j - 1], b[j]),
            bmax[i][j] = max(bmax[i][j - 1], b[j]);
}
signed main() {
    bool flg1 = 1;
	int n, m, T;
    cin >> n >> m >> T;
    if (n > N)
    	return puts("Line 26: This Program ONLY Support Subtask 1, 2, 3, 6, 9, 10!"), 42;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], flg1 &= a[i] > 0;
    for (int i = 1; i <= m; i ++)
        cin >> b[i], flg1 &= a[i] > 0;
    init(n, m);
    while (T --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (flg1) 
            cout << amax[l1][r1] * bmin[l2][r2] << endl;
        else if (l1 == r1) 
            if (a[l1] > 0)
                cout << a[l1] * bmin[l2][r2] << endl;
            else if (a[l1] == 0)
                cout << 0 << endl;
            else
                cout << a[l1] * bmax[l2][r2] << endl;
        else if (l2 == r2) 
            if (b[l2] > 0)
                cout << b[l2] * amax[l1][r1] << endl;
            else if (b[l2] == 0)
                cout << 0 << endl;
            else
                cout << b[l2] * amin[l1][r1] << endl; 
        else 
            return puts("Line 52: This Program ONLY Support Subtask 1, 2, 3, 6, 9, 10!"), 42;
    }
    return 0;
}