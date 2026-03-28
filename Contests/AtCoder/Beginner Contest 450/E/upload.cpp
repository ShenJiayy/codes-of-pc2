#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b;
char dfs(int n) {
	if (n == 1) 
		cout << a;
	else if (n == 2)
		cout << b;
	else {dfs(n - 1); dfs(n - 2);}
	return '\0';
} 
signed main() {
    int n;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i ++) {
        cout << i << ": ";
		dfs(i);
		cout << endl;
	}
    return 0;
}
