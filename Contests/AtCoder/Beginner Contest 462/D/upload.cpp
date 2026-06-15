#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5, M = 1e6;
struct Line {
    int s, t;
} a[N + 5];
vector<int> ele[M + 5], ;
bool cmp(Line x, Line y) {
    if (x.s != y.s) return x.s < y.s;
    return x.t < y.t;
}
int find(vector<int> x, int v) {
    int l = 0, r = x.size() - 1, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (x[mid] < v)
            ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
signed main() {
	int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i ++) 
        cin >> a[i].s >> a[i].t,
        ele[a[i].s].push_back(a[i].t);
    int cnt = 0;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++) {
        int ed = find(ele[a[i].s], a[i].t + d), st = lower_bound(ele[a[i].s].begin(), ele[a[i].s].end(), a[i].t) - ele[a[i].s].begin();
        cnt += ed - st + 1;
        
        st = a[i].t - d + 1;
        // 这里只是满足了一个要求
        // 
    }
    cout << cnt;
    return 0;
}
