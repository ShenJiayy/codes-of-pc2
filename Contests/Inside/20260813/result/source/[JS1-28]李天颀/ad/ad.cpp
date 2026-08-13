#include <bits/stdc++.h>
using namespace std;
int n,ans;
bool book[500010];
struct node{
	int x,e;
}arr[500010];
bool cmp(node a,node b){
	return a.x<b.x;
}
bool flag;
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i].x>>arr[i].e;
	}
//	for(int i=2;i<=n;i++){
//		if(arr[i].e!=arr[i-1].e) flag = true;
//	}
//	if(flag){
//		sort(arr+1,arr+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				if(i==j) continue;
//				if(book[i]) continue;
//			}
//		}
//	}
//	else{
		sort(arr+1,arr+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(arr[i].x==arr[i-1].x) ans++;
		}
		cout<<n-ans;
//	}
	return 0;
}
/*
6 5
3 4
2 3
4 2
*/
