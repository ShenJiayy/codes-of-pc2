#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define debug
// #define dpbug
const int N = 2e5;
int a[N + 5], dp[2 * N + 5];
deque<int> q;
void push(int x) {
    while (!q.empty() && dp[q.back()] <= dp[x]) q.pop_back();
    q.push_back(x);
}
int query(int x, int r) {
    while (!q.empty() && q.front() + r < x) q.pop_front();
    return q.front();
}
signed main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("in.in", "r", stdin);
    // #endif
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i ++)
        cin >> a[i];
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    push(0);
    for (int i = l; i <= n + r; i ++) {
        // for (int j = l; j <= r; j ++)
        //     dp[i] = max(dp[i], dp[i - j] + a[i]);
        // q队列单调递减
        /*
for (int r = 1; r <= n; r ++) {
    while (!q.empty() && q.front() < r - k + 1) q.pop_front();
    while (!q.empty() && a[q.back()] <= a[r]) q.pop_back();
    q.push_back(r);
    if (r >= k)
        ans[r - k + 1] = q.front();
}
for (int i = 1; i <= n - k + 1; i ++)
    cout << a[ans[i]] << " ";
        */
        push(i - l);
        dp[i] = dp[query(i, r)] + a[i];
    }
    int ans = -9e18;
    for (int i = n + 1; i <= n + r; i ++)
        ans = max(ans, dp[i]);
    cout << ans;
    #ifdef debug
        #ifdef dpbug
            freopen("debug/dp.csv", "w", stderr);
            cerr << "i,";
            for (int i = 0; i <= n + r; i ++)
                cerr << i << ",";
            cerr << "\ndp[i],";
            for (int i = 0; i <= n + r; i ++)
                cerr << dp[i] << ",";
            fclose(stderr);
        #endif
        #ifdef _WIN32
            system("start debug");
        #else
            system("xdg-open debug");
        #endif
    #endif
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
    	// q淇濇寔鍗曡皟閫掑
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
    	// q淇濇寔鍗曡皟閫掑噺
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