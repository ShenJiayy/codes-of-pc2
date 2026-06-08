#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1000;
double dp[N + 5][N + 5];
bool used[N + 5][N + 5];
double solve(int a, int b) {
    if (a <= 0) return 0;
    if (b < 0) return 0;
    if (used[a][b]) return dp[a][b];
    used[a][b] = 1;
    double ans = a * 1.0 / (a + b);
    if (b >= 2) {
        double p = b * 1.0 / (a + b) * (b - 1) * 1.0 / (a + b - 1);
        if (a + b - 2 > 0) {
            if (a >= 1)
                ans += p * a * 1.0 / (a + b - 2) * solve(a - 1, b - 2);
            if (b >= 3)
                ans += p * (b - 2) * 1.0 / (a + b - 2) * solve(a, b - 3);
        }
    }
    dp[a][b] = ans;
    return ans;
}
signed main() {
	int a, b;
    cin >> a >> b;
    printf("%.10lf", solve(a, b));
    return 0;
}
