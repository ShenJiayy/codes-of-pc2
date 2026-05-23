#include<bits/stdc++.h>
using namespace std;
int a[500020],n;
map<int,int> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	int k=a[(n-1)/2+1];
	int p=(lower_bound(a+1,a+1+n,k)-a-1);
	int q=n-(upper_bound(a+1,a+1+n,k)-a-1);
	if (abs(p+mp[k]-q)<=abs(q+mp[k]-p)) cout<<*(upper_bound(a+1,a+1+n,k));
	else if (abs(p+mp[k]-q)>abs(q+mp[k]-p)) cout<<k;
	return 0;
} 
