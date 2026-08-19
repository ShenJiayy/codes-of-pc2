#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 400;
vector<int> g[N + 5];
void dfs(int id) {
    
}
signed main() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i ++) {
        int f;
        cin >> f;
        g[f].push_back(i);
        g[i].push_back(f);
    }
    
    return 0;
}
