#include <bits/stdc++.h>
using namespace std;
#define int long long
char s[20] = "0HelloWorld";
signed main() {
	int x;
    cin >> x;
    for (int i = 1; i <= 10; i ++)
        if (i != x)
            cout << s[i];
    return 0;
}
