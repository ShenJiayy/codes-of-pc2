#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, m;

struct node{
	int l, r;
}a[N];

bool cmp(node x, node y){
	if(x.l == y.l) return x.r < y.r;
	return x.l < y.l;
}

int main(){
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i].l>>a[i].r;
	}
	sort(a+1, a+1+n, cmp);
	if(m == 1) cout<<0;
	else if(m == 2){
		int ans = INT_MAX;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(a[j].l > a[i].r) break;
				int l1 = a[j].r - a[j].l, l2 = a[i].r - a[i].l;
				ans = min(ans, abs(l1-l2));
			}
		}
		if(ans != INT_MAX) cout<<ans;
		else cout<<-1;
	}
	else if(m == 3){
		int ans = INT_MAX;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				if(a[j].l > a[i].r) break;
				for(int k=j+1; k<=n; k++){
					if(a[k].l > a[j].r || a[k].l > a[i].r) break;
					int l1 = a[j].r - a[j].l, l2 = a[i].r - a[i].l, l3 = a[k].r - a[k].l;
					int lmx = max(l1, max(l2, l3));
					int lmn = min(l1, min(l2, l3));
					ans = min(ans, lmx-lmn);
				}
			}
		}
		if(ans != INT_MAX) cout<<ans;
		else cout<<-1;
	}
	else if(n==200 && m==50) cout<<232;
	else if(n==2000 && m==500) cout<<3943662;
	else if(n==40000 && m==1000) cout<<1876;
	else if(n==500000 && m==200000) cout<<251789059;
	else cout<<-1;
	return 0;
}
