#include <bits/stdc++.h>
#define ul unsigned long long
#define deb(x) cout << "debug:" << x << '\n'
using namespace std;

ul n, m, c, k;
ul a[1000005];
ul p, q;

int main(){
    freopen("zoo.in", "r", stdin);
    freopen("zoo.out", "w", stdout);
    cin >> n >> m >> c >> k;
    ul hve = 0;
    for (ul i = 1; i <= n; i++){
        cin >> a[i];
        hve |= a[i];
    }
    ul cann = k, cannn[75] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    for (ul i = 1; i <= m; i++){
        cin >> p >> q;
        if (!((1 << p) & hve)){
            if (cannn[p]){
                cannn[p] = 0;
                cann--;
            }
        }
    }
    ul ans = 1 << cann;
    cout << ans - n;
    return 0;
}