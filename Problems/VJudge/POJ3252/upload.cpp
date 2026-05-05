#include <iostream>
using namespace std;
#define int long long
const int N = 40;
int c[N + 5][N + 5], bin[N + 5];
inline void init() {
    c[0][0] = 1;
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= i; j ++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
}
inline int query(int n, int m) {
    if (m > n || m < 0 || n > N)
        return 0;
    return c[n + 1][m + 1];
}
inline int turn(int dec) {
    int len = 0;
    for (; dec; dec >>= 1) bin[++ len] = dec & 1;
    return len;
}
inline int work(int x) {
    int len = turn(x);
    int sum = 0;
    for (int i = 1; i < len - 1; i ++)
        for (int j = i / 2 + 1; j <= i; j ++)
            sum += query(i, j);
    int z = 0;
    for (int i = len - 1; i >= 1; i --)
        if (bin[i] == 1)
            for (int j = (len + 1) / 2 - z - 1; j <= i; j ++)
                sum += query(i - 1, j);
        else z ++;
    return sum;
}
inline int solve(int x) {
    return work(x + 1);
}
signed main() {
    init();
	int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1);
    return 0;
}