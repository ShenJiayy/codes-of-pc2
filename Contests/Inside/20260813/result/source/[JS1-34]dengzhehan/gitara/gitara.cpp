#include <bits/stdc++.h>
using namespace std;

int n, p;
int xx[10][500005], cnts[10] = {0};

int main(){
	freopen("gitara.in", "r", stdin);
	freopen("gitara.out", "w", stdout);
	cin >> n >> p;
	int a, b;
	long long cnt = 0;
	for (int i = 1; i <= n; i++){
		cin >> a >> b;
		if (b > xx[a][cnts[a]]){
			xx[a][++cnts[a]] = b;
			cnt++;
			continue;
		}
		if (b == xx[a][cnts[a]]) continue;
		int wz = lower_bound(xx[a] + 1, xx[a] + cnts[a] + 1, b) - xx[a];
		if (xx[a][wz] > b){
			cnt += cnts[a] - wz + 1;
			cnts[a] = wz - 1;
			cnt++;
			xx[a][++cnts[a]] = b;
		}else{
			cnt += cnts[a] - wz;
			cnts[a] = wz;
		}
//		printf("i%d a%d b%d wz%d cnts[a]%d\n", i, a, b, wz, cnts[a]);
	}
	cout << cnt;
	return 0;
}
