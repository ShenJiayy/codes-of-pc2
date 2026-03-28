#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    priority_queue<int, vector<int>, greater<int>> heap;
    int q;
    cin >> q;
    while (q --) {
        int opt, x;
        cin >> opt >> x;
        if (opt == 1)
            heap.push(x);
        else 
            while (!heap.empty() && heap.top() <= x)
                heap.pop();
        cout << heap.size() << endl;
    }
    return 0;
}