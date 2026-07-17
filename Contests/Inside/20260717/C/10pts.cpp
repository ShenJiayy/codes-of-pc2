#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000;
int a[N + 5], n;
vector<int> ans;
bool vis[N + 5];
void dfs(int id) {
    if (id >= n) {
        vector<int> v;
        int sum = a[1];
        for (int i = 1; i <= n; i ++)
            if (vis[i])
                sum += a[i + 1];
            else 
                v.push_back(sum),
                sum = a[i + 1];
        bool valid = 1;
        for (int i = 0; i + 1 < v.size(); i ++)
            if (v[i] > v[i + 1])
                valid = 0;
        if (valid && ans.size() < v.size()) 
            ans = v;
        return ;
    }
    vis[id] = 0;
    dfs(id + 1);
    vis[id] = 1;
    dfs(id + 1);
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dfs(1);
    cout << ans.size() << endl;
    for (int val : ans)
        cout << val << " ";
    return 0;
}