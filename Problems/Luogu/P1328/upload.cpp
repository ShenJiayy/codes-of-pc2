#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200;
int ra[N + 5], rb[N + 5];
bool ck[5][5] = {
    0, 0, 1, 1, 0,
    1, 0, 0, 1, 0,
    0, 1, 0, 0, 1,
    0, 0, 1, 0, 1,
    1, 1, 0, 0, 0,
};
signed main() {
	int n, na, nb;
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i ++)
        cin >> ra[i];
    for (int i = 0; i < nb; i ++)
        cin >> rb[i];
    int sa = 0, sb = 0;
    for (int i = 0; i < n; i ++) {
        int ca = ra[i % na], cb = rb[i % nb];
        sa += ck[ca][cb], sb += ck[cb][ca];
    }
    cout << sa << " " << sb;
    return 0;
}