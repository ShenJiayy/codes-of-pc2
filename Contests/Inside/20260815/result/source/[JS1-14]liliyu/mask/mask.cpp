#include<bits/stdc++.h>
using namespace std;
int h,w,q;
int a[600][600];
bool b[600][600];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> h >> w >> q;
	while(q--){
		int op;
		cin >> op;
		if(op == 1){
			int x,y,c;
			cin >> x >> y >> c;
			if(!b[x][y]) a[x][y] = c;
			if(!b[x+1][y]) a[x+1][y] = c;
			if(!b[x][y+1]) a[x][y+1] = c;
			if(!b[x+1][y+1]) a[x+1][y+1] = c;
		}
		if(op == 2){
			int x,y;
			cin >> x >> y;
			b[x][y] = true;
			b[x+1][y] = true;
			b[x][y+1] = true;
			b[x+1][y+1] = true;
		}
	}
	for(int i = 1;i <= h;i++){
		for(int j = 1;j <= w;j++){
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}
