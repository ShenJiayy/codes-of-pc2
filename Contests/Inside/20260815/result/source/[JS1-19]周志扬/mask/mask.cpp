#include <bits/stdc++.h>]
using namespace std;

int A[505][505];  bool Vis[505][505];

int main() {
	freopen("mask.in", "r", stdin);
	freopen("mask.out", "w", stdout);
	int n, m, Q;  scanf("%d %d %d", &n, &m, &Q);
	while(Q--) {
		int op, x, y, a;  scanf("%d", &op);
		
		if(op == 1) {
			scanf("%d %d %d", &x, &y, &a);
			if(!Vis[x][y]) A[x][y] = a;
			if(!Vis[x + 1][y]) A[x + 1][y] = a;
			if(!Vis[x][y + 1]) A[x][y + 1] = a;
			if(!Vis[x + 1][y + 1]) A[x + 1][y + 1] = a;
		}
		if(op == 2) { scanf("%d %d", &x, &y);  Vis[x][y] = Vis[x + 1][y] = Vis[x][y + 1] = Vis[x + 1][y + 1] = true; }
	}
	return 0;
} 
