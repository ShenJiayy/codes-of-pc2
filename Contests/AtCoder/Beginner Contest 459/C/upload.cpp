#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e5;
int s[N + 5], a[N + 5];
int lowbit(int x) { return x & -x; }
void upd(int p, int d) {
    for (; p <= N; p += lowbit(p)) 
        s[p] += d;
}
void update(int p, int d) {
	upd(p + 1, d);
}
int qry(int p) {
    int ret = 0;
    for (; p; p -= lowbit(p)) 
        ret += s[p]; 
    return ret; 
}
int query(int p) {
	return qry(p + 1);
}
signed main() {
	int n, T, gt = 0;
    cin >> n >> T;
    update(0, n);
	s[0] = n;
    while (T --) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1) {
            update(a[x], -1);
            a[x] ++;
            update(a[x], 1);
            if (query(gt) == 0) gt ++;
        }
        else {
			int ans = query(N) - query(x - 1 + gt);
			cout << ans << endl;
		}
    }
    return 0;
}
