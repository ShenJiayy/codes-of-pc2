#include <bits/stdc++.h>
using namespace std;
#define int __int128
// 消灭所有不具有__int128的单位
const int N = 1e5;
vector<int> g[N + 5];
int rd[N + 5];
int read() {
    int ans = 0;
    string s;
    cin >> s;
    for (char c : s)
        ans = ans * 10 + c - '0';
    return ans;
}
void write(int x) {
    if (x > 9) write(x / 10);
    cout << char(x % 10 + '0');
}
int gcd(int x, int y) { return (y == 0)?x:gcd(y, x % y); }
struct frac {
    int p, q;
    frac() { p = 0, q = 1; }
    frac(int x) { p = x, q = 1; }
    frac(int x, int y) { p = x, q = y; }
    void operator = (int x) { p = x, q = 1; }
    void operator = (frac x) { p = x.p, q = x.q; }
    void exec() {
        int g = gcd(p, q);
        p /= g, q /= g;
    }
    void exec(int x) {
        int l = q / gcd(q, x) * x;
        p *= l / q, q *= l / q;
    }
} ans[N + 5];
bool operator == (frac x, frac y) {
    x.exec(), y.exec();
    return x.p == y.p && x.q == y.q;
}
frac operator +(frac x, frac y) {
    x.exec(y.q), y.exec(x.q);
    frac ret = {x.p + y.p, x.q};
    ret.exec();
    return ret;
}
frac operator *(frac x, frac y) {
    frac ret = {x.p * y.p, x.q * y.q};
    ret.exec();
    return ret;
}
vector<int> topsort(int n) {
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i ++)
        if (rd[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        ans.push_back(t);
        for (int nxt : g[t]) {
            rd[nxt] --;
            if (rd[nxt] == 0)
                q.push(nxt);
        }
    }
    return ans;
}
signed main() {
	int n = read();
    int m = read();
    for (int u = 1; u <= n; u ++) {
        int k = read();
        while (k --) {
            int v = read();
            g[u].push_back(v);
            rd[v] ++;
        }
    }
    auto tp = topsort(n);
    for (int i = 1; i <= m; i ++) 
        ans[i] = 1;
    for (int i : tp) {
        bool valid = 0;
        frac foreach(1, g[i].size());
        for (int nxt : g[i]) {
            ans[nxt] = ans[nxt] + foreach * ans[i];
            valid = 1;
        }
        if (valid)
            ans[i] = 0;
    }
    for (int i = 1; i <= n; i ++) {
        ans[i].exec();
        if (ans[i] == frac(0, 1)) continue;
        write(ans[i].p);
        cout << " ";
        write(ans[i].q);
        cout << endl;
    }
    return 0;
}
