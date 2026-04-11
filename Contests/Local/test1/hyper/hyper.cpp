#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4;
string ans[N + 5];
int numcnt[N + 5], fact[8];
void dfs(int x) {
    if (!ans[x].empty()) return ;
    for (int i = 3; i <= 7; i ++) {
        if (x == fact[i] && numcnt[i] < numcnt[x])
            numcnt[x] = numcnt[i], ans[x] = ans[i] + '!';
    }
    if (numcnt[x] == 1) return ;
    for (int i = 1; i < x; i ++) {
        int a = i, b = x - i;
        if (ans[a].empty())
            dfs(a);
        if (ans[b].empty())
            dfs(b);
        if (numcnt[a] + numcnt[b] < numcnt[x]) {
            ans[x] = '(' + ans[a] + '+' + ans[b] + ')';
            numcnt[x] = numcnt[a] + numcnt[b];
        }
    }
    for (int i = 1; i * i <= x; i ++) {
        if (x % i) continue ;
        int a = i, b = x / i;
        if (ans[a].empty())
            dfs(a);
        if (ans[b].empty())
            dfs(b);
        if (numcnt[a] + numcnt[b] < numcnt[x]) {
            ans[x] = '(' + ans[a] + '*' + ans[b] + ')';
            numcnt[x] = numcnt[a] + numcnt[b];
        }
    }
    for (int a = 2; a <= x; a ++) 
        for (int b = 1; pow(a, b) <= x; b ++) {
            if (pow(a, b) != x)
                continue;
            if (ans[a].empty())
                dfs(a);
            if (ans[b].empty())
                dfs(b);
            if (numcnt[a] + numcnt[b] < numcnt[x]) {
                ans[x] = '(' + ans[a] + '^' + ans[b] + ')';
                numcnt[x] = numcnt[a] + numcnt[b];
            }
        }
}
signed main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    ans[1] = "1"; ans[2] = "2"; ans[3] = "3";
    ans[4] = "(1+3)"; ans[5] = "5"; ans[6] = "3!";
    ans[7] = "7";
    fact[1] = 1;
    for (int i = 2; i <= 7; i ++) 
        fact[i] = fact[i - 1] * i;
    memset(numcnt, 0x1f, sizeof numcnt);
    numcnt[1] = numcnt[2] = numcnt[3] = numcnt[5] = 1;
    numcnt[6] = numcnt[7] = 1;
    numcnt[4] = 2;
    int n;
    cin >> n;
    dfs(n);
    cout << ans[n];
    return 0;
}