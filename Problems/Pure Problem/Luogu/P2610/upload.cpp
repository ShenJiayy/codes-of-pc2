#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
vector<int> gt[N + 5], g[N + 5];
int dis[N + 5];
bool vis[N + 5];
void dfs(int id, int ft) {
    if (vis[id]) return ;
    vis[id] = 1;
    dis[id] = dis[ft] + 1;
    for (int nxt : g[id])
        dfs(nxt, id);
}
signed main() {
    // 蒟蒻考虑建图
    map<pair<int, int>, vector<int>> mp;
	int n;
    cin >> n;
    for (int i = 1; i <= n - 2; i ++) {
        int p, q, r;
        cin >> p >> q >> r;
        // p -> q
        for (int vals : mp[{p, q}])
            gt[i].push_back(vals);
        mp[{p, q}].push_back(i);
        // q -> p
        for (int vals : mp[{q, p}])
            gt[i].push_back(vals);
        mp[{q, p}].push_back(i);
        // p -> r
        for (int vals : mp[{p, r}])
            gt[i].push_back(vals);
        mp[{p, r}].push_back(i);
        // r -> p
        for (int vals : mp[{r, p}])
            gt[i].push_back(vals);
        mp[{r, p}].push_back(i);
        // q -> r
        for (int vals : mp[{q, r}])
            gt[i].push_back(vals);
        mp[{q, r}].push_back(i);
        // r -> q
        for (int vals : mp[{r, q}])
            gt[i].push_back(vals);
        mp[{r, q}].push_back(i);
    }
    for (int i = 1; i <= n - 2; i ++) {
        map<int, bool> mp2;
        for (int nxt : gt[i])
            if (mp2[nxt] == 0) {
                mp2[nxt] = 1;
                g[i].push_back(nxt);
                g[nxt].push_back(i);
            }
    }
    // 考虑换根 DP
    for (int rt = 1; rt <= n - 2; rt ++) 
        dfs(rt, 0);
    int maxn = 0, maxid = 0;
    for (int i = 1; i <= n - 2; i ++)
        if (dis[i] > maxn)
            maxn = dis[i], maxid = i;
    memset(vis, 0, sizeof vis);
    dfs(maxid, 0);
    maxn = 0;
    for (int i = 1; i <= n - 2; i ++)
        maxn = max(maxn, dis[i]);
    cout << maxn;
    return 0;
}
