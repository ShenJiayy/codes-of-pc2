#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Data { int x, y;  bool operator < (const Data &_) const { return y != _.y ? y < _.y : x < _.x; } };

int n, m, c, k, cur, St, State, ans = 1;
int A[1000005];
Data B[1000005], C[1000005];

void Cal(int x) {
	for(int i = 1; i <= k; i++) {
		if(x & 1) St |= (1 << i - 1);
		x >>= 1;
	}
}

signed main() {
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	
	scanf("%lld %lld %lld %lld", &n, &m, &c, &k);
	for(int i = 1; i <= n; i++) { scanf("%lld", &A[i]);  Cal(A[i]); }
	for(int i = 1; i <= m; i++) scanf("%lld %lld", &B[i].x, &B[i].y);  sort(B + 1, B + m + 1);
	
	for(int i = 1; i <= m; i++) {
		if(B[i].y != C[cur].y) cur++;
		C[cur].x |= (1 << B[i].x);
		C[cur].y = B[i].y;
	}
	
	for(int i = 1; i <= cur; i++) {
		if(St & C[i].x) continue;
		State |= C[i].x;
	}

	for(int i = 1; i <= k; i++) {
		if(!(State & 1))  ans *= 2;
		State >>= 1;
	}
	printf("%lld", ans - n);
	return 0;
}
