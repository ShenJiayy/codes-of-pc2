#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int a[N + 5];
signed main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	set<int> st;
	for (int i = 1; i <= n; i ++)
		st.insert(a[i]);
	int sum = 0, pos = 0;
	for (int i = 1; i <= n; i ++) {
		auto lp = st.lower_bound(pos);
		if (lp != st.begin())
			lp --;
		auto rp = st.lower_bound(pos);
		if (rp == st.end()) rp --;
		if (abs((*lp) - pos) <= abs((*rp) - pos))
			sum += abs((*lp) - pos), pos = (*lp), st.erase(*lp);
		else if (rp != st.end())
			sum += abs((*rp) - pos), pos = (*rp), st.erase(*rp);
	}
	cout << sum;
	return 0;
}