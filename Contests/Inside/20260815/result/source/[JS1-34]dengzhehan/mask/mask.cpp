#include <bits/stdc++.h>
using namespace std;

int h, w, q, fk[505][505];
bool zb[505][505];

int main(){
	freopen("mask.in", "r", stdin);
	freopen("mask.out", "w", stdout);
	cin >> h >> w >> q;
	int op, x, y, z;
	for (int i = 1; i <= q; i++){
		cin >> op >> x >> y;
		if (op == 1){
			cin >> z;
			if (!zb[x][y]) fk[x][y]=z;
			if (!zb[x+1][y]) fk[x+1][y]=z;
			if (!zb[x][y+1]) fk[x][y+1]=z;
			if (!zb[x+1][y+1]) fk[x+1][y+1]=z;
		}else{
			zb[x][y] = 1;
			zb[x+1][y] = 1;
			zb[x][y+1] = 1;
			zb[x+1][y+1] = 1;
		}
	}
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= h; j++){
			cout << fk[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
