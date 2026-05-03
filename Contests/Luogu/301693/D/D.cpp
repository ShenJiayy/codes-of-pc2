#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1.5e5;
struct Interval {
    int s, t;
    int getcnt() {
        return t - s + 1;
    }
} a[N + 5];
bool cmp(Interval x, Interval y) {
    return x.t < y.t;
}
int dp[N + 5];

int find(int l, int r, int key) {
    // 函数作用：二分查找比key最小的数中最大的数
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid].t >= key)
            r = mid - 1;
        else 
            ans = mid, l = mid + 1;
    }
    return ans;
}
/*
dp[i]：前i个牧草堆，最多选多少个草堆子

递推代码：
for (int i = 1; i <= n; i ++) {
    // 假设这里已经排过序了
    // 每个Interval的后端点比前端点大
    // 则可以使用二分，从1~i这一区间寻找比a[i].s更小的a[ans].t
    // 自己手写个二分就行了
    int pos = find(1, i - 1, a[i].s);
    dp[i] = max(dp[i - 1], dp[pos] + a[i].getcnt());
}
*/

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i].s >> a[i].t;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        int pos = find(1, i - 1, a[i].s);
        dp[i] = max(dp[i - 1], dp[pos] + a[i].getcnt());
    }
    cout << dp[n];
    return 0;
}