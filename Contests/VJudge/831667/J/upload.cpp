#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4, lgN = 16;
int a[N + 5], maxn[N + 5][lgN + 5], minn[N + 5][lgN + 5];
int qmax(int l, int r) {
    int len = log2(r - l + 1);
    return max(maxn[l][len], maxn[r - (1 << len) + 1][len]);
}
int qmin(int l, int r) {
    int len = log2(r - l + 1);
    return min(minn[l][len], minn[r - (1 << len) + 1][len]);
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("C:\\Users\\DELL\\Downloads\\P2880_1.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
	int n, T;
    cin >> n >> T;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        maxn[i][0] = minn[i][0] = a[i];
    for (int len = 1; (1 << len) <= n; len ++)
        for (int l = 1, r = 1 << len; r <= n; l ++, r ++)
            maxn[l][len] = max(maxn[l][len - 1], maxn[l + (1 << len - 1)][len - 1]),
            minn[l][len] = min(minn[l][len - 1], minn[l + (1 << len - 1)][len - 1]);
    while (T --) {
        int l, r;
        cin >> l >> r;
        cout << qmax(l, r) - qmin(l, r) << endl;
    }
    #ifndef ONLINE_JUDGE
		fclose(stdout);
		system("fc C:\\Users\\DELL\\Downloads\\P2880_1.out data.out > diff.log");
		system("start diff.log");
	#endif
    return 0;
}
