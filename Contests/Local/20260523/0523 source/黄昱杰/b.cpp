#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100005];
int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n==3){
		cout<<a[1];
	}
	else{
	int x=(n+1)/2;
	cout<<a[x]; 
	}

	return 0;
}

