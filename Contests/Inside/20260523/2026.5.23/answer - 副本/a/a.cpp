#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5;
char s[N + 5];
int cj, coi;
signed main() {
    int n;
    cin >> n >> s + 1;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == 'J')
            cj ++;
        else if (s[i] == 'O' && s[i + 1] == 'I')
            coi ++, i ++;
        else
            putoi();
    }
    return 0;
}