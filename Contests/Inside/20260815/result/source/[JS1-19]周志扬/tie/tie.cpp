#include <bits/stdc++.h>
using namespace std;

struct Data { int id, val;  bool operator < (const Data &_) const { return val < _.val; } };

const int N = 2e5 + 5;
Data A[N];
int B[N], C[N], MaxL[N], MaxR[N], Ans[N];

int main() {
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	int n;  scanf("%d", &n);
	for(int i = 1; i <= n + 1; i++) { scanf("%d", &A[i].val);  A[i].id = i; }  sort(A + 1, A + n + 2);
	for(int i = 1; i <= n; i++) scanf("%d", &B[i]);  sort(B + 1, B + n + 1);
	
	for(int i = 1; i <= n; i++) MaxL[i] = max(MaxL[i - 1], max(A[i].val - B[i], 0));
	for(int i = n + 1; i >= 2; i--) MaxR[i] = max(MaxR[i + 1], max(A[i].val - B[i - 1], 0));
	
	for(int i = 1; i <= n + 1; i++) Ans[A[i].id] = max(MaxL[i - 1], MaxR[i + 1]);
	for(int i = 1; i <= n + 1; i++) printf("%d ", Ans[i]);
	return 0;
}
