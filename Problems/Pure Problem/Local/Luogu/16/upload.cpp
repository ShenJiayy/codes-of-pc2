#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
struct dis {
    int l, r;
} qs[N + 5];
bool cmp(dis x, dis y) {
    if (x.l != y.l)
        return x.l < y.l;
    return x.r > y.r;
}
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) 
        cin >> qs[i].l >> qs[i].r;
    sort(qs + 1, qs + n + 1, cmp);
    vector<dis> ans;
    ans.push_back(qs[1]);
    for (int i = 2; i <= n; i ++)
        if (qs[i].l <= ans.back().r)
            ans.back().r = max(ans.back().r, qs[i].r);
        else
            ans.push_back(qs[i]);
    for (dis d : ans)
        cout << d.l << " " << d.r << endl;
    return 0;
}
