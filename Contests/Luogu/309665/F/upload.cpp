#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
unordered_map<int, int> f;
int a1[N + 5], a2[N + 5];
void init(int n) {
    if (f.count(n) == 0)
        f[n] = n;
}
int find(int id) {
    if (f[id] != id)
        f[id] = find(f[id]);
    return f[id];
}
void merge(int x, int y) {
    int ftx = find(x), fty = find(y);
    if (ftx != fty)
        f[ftx] = fty;
}
signed main() {
    int T;
    cin >> T;
    while (T --) {
        int n, curr = 0;
        cin >> n;
        f.clear();
        memset(a1, 0, sizeof a1);
        memset(a2, 0, sizeof a2);
        for (int i = 1; i <= n; i ++) {
            int x, y;
            bool e;
            cin >> x >> y >> e;
            init(x), init(y);
            if (e == 1)
                merge(x, y);
            else
                curr ++, a1[curr] = x, a2[curr] = y;
        }
        bool ans = 0;
        for (int i = 1; i <= curr; i ++)
            ans |= find(a1[curr]) == find(a2[curr]);
        if (ans)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}