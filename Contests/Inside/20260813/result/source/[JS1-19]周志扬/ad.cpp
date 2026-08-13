#include <bits/stdc++.h>
using namespace std;

struct Point { int X, E;  bool operator < (const Point &_) const { return E > _.E; } };

int n, Ans, Index;
bool Vis[500005];
map<int, int> Map;
Point A[500005];

void Main_1() {
	for(int i = 1; i <= n; i++) {
		int x, y;  scanf("%d %d", &x, &y);  
		if(!Map[x]) Ans++;
		Map[x]++;
	}
	printf("%d", Ans);
}

void Main_23() {
	for(int i = 1; i <= n; i++) {
		int x, y;  scanf("%d %d", &x, &y);
		if(!Map[x]) Map[x] = ++Index;
		A[Map[x]].E = max(A[Map[x]].E, y);
		A[Map[x]].X = x;
	}  sort(A + 1, A + Index + 1);
	for(int i = 1; i <= Index; i++) {
		if(Vis[i]) continue;  Vis[i] = true;  Ans++;
		for(int j = 1; j <= Index; j++)
			if(abs(A[i].X - A[j].X) <= A[i].E - A[j].E)
				Vis[j] = true;
	}
	printf("%d", Ans);
}

int main() {
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);
	scanf("%d", &n);
	if(n <= 1000) { Main_23();  return 0; }
	Main_1();  return 0;
}
