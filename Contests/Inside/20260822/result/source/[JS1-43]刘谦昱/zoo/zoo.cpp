#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define int long long
#define F(i, st, ed) for (int i = st; i <= ed; i++)
using namespace std;

const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int K = 64;

// 已经养了n种动物
// 有m条规则
// 有c种饲料
// 共2^k种动物
int n, m, c, k;
int a[N]; // a[i]表示已经饲养的第i个动物的种类
int aa; // aa表示所有动物取“或”后的结果
bool fl[K]; // fl[i]表示aa在二进制表示下的第i位
vector <int> id[K]; // id[i]表示占用第i位就需要购买的饲料
unordered_map <int, bool> mp; // mp[i]表示饲料i是否必选

inline bool check(int i) {
	if (id[i].empty()) return 1;
	for (auto t : id[i])
		if (!mp[t]) return 0;
	return 1;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("zoo.in", "r", stdin);
	freopen("zoo.out", "w", stdout);
	cin >> n >> m >> c >> k;
	F(i, 1, n) cin >> a[i], aa |= a[i];
	F(i, 0, k - 1) {
		fl[i] = aa - (aa >> 1 << 1);
		aa >>= 1;
	}
	while (m--) {
		int p, q;
		cin >> p >> q;
		id[p].push_back(q);
		if (fl[p]) mp[q] = 1;
	}
	int cnt = 0;
	F(i, 0, k - 1) if (check(i)) cnt++;
	int full = 1 << cnt;
	cout << full - n;
	return 0;
}
