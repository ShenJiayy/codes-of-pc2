#include <bits/stdc++.h>
using namespace std;

int n;
char a[500005], b[500005];

int main () {
	
	freopen ("a.in", "r", stdin);
	freopen ("a.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	int len = 0;
	
	for (int i = 1; i <= n; i ++) {
		if (a[i] == 'J') {
			b[++ len] = 'a';
		}
		else if (a[i] == 'O' && a[i + 1] == 'I') {
			b[++ len] = 'b';
			i ++;
		}
		else {
			b[++ len] = a[i];
		}
	}
	
	for (int i = 1; i <= len; i ++) {
		if (b[i] != 'a' && b[i] != 'b') {
			cout << b[i];
			continue;
		}
		int A = 0, B = 0;
		for (int j = i; b[j] == 'a' || b[j] == 'b'; j ++) {
			if (b[j] == 'a') A ++;
			if (b[j] == 'b') B ++;
			i = j;
		}
		for (int j = 1; j <= B; j ++)
			cout << "OI";
		for (int j = 1; j <= A; j ++)
			cout << "J";
	}
	
	return 0;
} 
