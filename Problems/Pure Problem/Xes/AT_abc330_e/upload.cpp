#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[N + 5], cnt[N + 5];
signed main() {
	int n, T;
    cin >> n >> T;
    set<int> st;
    for (int i = 0; i <= n + 1; i ++)
        st.insert(i);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        st.erase(min(a[i], n + 1));
        cnt[min(a[i], n + 1)] ++;
    }
    while (T --) {
        int p, v;
        cin >> p >> v;
        cnt[min(a[p], n + 1)] --;
        if (cnt[min(a[p], n + 1)] == 0) st.insert(a[p]);
        a[p] = v;
        cnt[min(a[p], n + 1)] ++;
        st.erase(a[p]);
        int minn = *(st.begin());
        cout << minn << endl;
    }
    return 0;
}
