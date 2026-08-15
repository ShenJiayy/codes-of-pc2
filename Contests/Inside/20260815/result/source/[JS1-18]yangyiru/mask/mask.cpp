#include <bits/stdc++.h>
using namespace std;

int h, w, q;
int a[505][505];
bool vis[505][505];

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

int main(){
	freopen("mask.in", "r", stdin);
	freopen("mask.out", "w", stdout);
	cin>>h>>w>>q;
	while(q--){
		int op, x, y, c;
		cin>>op>>x>>y;
		if(op == 1){
			cin>>c;
			for(int i=0; i<4; i++){
				int fx = x + dx[i], fy = y + dy[i];
				if(!vis[fx][fy]) a[fx][fy] = c;
			}
		}
		else{
			for(int i=0; i<4; i++){
				int fx = x + dx[i], fy = y + dy[i];
				vis[fx][fy] = 1;
			}
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}
