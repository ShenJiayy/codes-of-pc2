#include <bits/stdc++.h>
using namespace std;

int n, m, unvis;
vector <int> maps[300005];
bool vis[300005][2];

void dfs(int x, bool da){
//	cout << x << ' ' << da << endl;
	for (int i = 0; i < maps[x].size(); i++){
		if (!vis[maps[x][i]][(da + 1) % 2] && ((da && maps[x][i] > x) || (!da && maps[x][i] < x))){
			if (!vis[maps[x][i]][da]) unvis--;
			vis[maps[x][i]][(da + 1) % 2] = 1;
			int tt = maps[x][i];
			dfs(tt, (da + 1) % 2);
		}
	}
	return ;
}

int main(){
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++){
		cin >> u >> v;
		maps[u].push_back(v);
		maps[v].push_back(u);
	}
	for (int i = 1; i <= n; i++){
		unvis = n - 1;
		for (int j = 1; j <= n; j++){
			vis[j][0] = 0;
			vis[j][1] = 0;
		}
		vis[i][1] = 1;
		dfs(i, 1);
		cout << unvis << '\n';
	}
	return 0;
}
