#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int stk[N + 5], top;
inline bool checkup() {
    if (top < 4) return 0;
    return stk[top] == stk[top - 1] && stk[top] == stk[top - 2] && stk[top] == stk[top - 3];
}
signed main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> stk[++ top];
        if (checkup())
            top -= 4, ans ++;
    }
    cout << n - 4 * ans;
    return 0;
}
