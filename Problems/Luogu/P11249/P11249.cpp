#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5;
bool hs[N + 5];
vector<int> v[N + 5];
int dep[N + 5];

void dfs(int id, int ft) {
    dep[id] = dep[ft] + hs[id];
    for (int next : v[id])
        if (next != ft) 
            dfs(next, id);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> hs[i];
    for (int i = 1; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += hs[i];
    memset(dep, 0, sizeof dep);
    dfs(1, 0);
    int mxv = -1, mxid;
    for (int i = 1; i <= n; i ++)
        if (mxv < dep[i])
            mxv = dep[i], mxid = i;
    memset(dep, 0, sizeof dep);
    dfs(mxid, 0);
    if (*max_element(dep + 1, dep + n + 1) == sum)
        cout << "Yes";
    else   
        cout << "No";
    cout << endl;
    for (int i = 1; i <= n; i ++)
        v[i].clear();
}

int main() {
    int T;
    cin >> T;
    while (T --)
        solve();
    return 0;
}
