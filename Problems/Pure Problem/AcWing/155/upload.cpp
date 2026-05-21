#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
set<pii> running; // {startm, M}
queue<pii> waiting; // {M, P}
priority_queue<pii, vector<pii>, greater<pii>> process; // {P, M}
int ans;
bool push(int t, int m, int p) {
    int last = 0;
    for (auto it = running.begin(); it != running.end(); it ++) {
        if ((*it).first - last >= m) {
            // 分配在这
            running.insert({last, m});
            process.push({t + p, last});
            return 1;
        }
        last = (*it).first + (*it).second;
    }
    return 0;
}
void finish(int t) {
    while (!process.empty() && process.top().first <= t) {
        int pend = process.top().first;
        while (!process.empty() && process.top().first == pend) {
            pii now = process.top();
            process.pop();
            auto it = running.lower_bound({now.second, 0});
            if (it != running.end())
                running.erase(it);
        }
        while (!waiting.empty()) {
            pii nxt = waiting.front();
            if (push(pend, nxt.first, nxt.second))
                waiting.pop();
            else
                break;
        }
        ans = max(ans, pend);
    }
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    int n, cnt = 0;
    cin >> n;
    running.insert({n, 0});
    while (1) {
        int t, m, p;
        cin >> t >> m >> p;
        if (t == m && m == p && p == 0) break;
        finish(t);
        if (!push(t, m, p))
            waiting.push({m, p}), cnt ++;
    }
    finish(2e9);
    cout << ans << endl << cnt;
    return 0;
}