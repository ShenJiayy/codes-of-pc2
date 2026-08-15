#include <bits/stdc++.h>
#define FAIL 2147483647
using namespace std;

int n, k;
bool d[200005];
string s;

int func_70_84_65_72_36_79_73_78_41(int idx, int sheng){
	if (sheng < k * 3) return FAIL;
	if (idx >= n){
		if (sheng != k * 3) return FAIL;
		int jj = 0, oo = 0, ii = 0, gai = n - sheng;
		bool f = 0;
		for (int i = 0; i < s.size(); i++){
			if (d[i]) continue;
			if (s[i] == 'J'){
				if (oo || ii) return FAIL;
				jj++;
			}
			if (s[i] == 'O'){
				if (jj != k || ii) return FAIL;
				oo++;
			}
			if (s[i] == 'I'){
				if (jj != k || oo != k) return FAIL;
				ii++;
			}
			if (jj > k || oo > k || ii > k) return FAIL;
		}
//		for (int i = 0; i < s.size(); i++)cout<<d[i];cout<<' '<<jj<<oo<<ii<<k<<endl;
		for (int i = 0; i < s.size(); i++){
			if (!d[i]) break;
			gai--;
		}
		for (int i = s.size() - 1; i >= 0; i--){
			if (!d[i]) break;
			gai--;
		}
		return gai;
	}
	int mn = 2147483647;
	d[idx] = 1;
	mn = min(func_70_84_65_72_36_79_73_78_41(idx + 1, sheng - 1),
			 mn);
	d[idx] = 0;
	mn = min(func_70_84_65_72_36_79_73_78_41(idx + 1, sheng), mn);
	return mn;
} 

int main(){
	freopen("jjooii.in", "r", stdin);
	freopen("jjooii.out", "w", stdout);
	cin >> n >> k;
	cin >> s;
	int funcr = func_70_84_65_72_36_79_73_78_41(0, n);
	if (funcr == FAIL) funcr = -1;
	cout << funcr;
	return 0;
}
