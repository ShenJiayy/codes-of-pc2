#include <bits/stdc++.h>
using namespace std;
#define int long long
#define judge
const int N = 1e3;
int a[N + 5];
int box[N + 5], boxx[N + 5];
signed main() {
    #ifdef judge
        freopen("uciteljica.in", "r", stdin);
        freopen("uciteljica.out", "w", stdout);
    #else
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
        freopen("data.log", "w", stderr);
    #endif
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    int cnt = 0;
    for (int l = 1; l <= n; l ++)
        for (int r = l; r <= n; r ++) {
            memset(box, 0, sizeof box);
            for (int i = l; i <= r; i ++)
                box[a[i]] ++;
            memset(boxx, 0, sizeof boxx);
            for (int i = 1; i <= n; i ++)
                boxx[box[i]] ++;
            bool ok = 1;
            for (int i = 1; i <= k; i ++) {
                bool valid = boxx[i];
                if (valid == 0) {
                    ok = 0;
                    break;
                }
            }
            cnt += ok;
        }
    cout << cnt;
    return 0;
}
