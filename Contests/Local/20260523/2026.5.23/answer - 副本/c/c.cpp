#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
signed main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    /*
    对于 Subtask 3
    Ans = (A_1 + ... + A_n) / 3.  
    对于Subtask 4
    当 n % 3 == 0 或 1 时
    ans = 2 * (n / 3).
    当 n % 3 == 2 时
    ans = 2 * (n / 3) + 1.
    对于 Subtask 5
    // 对于 3 | A_i 的，见 Subtask 3.
    // 接下来讨论 A_i mod 3 ≠ 0 的
    // 把所有的 (2, 2) 改成 (0, 1)
    // 将所有 (1, 2) 组合
    // 余下的玩意 就啥用没有了
    狗都不要的贪心，wtm被hk了
    // 狗都不要的dp，wtm没法做
    dp[i]表示 1~i 
    对于 Subtask 6
    对于所有 A_i，将他们对 3 取模
    得到的玩意，商给 Subtask 3，余数给 Subtask 5.
    */
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += a[i] / 3, a[i] %= 3;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        if (a[i] == 2 && a[i + 1] == 2 && a[i + 2] == 2)
            sum += 2, a[i] = a[i + 1] = a[i + 2] = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        if (a[i] == a[i + 1] && a[i + 1] == 2)
            sum ++, a[i] = 0, a[i + 1] = 1;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        if (a[i] == 1 && a[i + 1] == 2)
            sum ++, a[i] = a[i + 1] = 0;
    cout << sum;
    return 0;
}
