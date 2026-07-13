#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200000;
struct Node {
    string opt;
    int u, v;
} a[N + 5];
namespace pts25 {
    int dfs(int id) {
        if (a[id].opt == "IN") return a[id].u;
        if (a[id].opt == "NEG") return -dfs(a[id].u);
        if (a[id].opt == "MIN") return min(dfs(a[id].u), dfs(a[id].v));
        if (a[id].opt == "MAX") return max(dfs(a[id].u), dfs(a[id].v));
        if (a[id].opt == "ADD") return dfs(a[id].u) + dfs(a[id].v);
        return 0;
    }
    void solve(int n) {
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].opt >> a[i].u;
            if (a[i].opt != "NEG") cin >> a[i].v;
        }
        for (int i = 1; i <= n; i ++) {
            if (a[i].opt != "IN") continue;
            swap(a[i].u, a[i].v);
            cout << dfs(1) << " ";
            swap(a[i].u, a[i].v);
        }
        cout << endl;
    }
}
namespace pts15 {
    const int N = 200000;
    Node b[N + 5];
    int mmp[N + 5], ans[N + 5];
    int getans(int id) {
        if (a[id].opt == "IN") return a[id].u;
        if (a[id].opt == "NEG") return -getans(a[id].u);
        if (a[id].opt == "ADD") return getans(a[id].u) + getans(a[id].v);
        return 0;
    }
    void delneg(int id, bool neg = 0) {
        if (a[id].opt == "IN") {
            if (neg)
                a[id].u = -a[id].u, a[id].v = -a[id].v;
            return ;
        }
        if (a[id].opt == "NEG") 
            return delneg(a[id].u, !neg);
        if (a[id].opt == "ADD") {
            delneg(a[id].u, neg);
            delneg(a[id].v, neg);
        }
    } 
    int curr;
    void merge(int id) {
        if (a[id].opt == "IN") 
            curr ++, b[curr] = a[id], mmp[curr] = id;
        if (a[id].opt == "NEG") 
            merge(a[id].u);
        if (a[id].opt == "ADD") {
            b[++ curr] = a[id];
            merge(a[id].u);
            merge(a[id].v);
        }
    }
    void solve(int n) {
        for (int i = 1; i <= n; i ++) {
            cin >> a[i].opt >> a[i].u;
            if (a[i].opt != "NEG") cin >> a[i].v;
        }
        delneg(1);
        merge(1);
        int sum = 0;
        for (int i = 1; i <= curr; i ++) 
            if (b[i].opt == "IN")
                sum += b[i].u;
        for (int i = 1; i <= curr; i ++) 
            if (b[i].opt == "IN") 
                ans[mmp[i]] = sum - b[i].u + b[i].v;
        for (int i = 1; i <= n; i ++) 
            if (ans[i]) 
                cout << ans[i] << " ";
        cout << endl;
    }
}
signed main() {
    freopen("signal.in", "r", stdin);
    freopen("signal.out", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        if (n <= 3000)
            pts25::solve(n);
        else pts15::solve(n);
    }
    return 0;
}