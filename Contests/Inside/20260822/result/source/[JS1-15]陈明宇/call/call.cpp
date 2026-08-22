#include <bits/stdc++.h>
#define ll long long
#define mod 998244353

using namespace std;

constexpr ll MAXN = 100010;

ll n, m, a[MAXN], q;

class Func {
public: ll t, p, x, c;
		vector<ll> cal;
};

Func funC[MAXN];
ll f[MAXN];

class SegmentTree {
	ll add[MAXN << 2] = {}, mul[MAXN << 2] = {}, sum[MAXN << 2] = {};
	
	static ll L(ll p) { return p << 1; }
	static ll R(ll p) { return p << 1 | 1; }
	
	void push_up(ll p) {
		sum[p] = (sum[L(p)] + sum[R(p)]) % mod;
	}
	
	void changeA(ll p, ll len, ll x) {
		sum[p] += len * x;
		add[p] += x;
		sum[p] %= mod, add[p] %= mod;
	}
	
	void changeM(ll p, ll x) {
		mul[p] *= x;
		sum[p] *= x;
		mul[p] %= mod, sum[p] %= mod;
	}
	
	void push_downA(ll p, ll l, ll r) {
		if (add[p] == 0) return;
		ll mid = (l + r) >> 1;
		changeA(L(p), mid - l + 1, add[p]);
		changeA(R(p), r - mid, add[p]);
		add[p] = 0;
	}
	
	void push_downM(ll p, ll l, ll r) {
		if (mul[p] == 1) return;
		add[p] *= mul[p];
		add[p] %= mod;
		ll mid = (l + r) >> 1;
		changeM(L(p), mul[p]);
		changeM(R(p), mul[p]);
		mul[p] = 1;
	}
	
public: 
	void build(ll p, ll l, ll r) {
		add[p] = 0, mul[p] = 1;
		if (l == r) {
			sum[p] = a[l];
			return;
		}
		ll mid = (l + r) >> 1;
		build(L(p), l, mid);
		build(R(p), mid + 1, r);
		push_up(p);
	}
	
	ll query(ll p, ll l, ll r, ll pos) {
		if (l == r) return sum[p];
		push_downM(p, l, r);
		push_downA(p, l, r);
		ll mid = (l + r) >> 1;
		if (pos <= mid) return query(L(p), l, mid, pos);
		return query(R(p), mid + 1, r, pos);
	}
	
	void modify(ll p, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			changeM(p, x);
			return;
		}
		push_downM(p, l, r);
		push_downA(p, l, r);
		ll mid = (l + r) >> 1;
		if (ql <= mid) modify(L(p), l, mid, ql, qr, x);
		if (qr > mid) modify(R(p), mid + 1, r, ql, qr, x);
		push_up(p);
	}
	
	void modifyA(ll p, ll l, ll r, ll pos, ll x) {
		if (l == r) {
			changeA(p, 1, x);
			return;
		}
		push_downM(p, l, r);
		push_downA(p, l, r);
		ll mid = (l + r) >> 1;
		if (pos <= mid) modifyA(L(p), l, mid, pos, x);
		else modifyA(R(p), mid + 1, r, pos, x);
		push_up(p);
	}
};

SegmentTree st = {};

void callS(ll x) {
	if (funC[x].t == 1) {
		st.modifyA(1, 1, n, funC[x].p, funC[x].x);
		return;
	}
	if (funC[x].t == 2) {
		st.modify(1, 1, n, 1, n, funC[x].x);
		return;
	}
	for (ll y : funC[x].cal)
		callS(y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	freopen("call.in", "r", stdin);
	freopen("call.out", "w", stdout);

	cin >> n;
	
	for (ll i = 1; i <= n; i++) cin >> a[i];

	st.build(1, 1, n);

	cin >> m;
	
	for (ll i = 1; i <= m; i++) {
		ll t, p, v, c;
		cin >> t;
		funC[i].t = t;
		if (t == 1) cin >> funC[i].p >> funC[i].x;
		if (t == 2) cin >> funC[i].x;
		if (t == 3) {
			cin >> funC[i].c;
			for (ll j = 1; j <= funC[i].c; j++) {
				ll x;
				cin >> x;
				funC[i].cal.push_back(x);
			}
		}
	}
	
	cin >> q;
	
	while (q--) {
		ll x; cin >> x;
		callS(x);
	}
	
	for (ll i = 1; i <= n; i++) cout << st.query(1, 1, n, i) << ' ';

	return 0;
}


