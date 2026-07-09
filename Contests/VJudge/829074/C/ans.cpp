#include <bits/stdc++.h>
#define int long long
#define lint long long
#define endl '\n'
using namespace std;
const int N = 5e2+5;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

struct node{
	int num;
	int col;
}a[N][N];

int n,m,f[N*N];
int sz[N*N],col[N*N];
bitset<1> vis[N][N];
set<int > s;
map<int,int > table;

inline int find(int x){
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

inline void merge(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx != fy) f[fx] = fy;
}

inline void dfs(int x,int y){
	vis[x][y].set();
	for(int idx = 0; idx < 4; idx++){
		int tx = x + dx[idx];
		int ty = y + dy[idx];
		if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
		if(a[tx][ty].col == a[x][y].col && vis[tx][ty] == false) dfs(tx,ty);
		else if(a[tx][ty].col != a[x][y].col) s.insert(f[a[tx][ty].num]);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j].col;
			a[i][j].num = (i-1) * m + j;
			f[a[i][j].num] = a[i][j].num;
			if(i > 1 && a[i-1][j].col == a[i][j].col) merge(a[i][j].num,a[i-1][j].num);
			if(j > 1 && a[i][j-1].col == a[i][j].col) merge(a[i][j].num,a[i][j-1].num);
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			sz[find(a[i][j].num)]++;
			col[f[a[i][j].num]] = a[i][j].col;
			ans = max(ans,sz[f[a[i][j].num]]);
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(vis[i][j] == true)
				continue;

			dfs(i,j);

			for(int val : s){
				if(table.find(col[val]) == table.end())
					table[col[val]] = sz[val];
				else table[col[val]] += sz[val];
			}

			int maxCol = 0;
			for(auto val : table)
				if(!maxCol || table[maxCol] < val.second)
					maxCol = val.first;
			ans = max(ans,sz[f[a[i][j].num]]+table[maxCol]);
			s.clear(),table.clear();
		}
	}

	cout << ans << endl;
	return 0;
}
