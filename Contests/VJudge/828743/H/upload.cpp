#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int x[N + 5], y[N + 5];
double dist(int i, int j) {
	return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> x[i] >> y[i];
	double minn = 1000000000;
	for (int i = 1; i <= n; i ++)
		for (int j = i + 1; j <= n; j ++)
			minn = min(minn, dist(i, j));
	printf("%.4lf", round(minn * 10000) / 10000);
	return 0;
}
