#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 2e9;
    cin >> n;
    for (int i = 0; i <= n / 5; i ++) {
        if ((n - i * 5) % 3) continue;
        int j = (n - i * 5) / 3;
        ans = min(ans, i + j);
    }
    if (ans != 2e9)
    	cout << ans;
    else cout << -1;
    return 0;
}
