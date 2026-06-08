#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int sl[N + 5], sc[N + 5];
int lowbit(int x) { return x & -x; }
void update(int t[], int p, int d) {
    for (; p <= N; p += lowbit(p))
        t[p] += d;
}
int query(int t[], int p) {
    int ret = 0;
    for (; p; p -= lowbit(p))
        ret += t[p];
    return ret;
}
signed main() {
	int n, T, cnt = 0;
    cin >> n >> T;
    while (T --) {
        int opt, val;
        cin >> opt >> val;
        if (opt == 1) {
            cnt += n;
            // scs
        }
        else {
            cnt -= n;
            // sls
        }
        cout << cnt << endl;
    }
    return 0;
}
