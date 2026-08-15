#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int b[N], ans[N];
int tie[N][2], mx[N][2];

struct node{
	int v, id;
}a[N];

bool cmp(node x, node y){
	return x.v < y.v;
}

int main(){
	freopen("tie.in", "r", stdin);
	freopen("tie.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n+1; i++){
		cin>>a[i].v;
		a[i].id = i;
	}
	for(int i=1; i<=n; i++) cin>>b[i];
	sort(a+1, a+2+n, cmp);
	sort(b+1, b+1+n);
	for(int i=1; i<=n; i++){
		tie[i][0] = max(a[i].v-b[i], 0);
		tie[i][1] = max(a[i+1].v-b[i], 0);
		mx[i][0] = max(mx[i-1][0], tie[i][0]);
//		mx[i][1] = max(mx[i-1][1], tie[i][1]);
	}
	for(int i=n; i>=1; i--) mx[i][1] = max(mx[i+1][1], tie[i][1]);
	for(int i=1; i<=n+1; i++){
		ans[a[i].id] = max(mx[i-1][0], mx[i][1]);
	}
	for(int i=1; i<=n+1; i++) cout<<ans[i]<<' ';
	return 0;
}
