#include <iostream>
using namespace std;
#define int long long
int getc(int n, int m) {
    double res = 1;
    while (m > 0)
        res *= 1.0 * n / m, n --, m --;
    return res + 0.5;
}
int solve(int n, int m) {
    return getc(n + m, min(n, m));
}
signed main() {
	while (1) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        cout << solve(n, m) << endl;
    }
    return 0;
}