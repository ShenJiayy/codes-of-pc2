#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int n, L, ans;
int X[N], T[N];  bool Vis[N];

int Cal(int x, int y) {
	if(abs(X[x] - X[y]) <= L / 2) return abs(X[x] - X[y]);
	return L - abs(X[x] - X[y]);
}

void Solve(int x, int Step, int Cost, int Cnt) {
	if(Step >= n) {
		ans = max(ans, Cnt);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(Vis[i]) continue;  Vis[i] = true;
		Solve(i, Step + 1, Cost + Cal(x, i), Cnt + (Cost + Cal(x, i) <= T[i]));
		Vis[i] = false;
	}
}

int main() {
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	scanf("%d %d", &n, &L);
	for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &T[i]);
	Solve(0, 0, 0, 0);
	printf("%d", ans);
	return 0;
}
