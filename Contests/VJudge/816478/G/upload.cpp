#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 30000;
bool isp[N + 5];
vector<int> P;
unordered_map<int, int> m1p; 
int solve(int s) {
    // 5. 处理
    int ans = 0;
    for (auto kv : m1p) {
        int cnt = 0;
        if (s % kv.first) 
            return 9e18;
        while (s % kv.first == 0)
            cnt ++, s /= kv.first;
        ans = max(ans, (cnt + kv.second - 1) / cnt);
        // s里面kv的数量 * k >= p里面的 
        // cnt * k >= kv.second
        // k >= kv.second / cnt
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int T, m1, m2;
    /*
    题目要求最小的正整数k使得有一个i（1~n），满足m1^m2|s^k。
    （cp题解一句话）
    对于每个s
    分解s 分解m1
    显然，m2只有个一次性用途
    然后，遍历那个map
    m1有的s没有，这个s当fw丢掉
    s多了就丢掉
    然后取呗，向上取整取max
    */
    // 1. 初始化 P
    memset(isp, 1, sizeof isp);
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= N; i ++)
        if (isp[i])
            for (int j = i + i; j <= N; j += i)
                isp[j] = 0;
    for (int i = 2; i <= N; i ++)
        if (isp[i])
            P.emplace_back(i);
    // 2. 分解 m1
    cin >> T >> m1 >> m2;
    if (m1 == 1) {
        cout << 0;
        return 0;
    }
    int t = m1;
    for (int v : P)
        while (t % v == 0)
            m1p[v] += m2, t /= v;
    // 3. 初始化答案 & 读入
    int ans = 9e18;
    while (T --) {
        int s;
        cin >> s;
        ans = min(ans, solve(s));
    }
    if (ans == 9e18) cout << -1;
    else cout << ans;
    return 0;
}
