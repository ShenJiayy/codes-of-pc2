#include <iostream>
#include <unordered_map>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 2e5 + 5;
int n, k, ans = 1e9;
int pj[N], po[N], pi[N];
char ch[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("jjooii.in", "r", stdin);
	freopen("jjooii.out", "w", stdout);
	cin >> n >> k;
	F(s, 1, n) {
		cin >> ch[s];
		pj[s] = pj[s - 1];
		po[s] = po[s - 1];
		pi[s] = pi[s - 1];
		if (ch[s] == 'J') pj[s]++;
		if (ch[s] == 'O') po[s]++;
		if (ch[s] == 'I') pi[s]++;
	}
	F(a, 1, n) {
		if (ch[a] != 'J') continue ;
		F(b, a, n) {
			if (ch[b] != 'J') continue ;
			if (pj[b] - pj[a - 1] < k) continue ;
			F(c, b, n) {
				if (ch[c] != 'O') continue ;
				F(d, c, n) {
					if (ch[d] != 'O') continue ;
					if (po[d] - po[c - 1] < k) continue ;
					F(e, d, n) {
						if (ch[e] != 'I') continue ;
						F(f, e, n) {
							if (ch[f] != 'I') continue ;
							if (pi[f] - pi[e - 1] < k) continue ;
							int x = b - a + 1;
							int y = d - c + 1;
							int z = f - e + 1;
							ans = min(ans, x + y + z - 3 * k);
						}
					}
				}
			}
		}
	}
	cout << (ans == 1e9 ? -1 : ans);
	return 0;
}
