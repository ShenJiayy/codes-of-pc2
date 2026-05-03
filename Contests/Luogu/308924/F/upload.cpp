#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], n;
int nxt[N + 5], prv[N + 5], male[N + 5];
bool vis[N + 5];
pair<int, int> ans[N + 5];
struct Node {
    pair<int, int> connection;
    int subabs;
};
bool operator < (Node x, Node y) {
    if (x.subabs != y.subabs) return x.subabs > y.subabs;
    return x.connection.first > y.connection.first;
}
signed main() {
    #ifndef ONLINE_JUDGE
        freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        char opt;
        cin >> opt;
        if (opt == 'B')
            male[i] = 1;
        else
            male[i] = 2;
    }
    priority_queue<Node> heap;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    // Initalize Min-heap
    for (int i = 1; i < n; i ++)
        if (male[i] != male[i + 1])
            heap.push({{i, i + 1}, abs(a[i] - a[i + 1])});
    // Initalize Linked-list
    for (int i = 1; i <= n; i ++)
        nxt[i] = i + 1, prv[i] = i - 1;
    // Solve
    int curr = 0;
    while (!heap.empty()) {
        Node t = heap.top();
        heap.pop();
        int p = t.connection.first, q = t.connection.second;
        if (vis[p] == 0 && vis[q] == 0) {
            nxt[prv[p]] = nxt[q];
            prv[nxt[q]] = prv[p];
            ans[++ curr] = {p, q};
            vis[p] = vis[q] = 1;
            if (vis[prv[p]] == 0 && vis[nxt[q]] == 0)
                if (male[prv[p]] == 2 && male[nxt[q]] == 1)
                    heap.push({{prv[p], nxt[q]}, abs(a[nxt[q]] - a[prv[p]])});
        }
    }
    // Print
    cout << curr << endl;
    for (int i = 1; i <= curr; i ++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}