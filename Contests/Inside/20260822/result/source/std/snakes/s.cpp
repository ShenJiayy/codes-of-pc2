#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, T;
vector<ll> a;

struct Result {
    int cnt;
    vector<char> alive;
};

bool cmpSnake(const pair<ll,int>& x, const pair<ll,int>& y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second < y.second;
}

Result solve(vector<pair<ll,int>> s) {
    sort(s.begin(), s.end(), cmpSnake);

    int len = s.size();
    Result ret;
    ret.alive.assign(n + 1, 0);

    if (len == 1) {
        ret.cnt = 1;
        ret.alive[s[0].second] = 1;
        return ret;
    }

    auto weak = s.front();
    auto strong = s.back();

    vector<pair<ll,int>> nxt;
    for (int i = 1; i + 1 < len; i++) {
        nxt.push_back(s[i]);
    }

    nxt.push_back({strong.first - weak.first, strong.second});

    Result after = solve(nxt);

    if (after.alive[strong.second]) {
        return after;
    } else {
        ret.cnt = len;
        for (auto [v, id] : s) {
            ret.alive[id] = 1;
        }
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    cin >> n;
    a.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int tc = 1; tc <= T; tc++) {
        if (tc > 1) {
            int k;
            cin >> k;
            for (int i = 1; i <= k; i++) {
                int x;
                ll y;
                cin >> x >> y;
                a[x] = y;
            }
        }

        vector<pair<ll,int>> s;
        for (int i = 1; i <= n; i++) {
            s.push_back({a[i], i});
        }

        Result ans = solve(s);
        cout << ans.cnt << '\n';
    }

    return 0;
}