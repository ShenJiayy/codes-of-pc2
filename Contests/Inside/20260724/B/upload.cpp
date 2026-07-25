#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N + 5], b[N + 5];
int main() {
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        cin >> b[i];
    for (int i = 1; i <= n; i ++)
        mp[b[i] - a[i]] ++;
    int maxn = 0;
    for (auto kv : mp)
        maxn = max(maxn, kv.second);
    cout << maxn;
    return 0;
}