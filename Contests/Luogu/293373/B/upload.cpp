#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 9, mod = 998244353;
char c[N + 5];
int nxt[N + 5], n, k, p;
stack<char> t;
string s;
int gailv = 1, sum;
void dfs(int stp, int id) {
    if (stp > 2 * k) {
        bool valid = 1;
        for (int i = 0; i < k; i ++)
            if (s[i] != s[k + i])
                valid = 0;
        if (!valid) return ;
        sum += gailv;
        sum %= mod;
        return ;
    }
    t.push(id);
    string baks = s;
    s = s + c[id];
    int baklv = gailv;
    gailv = baklv * p % mod;
    dfs(stp + 1, nxt[id]);
    if (t.size() > 1) {
        gailv = baklv * (1 - p) % mod;
        stack<char> bakt = t;
        t.pop();
        dfs(stp + 1, t.top());
        t = bakt;
    }
    s = baks;
    t.pop();
}
signed main() {
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    for (int i = 1; i <= n; i ++)
        cin >> nxt[i];
    for (int i = 1; i <= n; i ++)
        dfs(1, i);
    cout << sum * n % mod;
    return 0;
}