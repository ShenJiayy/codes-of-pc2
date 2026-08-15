#include <bits/stdc++.h>
using namespace std;

int n, l, wz[205], sj[205];

int ssz(){
	int cnt = 0;
	for (int i = 1; i <= n; i++) cnt += (wz[i] <= sj[i]);
	return cnt;
}
int nsz(){
	int cnt = 0;
	for (int i = n; i >= n; i--) cnt += ((l - wz[i]) <= sj[i]);
	return cnt;
}
int szn(){
	int mx = 0, cnt;
	for (int i = 1; i <= n; i++){
		cnt = 0;
		for (int j = 1; j <= i; j++) cnt += (wz[j] <= sj[j]);
		for (int j = n; j > i; j--)
			cnt += (2 * wz[i] + (l - wz[j]) <= sj[j]);
		mx = max(mx, cnt);
	}
	return mx;
}
int nzs(){
	int mx = 0, cnt;
	for (int i = n; i >= 1; i--){
		cnt = 0;
		for (int j = n; j >= i; j--)
			cnt += ((l - wz[j]) <= sj[j]);
		for (int j = 1; j < i; j++)
			cnt += (2 * (l - wz[i]) + wz[j] <= sj[j]);
		mx = max(mx, cnt);
	}
	return mx;
}

int main(){
	freopen("stamps.in", "r", stdin);
	freopen("stamps.out", "w", stdout);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> wz[i];
	for (int i = 1; i <= n; i++) cin >> sj[i];
	cout << max(max(ssz(), nsz()), max(szn(), nzs()));
	return 0;
}
