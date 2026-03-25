#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], f[2 * N + 5];
signed main() {
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i ++)
    	cin >> a[i];
    deque<int> q;
    for (int i = l; i <= n + r; i ++) {
        // 此处求f[max(i-r, 0)]~f[min(i-l, n)]+a[i]的最大值
        // 可以使用双端队列
        while (!q.empty() && q.front() < i - l + 1) q.pop_front();
        while (!q.empty() && f[q.back()] >= f[i]) q.pop_back();
        f[i] = q.front() + a[i];
        q.push_back(f[i]);
    }
    int ans = 0;
    for (int i = n + 1; i <= n + r; i ++)
    	ans = max(ans, f[i]);
    cout << ans;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N + 5], ans[N + 5];
signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
    	cin >> a[i];
    deque<int> q;
    for (int r = 1; r <= n; r ++) {
    	// q保持单调递增
        while (!q.empty() && q.front() < r - k + 1) q.pop_front();
        while (!q.empty() && a[q.back()] >= a[r]) q.pop_back();
        q.push_back(r);
        if (r >= k)
            ans[r - k + 1] = q.front();
	}
    for (int i = 1; i <= n - k + 1; i ++)
        cout << a[ans[i]] << " ";
    cout << endl;
    q.clear();
    for (int r = 1; r <= n; r ++) {
    	// q保持单调递减
        while (!q.empty() && q.front() < r - k + 1) q.pop_front();
        while (!q.empty() && a[q.back()] <= a[r]) q.pop_back();
        q.push_back(r);
        if (r >= k)
            ans[r - k + 1] = q.front();
	}
    for (int i = 1; i <= n - k + 1; i ++)
        cout << a[ans[i]] << " ";
    
	return 0;
}
*/