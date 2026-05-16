#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e8;
bool isp[N + 5];
vector<int> p;
signed main() {
	int n, T;
	scanf("%lld%lld", &n, &T);
	memset(isp, 1, sizeof isp);
	isp[0] = isp[1] = 0;
	for (int i = 2; i <= n; i ++)
		if (isp[i])
			for (int j = i + i; j <= n; j += i)
				isp[j] = 0;
	for (int i = 1; i <= n; i ++)
		if (isp[i])
			p.emplace_back(i);
	while (T --) {
		int idx;
		scanf("%lld", &idx);
		idx --;
		if (idx < p.size())
			printf("%lld\n", p[idx]);
		else puts("Error: Index Out of Range (IORE)");
	}
	return 0;
}
