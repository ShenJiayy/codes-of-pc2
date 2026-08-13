#include <bits/stdc++.h>
using namespace std;

int n, m, a[105][105];

int main(){
freopen("rect.in", "r", stdin);
freopen("rect.out", "w", stdout);
cin >> n >> m;
for (int i = 1; i <= n; i++){
for (int j = 1; j <= m; j++){
cin >> a[i][j];
}
}
int cnt = 0;
for (int i = 1; i <= n; i++){
for (int j = 1; j <= m; j++){
for (int i_ = i; i_ <= n; i_++){
for (int j_ = j; j_ <= m; j_++){
int sum = 0;
for (int i__ = i; i__ <= i_; i__++){
for (int j__ = j; j__ <= j_; j__++){
sum += a[i__][j__];
}
}
if (sum == (i_ - i + 1) * (j_ - j + 1))cnt++;
}
}
}
}
cout << cnt;
return 0;
}
