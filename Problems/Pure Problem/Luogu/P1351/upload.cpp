#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, mod = 1e4 + 7;
vector<int> g[N + 5];
int w[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    int maxn = 0, sum = 0;
    for (int i = 1; i <= n; i ++) {
        int sqa = 0, asq = 0, max1 = 0, max2 = 0;
        for (int nxt : g[i]) {
            if (max1 < w[nxt])
                max2 = max1, max1 = w[nxt];
            else if (max2 < w[nxt])
                max2 = w[nxt];
            sqa += pow(w[nxt], 2), sqa %= mod;
            asq += w[nxt], asq %= mod;
        }
        asq = asq * asq % mod;
        maxn = max(maxn, max1 * max2);
        sum = (sum + asq - sqa + mod) % mod;
    }
    cout << maxn << " " << sum;
    return 0;
}