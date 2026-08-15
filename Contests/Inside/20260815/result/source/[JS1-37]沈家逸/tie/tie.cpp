/*
for (int i = 1; i <= n; i ++)
    for (int i = 1; i <= n; i ++)
        for (int i = 1; i <= n; i ++)
            for (int i = 1; i <= n; i ++)
                for (int i = 1; i <= n; i ++)
                    for (int i = 1; i <= n; i ++)
                        for (int i = 1; i <= n; i ++)
                            for (int i = 1; i <= n; i ++)
                                for (int i = 1; i <= n; i ++)
                                    for (int i = 1; i <= n; i ++)
                                        for (int i = 1; i <= n; i ++) {
                                            n ++;
                                            puts("> Code is cheap,");
                                            puts("> Show me the talk,");
                                            puts("> Talk is expensive.");
                                            puts("");
                                            puts("God! Let my code AC!");
                                        }
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int b[N + 5];
struct Tie {
    int id, w;
} a[N + 5];
bool cmp(Tie x, Tie y) {
    return x.w < y.w;
}
int df[N + 5], ds[N + 5]; 
int mf[N + 5], ms[N + 5];
// df：第一匹配
// ds：第二匹配
int ans[N + 5];
signed main() {
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	int n;
    cin >> n;
    for (int i = 1; i <= n + 1; i ++)
        cin >> a[i].w, a[i].id = i;
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    sort(a + 1, a + n + 2, cmp);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i ++) {
        // 与i匹配的就是a[i]或者a[i + 1]
        df[i] = max(a[i].w - b[i], 0ll);
        ds[i] = max(a[i + 1].w - b[i], 0ll);
    }
    for (int i = 1; i <= n; i ++)
        mf[i] = max(mf[i - 1], df[i]);
    for (int i = n; i >= 1; i --)
        ms[i] = max(ms[i + 1], ds[i]);
    for (int i = 1; i <= n + 1; i ++) 
        ans[a[i].id] = max(mf[i - 1], ms[i]);
    for (int i = 1; i <= n + 1; i ++)
        cout << ans[i] << " ";
	return 0;
}
