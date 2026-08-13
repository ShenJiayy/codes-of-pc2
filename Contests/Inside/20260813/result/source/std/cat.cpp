#include <iostream>
#include <cstdio>
using namespace std;
const int N = 2e5 + 5;
struct Edge {int now, nxt;} e[N << 1];
int head[N], cur;
void add(int u, int v) {e[++cur].now = v, e[cur].nxt = head[u], head[u] = cur;}
int a[N], fa[N];
int get(int x) {return x == fa[x] ? x : fa[x] = get(fa[x]);}
int dep[N], jump[N][22];
void dfs(int u, int fa)
{
	dep[u] = dep[fa] + 1, jump[u][0] = fa;
	for (int i = 1; i <= 20; i++) jump[u][i] = jump[jump[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = e[i].nxt) {int v = e[i].now; if (v != fa) dfs(v, u);}
}
int lca(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	for (int i = 20; ~i; i--) if (dep[u] - dep[v] >= (1 << i)) u = jump[u][i];
	if (u == v) return u;
	for (int i = 20; ~i; i--) if (jump[u][i] != jump[v][i]) u = jump[u][i], v = jump[v][i];
	return jump[u][0];
}
int dis(int u, int v) {return dep[u] + dep[v] - 2 * dep[lca(u, v)];}
long long dp[N]; //dp[u] : 以 u 为根，可以走的最长距离
int main()
{
    freopen("cat.in","r",stdin);
    freopen("cat.out","w",stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) fa[i] = i, scanf("%d", &a[i]);
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), add(a[u], a[v]), add(a[v], a[u]);
	dfs(1, 0);
	for (int u = 1; u <= n; u++)
		for (int i = head[u]; i; i = e[i].nxt)
		{
			int v = e[i].now;
			v = get(v);
			if (v < u) fa[v] = u, dp[u] = max(dp[u], dp[v] + dis(u, v));
		}
	cout << dp[n];
	return 0;
}