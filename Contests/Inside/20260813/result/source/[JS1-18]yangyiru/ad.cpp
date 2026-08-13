#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n;
int arr[N];

struct node{
	int x, e;
}a[N];

bool cmp(node x, node y){
	if(x.x == y.x) return x.e < y.e;
	return x.x < y.x;
}

int main(){
	freopen("ad.in", "r", stdin);
	freopen("ad.out", "w", stdout);
	cin>>n;
	bool flag = 1;
	for(int i=1; i<=n; i++){
		cin>>a[i].x>>a[i].e;
		arr[i] = a[i].x;
		if(a[i].e!=a[i-1].e && i>1) flag = 0;
	}
	if(flag){
		sort(arr+1, arr+1+n);
		int ans = unique(arr+1, arr+1+n) - (arr+1);
		cout<<ans;
		return 0;
	}
	return 0;
}
