#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) 
        return {a, {1, 0}};
    auto res = exgcd(b, a % b);
    int x1 = res.second.first, y1 = res.second.second, g = res.first;
    int x = y1, y = x1 - a / b * y1;
    return {g, {x, y}};
}
signed main() {
	int a, b;
    cin >> a >> b;
    auto ret = exgcd(a, b);
    int ans = ret.second.first;
    ans %= b, ans += b, ans %= b;
    cout << ans;
    return 0;
}
