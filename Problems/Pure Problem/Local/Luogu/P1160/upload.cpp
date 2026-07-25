#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
list<int>::iterator pos[N + 5];
list<int> ls;
bool vis[N + 5];
signed main() {
	int n;
    cin >> n;
    ls.push_back(1);
    pos[1] = ls.begin();
    for (int i = 2; i <= n; i ++) {
        int k;
        bool p;
        cin >> k >> p;
        auto it = pos[k];
        if (p)
            it ++;
        pos[i] = ls.insert(it, i);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i ++) {
        int x;
        cin >> x;
        if (vis[x]) continue;
        vis[x] = 1;
        ls.erase(pos[x]);
        pos[x] = ls.end();
    }
    for (int val : ls)
        cout << val << " ";
    return 0;
}
