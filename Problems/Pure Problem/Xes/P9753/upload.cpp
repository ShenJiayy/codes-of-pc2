#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6;
char c[N + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    if (n > 8000)
        return puts("This Program ONLY Supports Subtask 1-3!"), 42;
    int ans = 0;
    for (int l = 1; l <= n; l ++) {
        stack<char> stk;
        for (int r = l; r <= n; r ++) {
            if (!stk.empty() && stk.top() == c[r])
                stk.pop();
            else stk.push(c[r]);
            ans += stk.empty(); 
        }
    }
    cout << ans;
    return 0;
}
