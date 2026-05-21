#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
int a[N * 2 + 5];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], a[n + i] = a[i];
    deque<int> q;
    q.emplace_back(1);
    int ans = 0;
    for (int i = 2; i <= n * 2; i ++) {
        /*
        while(!q.empty()&&q.front()<i-(n/2))q.pop_front();
        umax(ans,a[q.front()]+a[i]+(i-q.front()));
        while(!q.empty()&&a[q.back()]+(i-q.back())<a[i])q.pop_back();
        q.push_back(i);
        */
        while (!q.empty() && q.front() < i - n / 2) q.pop_front();
        ans = max(ans, a[q.front()] + a[i] + (i - q.front()));
        while (!q.empty() && a[q.back()] + i - q.back() < a[i]) q.pop_back();
        q.emplace_back(i);
    }
    cout << ans;
    return 0;
}
