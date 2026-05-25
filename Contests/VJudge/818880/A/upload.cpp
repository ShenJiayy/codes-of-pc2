#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
char s[N + 5];
int jc, oic;
inline void joi() {
    while (oic --) cout << "OI";
    while (jc --) cout << 'J';
    oic = jc = 0;
}
signed main() {
	int n;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i ++)
        if (s[i] == 'J')
            jc ++;
        else if (s[i] == 'O' && s[i + 1] == 'I')
            oic ++, i ++;
        else
            joi(), cout << s[i];
    joi();
    return 0;
}
