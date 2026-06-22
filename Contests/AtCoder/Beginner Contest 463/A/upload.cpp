#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int a, b;
    cin >> a >> b;
    if (a % 16 || b % 9) return puts("No"), 0;
    int k = a / 16;
    if (k == b / 9) puts("Yes");
    else puts("No");
    return 0;
}
