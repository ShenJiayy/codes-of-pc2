#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
unordered_map<int, int> mp;
int res[N + 5];
signed main() {
	int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        mp[x] ++;
    }
    int curr = 0;
    for (auto kv : mp) 
        res[++ curr] = kv.first * kv.second;
    sort(res + 1, res + curr + 1, greater<int>());
    int sum = 0;
    for (int i = k + 1; i <= curr; i ++)
        sum += res[i];
    cout << sum;
    return 0;
}
