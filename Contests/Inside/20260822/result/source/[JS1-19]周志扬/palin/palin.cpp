#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, A[500005];  vector<int> V;

bool Check() {
	for(int i = 0; i < n; i++) if(V[i] != V[n - i - 1]) return false;
	return true;
}

bool Min(int X, int Y) {
	if(X == (1 << n)) return true;
	for(int i = 1; i <= n; i++) {
		if((!(X & (1 << i - 1))) && (Y & (1 << i - 1))) return false;
	}
	return true;
}

void Main_1() {
	int ans = (1 << n);
	for(int S = 0; S < (1 << n - 1); S++) {
		int posL = 1, posR = n;  V.clear();
		for(int i = 1; i < n; i++) {
			if(!(S & (1 << i - 1))) V.push_back(A[posL++]);
			if(S & (1 << i - 1)) V.push_back(A[posR--]);
		}
		V.push_back(A[posL++]);

		if(Check()) ans = S;
	}
	
	if(ans == (1 << n)) { printf("-1\n");  return; }
	
	for(int i = 1; i <= n; i++) {
		if(!(ans & (1 << i - 1))) printf("L");
		if(ans & (1 << i - 1)) printf("R");
	}
	printf("\n");  return;
}

void Main() {
	scanf("%lld", &n);  n *= 2;  for(int i = 1; i <= n; i++) scanf("%lld", &A[i]);  Main_1();
}

signed main() { 
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	int T;  scanf("%lld", &T);  while(T--) Main();  return 0; 
}
