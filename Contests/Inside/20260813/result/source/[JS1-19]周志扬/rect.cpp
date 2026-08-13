#include <bits/stdc++.h>
using namespace std;

const int N = 250005;
int n, m, Sum, Ans;
int A[N], S[N], Box[N * 10];  bool Vis[N];

int Cal(int x, int y) { return x && y ? (x - 1) * m + y : 0; }

int Discal_x(int x) { return x / m + 1; }

int Discal_y(int x) { return x % m; }

int Find(int x, int y) {
	int Lx = 1, Ly = 1, Rx = x, Ry = y, Resx = x, Resy = y;
	while(Lx < Rx && Ly < Ry) {
		int Midx = Lx + Rx >> 1, Midy = Ly + Ry >> 1;
		if(Vis[Cal(Midx, Midy)]) break;  Vis[Cal(Midx, Midy)] = true;
		if(S[Cal(x, y)] + S[Cal(Midx - 1, Midy - 1)] - S[Cal(Midx - 1, y)] - S[Cal(x, Midy - 1)] == 0) Rx = Resx = Midx, Ry = Resy = Midy;
		else Lx = Midx, Ly = Midy;
	}
	return Cal(Resx, Resy);
}

void Main_1() {
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) S[Cal(i, j)] = S[Cal(i - 1, j)] + S[Cal(i, j - 1)] - S[Cal(i - 1, j - 1)] + A[Cal(i, j)];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int x = 1; x <= i; x++)
				for(int y = 1; y <= j; y++)
					if(S[Cal(i, j)] + S[Cal(x - 1, y - 1)] - S[Cal(x - 1, j)] - S[Cal(i, y - 1)] == (i - x + 1) * (j - y + 1)) 
						Ans++;
	
	printf("%d", Ans);
}

void Main_2() {
	Box[0]++;
	
	for(int i = 1; i <= m; i++) {
		A[i] += A[i - 1];
		Ans += Box[A[i] - i];
		Box[A[i] - i]++;
	}
	
	printf("%d", Ans);
}

void Main_3() {
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) S[Cal(i, j)] = S[Cal(i - 1, j)] + S[Cal(i, j - 1)] - S[Cal(i - 1, j - 1)] + (A[Cal(i, j)] == 0);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int res = Find(i, j);
			Ans += (i - Discal_x(res) + 1) * (j - Discal_y(res) + 1);
		}
	}
	
	printf("%d", Ans);
}

int main() {
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &A[Cal(i, j)]);
	if(n <= 30 && m <= 30) { Main_1();  return 0; }
	if(n == 1) { Main_2();  return 0; }
	Main_3();  return 0;
}
