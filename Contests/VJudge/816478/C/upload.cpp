#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
bool isp[N + 5];
vector<int> P;
signed main() {
	int l, r;
    cin >> l >> r;
    // 1. 预处理 1~10^6 的质数
    memset(isp, 1, sizeof isp);
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= N; i ++)
        if (isp[i])
            for (int j = i + i; j <= N; j += i)
                isp[j] = 0;
    for (int i = 1; i <= N; i ++)
        if (isp[i])
            P.push_back(i);
    // 2. 用他们筛 l~r
    memset(isp, 1, sizeof isp);
    if (l <= 2) l = 2;
    for (int v : P) 
        for (int j = max(2 * v, (l + v - 1) / v * v); j <= r; j += v)
            isp[j - l] = 0;
    int cnt = 0;
    for (int i = 0; i <= r - l; i ++) cnt += isp[i];
    cout << cnt;
    return 0;
}