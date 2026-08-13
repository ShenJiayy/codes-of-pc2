#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> temp;
vector <int> st;

int main(){
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin >> n;
	int tmp;
	bool z2 = 1;
	for (int i = 1; i <= n; i++){
		cin >> tmp;
		if (tmp > 2) z2 = 0;
		temp.push_back(tmp);
	}
	if (!z2){
		for (int i = 1; i <= n; i++){
			tmp = temp[i - 1];
			st.push_back(tmp);
			for (int j = st.size() - 2; j >= 0; j--){
				if (st[j] == tmp){
					while (j < st.size() - 1){
						st[j] = tmp;
						j++;
					}
					break;
				}
			}
		}
		for (int i = 0; i < st.size(); i++){
			cout << st[i] << '\n';
		}
	}else{
		int l1 = 0, l2 = 0;
		for (int i = 0; i < n; i++){
			if (temp[i] == 1) l1 = i;
			else l2 = i;
		}
		if (l1 < l2){
			for (int i = 0; i <= l1; i++) cout << 1 << '\n';
			for (int i = l1 + 1; i <= l2; i++) cout << 2 << '\n';
		}else{
			for (int i = 0; i <= l2; i++) cout << 2 << '\n';
			for (int i = l2 + 1; i <= l1; i++) cout << 1 << '\n';
		}
	}
	return 0;
}
