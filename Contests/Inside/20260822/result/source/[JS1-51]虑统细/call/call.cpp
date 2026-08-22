#include <bits/stdc++.h>
using namespace std;

#define int long long
const int Mod = 998244353;
const int N = 1e5 + 5;
const int C = 1e6 + 5;
int n, m, a[N], q, ls[C];
struct Fu {
	int opp, po;  // 对哪个点操作 / -1 = 全部 
	int pl, mu;
} f[N];
struct Edge {
	int v, nxt;
} e[C + N];
int head[N], cnt;

void add (int u, int v) {
	e[++ cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
} 

int sum[N], tim = 1;
void dfs (int x) {
	if (f[x].opp == 1) {
		sum[f[x].po] += f[x].pl * tim;
		sum[f[x].po] %= Mod;
		return;
	}
	if (f[x].opp == 2) {
		tim *= f[x].mu;
		tim %= Mod;
		return;
	}
	for (int i = head[x]; ~i; i = e[i].nxt)
		dfs (e[i].v);
}

signed main () {
	
	freopen ("call.in", "r", stdin);
	freopen ("call.out", "w", stdout);

	memset (head, -1, sizeof head);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) scanf ("%lld", &a[i]);
	scanf ("%d", &m);
	for (int i = 1; i <= m; i ++) {
		int op;
		scanf ("%lld", &op);
		f[i].opp = op;
		if (op == 1) {
			int x, y;
			scanf ("%lld%lld", &x, &y);
			f[i].po = x;
			f[i].mu = 1;
			f[i].pl = y;
		}
		if (op == 2) {
			int x;
			scanf ("%lld", &x);
			f[i].mu = x;
			f[i].pl = 0;
			f[i].po = -1;
		}
		if (op == 3) {
			int c;
			scanf ("%lld", &c);
			for (int j = 1; j <= c; j ++) {
				int v;
				scanf ("%d", &v);
				add (i, v);
			}
		}
	}
	scanf ("%d", &q);
	for (int i = 1; i <= q; i ++) {
		int v;
		scanf ("%d", &v);
		add (0, v);
	}
	dfs (0);
	for (int i = 1; i <= n; i ++) {
		a[i] = a[i] * tim % Mod + sum[i];
		a[i] %= Mod;
		cout << a[i] << " ";
	}
	return 0;
}

