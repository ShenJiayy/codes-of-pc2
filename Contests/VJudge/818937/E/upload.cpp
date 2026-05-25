#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int, pair<int, int>> exgcd(int a, int b) {
    if (b == 0) return {a, {1, 0}};
    auto gr = exgcd(b, a % b);
    int g = gr.first, x = gr.second.first, y = gr.second.second;
    return {g, {y, x - a / b * y}};
} 
int excrt(int n, int a[], int b[]) {
    int x = a[1], y = b[1];
    for (int i = 2; i <= n; i ++) {
        auto res = exgcd(x, a[i]);
        int g = res.first;
        if ((b[i] - y) % g) return -1;
        int x1 = res.second.first, x2 = res.second.second;
        x1 = x1 * (b[i] - y) / g;
        x1 %= a[i] / g, x1 += a[i] / g, x1 %= a[i] / g;
        y = x * x1 + y;
        x = x * a[i] / g;
    }
    y %= x, y += x, y %= x;
    return y;
}
int a[20], b[20];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    cout << excrt(n, b, a);
    return 0;
}