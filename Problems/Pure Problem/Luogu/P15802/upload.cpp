#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9;
int fp(int a, int b, int p) {
    int ret = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1)
            ret = ret * a % p;
    return ret;
}
signed main() {
	int T;
    cin >> T;
    while (T --) {
        int x;
        cin >> x;
        // 多拆3，少拆2，不拆1
        if (x <= 2) 
            cout << x;
        else if (x % 3 == 0) 
            cout << fp(3, x / 3, mod);
        else if (x % 3 == 1) {
            x -= 4;
            cout << fp(3, x / 3, mod) * 4 % mod;
        }
        else {
            x -= 2;
            cout << fp(3, x / 3, mod) * 2 % mod;
        }
        cout << endl;
    }
    return 0;
}