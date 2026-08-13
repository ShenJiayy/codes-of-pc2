#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N], arr[N], ans[N];

struct node{
	int col, pre, las;
}sel[N];

bool cmp(node x, node y){
	return x.pre < y.pre;
}

int main(){
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		arr[i] = a[i];
	}
	sort(arr+1, arr+1+n);
	int len = unique(arr+1, arr+1+n) - (arr+1);
	for(int i=1; i<=n; i++){
		int x = lower_bound(arr+1, arr+1+len, a[i]) - arr + 1;
		sel[x].col = a[i];
		if(!sel[x].pre) sel[x].pre = i;
		sel[x].las = i;
	}
	sort(sel+1, sel+1+len, cmp);
	for(int i=sel[1].pre; i<=sel[1].las; i++) ans[i] = sel[1].col;
	int maxx = sel[1].las;
	for(int i=2; i<=len; i++){
		if(sel[i].las > maxx){
			maxx = sel[i].las;
			for(int j=sel[i-1].las+1; j<=sel[i].las; j++) ans[j] = sel[i].col;
		}
	}
	for(int i=1; i<=n; i++) cout<<ans[i]<<'\n';
	return 0;
}
