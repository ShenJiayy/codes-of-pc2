#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int a[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1, ans = 0;
    for (int i = 1; i <= n; i ++) {
        while (j <= n && a[j] <= a[i])
            j ++;
        if (j > n) 
            break;
        ans ++;
        j ++;
    }
    cout << n - ans;
    return 0;
}
