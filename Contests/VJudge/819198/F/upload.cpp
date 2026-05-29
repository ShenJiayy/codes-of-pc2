#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5];
int d(int a, int b) {
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
}
struct Node {
    int s, len;
    int first() {
        return d(s, len);
    }
    int last() {
        return d(s + len - 1, len);
    }
};
vector<Node> box;
void solve() {
    box.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[i] = x - i;
        Node curr = {a[i], 1};
        while (!box.empty() && box.back().last() > curr.first()) {
            curr.len += box.back().len;
            curr.s += box.back().s;
            box.pop_back();
        }
        box.push_back(curr);
    }
    int ans = 0, pa = 0, pb = 0, idx = 0;
    for (Node elm : box) {
        for (int j = 0; j < elm.len; j ++) {
            int val = d(elm.s + j, elm.len);
            pa += a[idx];
            pb += val;
            if (idx < n - 1) ans += pa - pb;
            idx ++;
        }
    }
    cout << ans << endl;
}
signed main() {
	int T;
    cin >> T;
    while (T --) 
        solve();
    return 0;
}