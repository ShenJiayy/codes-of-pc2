#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	int n, k;
    cin >> n >> k;
    set<int> st;
    st.insert(1);
    for (int a = 2; a <= n; a ++) {
        int mul = a;
        for (int b = 1; mul <= n; b ++, mul *= a)
            if (b >= k)
                st.insert(mul);
    }
    cout << st.size();
    return 0;
}
