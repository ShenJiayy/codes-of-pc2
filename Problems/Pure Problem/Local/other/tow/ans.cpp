#include <iostream>
#include <cstring>
using namespace std;
long long f[41][41], n;

int main() {
    cin >> n;
    long long tot = 1;
    for (int i = 0; i < n - 1; i ++) tot *= 2;
    cout << tot << endl;
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++) {
            for (int k = 1; k < j; k ++) f[i][j] += f[i - k][j];
            for (int k = 0; k <= j; k ++) f[i][j] += f[i - j][k];
        }
    for (int i = 1; i <= n; i ++) cout << f[n][i] << " ";
}