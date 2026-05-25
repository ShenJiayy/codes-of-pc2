#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
	int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        cnt += a[i] / 3;
        a[i] %= 3;
        if (a[i] > 0) {
            int lst = 3 - a[i];
            if (i + 1 <= n && a[i + 1] >= lst)
                a[i + 1] -= lst, cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
