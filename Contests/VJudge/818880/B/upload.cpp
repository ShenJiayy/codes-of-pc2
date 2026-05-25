#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
int a[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int i = n, minn = 9e18, id = 0;
    while (i >= 1) {
        int bi = i;
        while (a[i] == a[bi] && i >= 1) i --;
        if (abs(n - 2 * i) < minn)
            id = i, minn = abs(n - 2 * i);
    }
    cout << a[id + 1];
    return 0;
}
