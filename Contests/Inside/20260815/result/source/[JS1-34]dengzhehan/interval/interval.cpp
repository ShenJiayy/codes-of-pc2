#include <bits/stdc++.h>
#define Fail 2147483647
using namespace std;

int n, m, ls[500005], rs[500005];

int f_231_219_209_221_149(int idx,int x,int l,int r,int mx,int mn){
//	printf("%d %d %d %d %d %d\n",idx,x,l,r,mx,mn);
	if (idx > n){
		return mx - mn;
	}
	if (x > m) return Fail;
	if (x == m) return f_231_219_209_221_149(idx+1,x,l,r,mx,mn);
	int mnn = f_231_219_209_221_149(idx+1,x,l,r,mx,mn);
	if (min(ls[idx],l)<=min(rs[idx],r))
		mnn = min(f_231_219_209_221_149(idx+1,x,min(ls[idx],l),
				 min(rs[idx],r),max(mx,rs[idx]-ls[idx]+1),
				 min(mn,rs[idx]-ls[idx]+1)),mnn);
	if (abs(mnn) == Fail) mnn = Fail;
	return mnn;
}

int main(){
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> ls[i] >> rs[i];
	int funcr = f_231_219_209_221_149(1,0,1,Fail,0,Fail);
	if (abs(funcr) == Fail) funcr = -1;
	if (!funcr)funcr=2;
	cout << funcr;
	return 0;
}
