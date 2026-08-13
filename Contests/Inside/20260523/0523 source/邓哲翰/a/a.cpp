#include <bits/stdc++.h>
using namespace std;

int n, cnt_j = 0, cnt_oi = 0;
string s, ans = "";

void clmem(){
	for (int j = 1; j <= cnt_oi; j++){
		ans += "OI";
	}
	cnt_oi = 0;
	for (int j = 1; j <= cnt_j; j++){
		ans += "J";
	}
	cnt_j = 0;
}

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; ){
		if (s[i] == 'J'){
			cnt_j++;
			i++;
			continue;
		}else if (s[i] == 'O'){
			if (i < n - 1 && s[i + 1] == 'I'){
				cnt_oi++;
				i += 2;
				continue;
			}else{
				clmem();
				ans += s[i];
				i++;
				continue;
			}
		}else{
			clmem();
			ans += s[i];
			i++;
			continue;
		}
	}
	clmem();
	cout << ans;
	return 0;
} 
