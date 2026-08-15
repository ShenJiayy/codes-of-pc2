#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
char s[N + 5];
vector<int> pos[128];
signed main() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i ++)
        cin >> s[i], pos[s[i]].push_back(i);
    int po = 1, pi = 1;
    int ans = 9e18;
    for (int i = 0; i < pos['J'].size(); i ++) {
        if (i + m > pos['J'].size())
            break;
        int po = lower_bound(pos['O'].begin(), pos['O'].end(), pos['J'][i + m - 1]) - pos['O'].begin();
        if (po + m > pos['O'].size())
            break;
        int pi = lower_bound(pos['I'].begin(), pos['I'].end(), pos['O'][po + m - 1]) - pos['I'].begin();
        if (pi + m > pos['I'].size())
            break;
        ans = min(ans, pos['I'][pi + m - 1] - pos['J'][i] + 1 - 3 * m);
    }
    if (ans == 9e18)
        puts("-1");
    else cout << ans;
	return 0;
}