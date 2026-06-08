#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
struct Gem {
    int val, col;
} a[N + 5];
bool cmp(Gem x, Gem y) {
    return x.val > y.val;
}
vector<int> gems[N + 5];
signed main() {
	int n, m, k;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].col >> a[i].val;
    for (int i = 1; i <= n; i ++)
        gems[a[i].col].push_back(a[i].val);
    for (int i = 1; i <= n; i ++)
        sort(gems[i].begin(), gems[i].end());
    vector<Gem> tmp;
    for (int i = 1; i <= n; i ++) 
        if (!gems[i].empty())
            tmp.push_back({gems[i].back(), i});
    sort(tmp.begin(), tmp.end(), cmp);
    int ans = 0;
    for (int i = 0; i < m; i ++)
        ans += tmp[i].val, gems[tmp[i].col].pop_back();
    // 其余的恢复，然后排序
    tmp.clear();
    for (int c = 1; c <= n; c ++)
        for (int v : gems[c])
            tmp.push_back({v, c});
    sort(tmp.begin(), tmp.end(), cmp);
    for (int i = 0; i < k - m; i ++)
        ans += tmp[i].val;
    cout << ans;
    return 0;
}
