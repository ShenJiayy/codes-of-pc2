#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4;
double f[N + 5], g[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = n - 1; i >= 0; i --)
        f[i] = f[i + 1] + n * 1.0 / (n - i);
    for (int i = n - 1; i >= 0; i --)
        g[i] = i * 1.0 / (n - i) * f[i] + g[i + 1] + f[i + 1] + n * 1.0 / (n - i);
    printf("%.2lf", g[0]);
    return 0;
}
