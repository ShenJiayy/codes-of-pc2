#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353377, N = 100;
int a[N + 5];
int read() {
    bool t = 0;
    int inp = 0;
    while (1) {
        char c = getchar();
        if (isdigit(c)) {
            inp = c - '0';
            break;
        }
        if (c == '-') t = 1;
    }
    while (1) {
        char c = getchar(); 
        if (!isdigit(c)) 
            return inp * pow(-1, t);
        inp = (inp * 10 + c - '0') % mod;
    }
}
signed main() {
	int n = read(), m = read();
    for (int i = 0; i <= n; i ++)
        a[i] = read();
    vector<int> ans;
    for (int x = 1; x <= m; x ++) {
        int res = 0;
        for (int i = n; i >= 0; i --)
            res = (res * x % mod + a[i]) % mod;
        if (res == 0) ans.push_back(x); 
        // cout << res << endl;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << endl;
    return 0;
}
