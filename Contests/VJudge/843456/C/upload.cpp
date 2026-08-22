#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5, mod = 998244353;
int a[N + 5], m;
struct Node {
    int opt, pos, add, mul;
} dat[N + 5];
int cnt[N + 5];
vector<int> g1[N + 5], g2[N + 5];
void ts1() {
	queue<int> q;
	vector<int> rd(N + 5);
	for (int i = 0; i <= m; i ++) {
		rd[i] = g1[i].size();
		if (rd[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : g2[u]) {
			dat[v].mul *= dat[u].mul, dat[v].mul %= mod;
			rd[v] --;
			if (rd[v] == 0)
				q.push(v);
		}
	}
}
void ts2() {
	queue<int> q;
	vector<int> rd(N + 5);
	for (int i = 0; i <= m; i ++) {
		rd[i] = g2[i].size();
		if (rd[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		reverse(g1[u].begin(), g1[u].end());
		int nmul = 1;
		for (int v : g1[u]) {
			cnt[v] += cnt[u] * nmul % mod,
			cnt[v] %= mod;
			nmul *= dat[v].mul, nmul %= mod; 
			rd[v] --;
			if (rd[v] == 0)
				q.push(v);
		}
		reverse(g1[u].begin(), g1[u].end());
	}
}
signed main() {
    int n, T;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    cin >> m;
	fill(dat, dat + m + 1, Node{3, 0, 0, 1});
	dat[0].mul = 1;
    for (int i = 1; i <= m; i ++) {
        int opt;
		cin >> opt;
		dat[i].opt = opt;
        if (opt == 1) 
            cin >> dat[i].pos >> dat[i].add;
        else if (opt == 2) 
            cin >> dat[i].mul;
        else {
            int t;
            cin >> t;
            while (t --) {
                int idx;
                cin >> idx;
                g1[i].push_back(idx);
				g2[idx].push_back(i);
            }
        }
    }
	cin >> T;
	cnt[0] = 1;
	while (T --) {
		int x;
		cin >> x;
		g1[0].push_back(x);
		g2[x].push_back(0);
	}
	ts1();
	ts2();
	for (int i = 1; i <= n; i ++)
		a[i] *= dat[0].mul, a[i] %= mod;
	for (int i = 1; i <= m; i ++)
		if (dat[i].opt == 1) {
			a[dat[i].pos] += cnt[i] * dat[i].add % mod;
			a[dat[i].pos] %= mod; 
		}
    for (int i = 1; i <= n; i ++)
        cout << a[i] << " ";
    return 0;
}