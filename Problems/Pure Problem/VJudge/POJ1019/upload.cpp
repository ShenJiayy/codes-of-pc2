#include <iostream>
#include <cmath>
using namespace std;
#define int long long
const int N = 31269;
int tb[N + 5], ts[N + 5];
void init() {
    tb[1] = ts[1] = 1;
    for (int i = 2; i <= N; i ++) {
        // 1~i，多了i
        tb[i] = tb[i - 1] + log(i) + 1;
        ts[i] = ts[i - 1] + tb[i];
    }
}
int query(int x) {
    int gid = 1;
    while (ts[gid] < x) gid ++;
    int p = x - ts[gid - 1];
    int l = 0, pid;
    for (pid = 1; l < p; pid ++)
        l += log(pid) + 1;
    pid --;
    return pid / (int)(pow(10, l - p)) % 10;
}
signed main() {
    int T;
    cin >> T;
    init();
    while (T --) {
        int x;
        cin >> x;
        cout << query(x) << endl;
    }
    return 0;
}