#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int a[N + 5], d[N + 5], b[N + 5], mp[N + 5], siz;
vector<int> upd[N + 5];
signed main() {
	int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i] >> d[i] >> b[i];
    for (int i = 1; i <= n; i ++)
        upd[d[i]].push_back(i), mp[a[i]] ++;
    for (int i = 1; i <= n; i ++)
        siz += bool(mp[i]);
    for (int i = 1; i <= m; i ++) {
        for (int key : upd[i]) {
            if (a[key] == b[key]) continue;
            mp[a[key]] --, mp[b[key]] ++;
            if (mp[a[key]] == 0) siz --;
            if (mp[b[key]] == 1) siz ++;
        }
        cout << siz << endl;
    }
    return 0;
}
