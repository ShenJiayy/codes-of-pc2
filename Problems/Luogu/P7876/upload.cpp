#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debugBCG
#define debugMerge
const int N = 100;
int f[N + 5], rnk[N + 5], rt[N + 5], s[N + 5][N + 5];
bool vis[N + 5], a[N + 5][N + 5];
vector<int> g[N + 5];
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
#ifdef debugBCG
int bcgccc;
#endif
#ifdef debugMerge
int mgrccc, mgrmnt;
#endif
signed main() {
	int cas, T;
    cin >> cas >> T;
    while (T --) {
        memset(vis, 0, sizeof vis);
        memset(rnk, 0, sizeof rnk);
        int cnt = 0;
        for (int i = 1; i <= N; i ++)
            g[i].clear();
        for (int i = 1; i <= N; i ++)
            f[i] = i;
        bool hasans = 1;
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                cin >> a[i][j];
        for (int k = 1; k <= n; k ++)
            for (int i = 1; i <= n; i ++)
                for (int j = 1; j <= n; j ++)
                    if (i != j && j != k && k != i)
                        if (!a[i][k] && !a[k][j] && a[i][j])
                            hasans = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++)
                if (i != j && !a[i][j]) {
                        #ifdef debugMerge
                            mgrmnt ++;
                        #endif
                        merge(i, j);
                    }
        #ifdef debugMerge
            mgrccc ++;
            string nmemgr = "debug/mgr/";
            nmemgr += to_string(mgrccc);
            nmemgr += ".txt";
            freopen(nmemgr.data(), "w", stderr);
            cerr << mgrmnt;
            mgrmnt = 0;
            fclose(stderr);
        #endif
        for (int i = 1; i <= n; i ++)
            g[find(i)].push_back(i);
        for (int blk = 1; blk <= n; blk ++)
            if (!g[blk].empty()) {
                cnt ++;
                memset(vis, 0, sizeof vis);
                for (int i : g[blk])
                    for (int j : g[blk])
                        if (i != j)
                            if (!a[i][j])
                                rnk[i] ++;
                for (int i : g[blk]) {
                    if (vis[rnk[i]]) hasans = 0;
                    vis[rnk[i]] = 1;
                    if (rnk[i] == 0) rt[blk] = i;
                }
            }
        if (!hasans || (m == 1 && cnt != 1)){
            cout << "NO\n";
            continue;
        }
        #ifdef debugBCG
            bcgccc ++;
            string nmebcg = "debug/bcg/";
            nmebcg += to_string(bcgccc);
            nmebcg += ".csv";
            freopen(nmebcg.data(), "w", stderr);
            for (int i = 1; i <= n; i ++)
                cerr << f[i] << ",";
            fclose(stderr);
        #endif
        int sum = 0;
        for (int i = 1; i <= n; i ++)
            if (!g[i].empty()) {
                s[rt[i]][1] = sum + g[i].size();
                s[rt[i]][2] = 100 - sum;
                for (int j = 3; j <= m; j ++)
                    s[rt[i]][j] = 100;
                for (int j : g[i])
                    for (int k = 1; k <= m; k ++)
                        s[j][k] = s[rt[i]][k] - rnk[j];
                sum += g[i].size();
            }
        cout << "YES\n";
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++)
                cout << s[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}