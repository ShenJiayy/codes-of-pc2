#include<bits/stdc++.h>
using namespace std;
int l[500005];
bool vis[500005];
struct node{
	int x,e;
}a[500005];
bool cmp(node a,node b){
	return a.e>b.e;
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	int n;
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].e;
		l[i]=a[i].x;
		if(i>=2){
			if(a[i].e!=a[i-1].e){
				flag=false;
			}
		}
	}
	if(flag){
		sort(l+1,l+1+n);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(l[i]!=l[i-1]){
				cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			cnt++;
			vis[i]=true;
			for(int j=i+1;j<=n;j++){
				if(abs(a[i].x-a[j].x)<=a[i].e-a[j].e){
					vis[j]=true;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
