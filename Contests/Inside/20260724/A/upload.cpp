#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char ans[N + 5];
int main() {
    int n, k, s = 0;
    cin >> n >> k;
    memset(ans, 0xff, sizeof ans);
    for (int i = 1; i <= k; i ++) {
        int x;
        char c;
        cin >> x >> c;
        x %= n;
        s += x;
        s %= n;
        if (ans[s] != c && ans[s] != -1)
            return puts("!"), 0;
        ans[s] = c;
    }
    ans[n] = ans[0];
    for (int i = s; i; i --)
        if (ans[i] != -1)
            cout << ans[i];
        else cout << '?';
    for (int i = n; i > s; i --)
        if (ans[i] != -1)
            cout << ans[i];
        else cout << '?';
    return 0;
}