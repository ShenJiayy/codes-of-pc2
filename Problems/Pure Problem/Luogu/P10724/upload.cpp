#include <bits/stdc++.h>
using namespace std;
#define int long long
const int table[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}, N = 1e5;
int a[N + 5], b[N + 5], s[N + 5], cnt[1024];
signed main() {
	int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < 10; j ++) 
            for (int ba = a[i]; ba % table[j] == 0; ba /= table[j]) 
                b[i] ^= (1 << j);
    for (int i = 1; i <= n; i ++)
        s[i] = s[i - 1] ^ b[i];
    int ans = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i ++) {
        ans += cnt[s[i]];
        cnt[s[i]] ++;
    }
    cout << ans;
    return 0;
}