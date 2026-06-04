#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 2e5 + 1;
bool valid[N + 5];
int fx[N + 5], curr;
signed main() {
	int x, T;
    scanf("%lld%lld", &x, &T);
    for (int i = ceil(sqrt(x)); i * i <= N; i ++)
        for (int j = 1; i * i * j <= N; j ++)
            valid[i * i * j] = 1;
    for (int i = x; i <= N; i ++)
        if (valid[i])
            fx[++ curr] = i;
    while (T --) {
        int n;
        scanf("%lld", &n);
        int v = *lower_bound(fx + 1, fx + curr + 1, n);
        if (v == n)
            printf("lucky\n");
        else
            printf("%lld\n", v);
    }
    return 0;
}
