#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000;
int a[N + 5][N + 5], h[N + 5], smaxn[N + 5][N + 5];
signed main() {
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= p; i ++)
        cin >> h[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            smaxn[i][j] = max(smaxn[i - 1][j], a[i][j]);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j + p - 1 <= m; j ++) {
            bool invalid = 0;
            for (int k = 0; k < p; k ++)
                if (a[i][j + k] || j + k > m)
                    invalid = 1;
            if (invalid) 
				continue;
            priority_queue<int> q1, q2;
            for (int k = 0; k < p; k ++)
                q1.push(smaxn[i - 1][j + k]),
                q2.push(h[k + 1]);
            while (!q1.empty()) {
                int t1 = q1.top(), t2 = q2.top();
                q1.pop(), q2.pop();
                if (t1 >= t2) 
					invalid = 1;
            }
            if (!invalid) 
				cnt ++;
        }
    cout << cnt;
    return 0;
}
