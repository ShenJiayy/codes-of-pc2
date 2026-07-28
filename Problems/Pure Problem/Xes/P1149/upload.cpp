#include <bits/stdc++.h>
using namespace std;
#define int long long
const int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, N = 8000;
inline int get(int x) {
    if (x == 0) return cnt[0];
    int ans = 0;
    while (x) {
        ans += cnt[x % 10];
        x /= 10;
    }
    return ans;
}
signed main() {
	int n, cnt = 0;
    cin >> n;
    n -= 4;
    for (int a = 0; a < N; a ++)
        for (int b = 0; b < N; b ++)
            if (get(a) + get(b) + get(a + b) == n)
                cnt ++;
    cout << cnt;
    return 0;
}
