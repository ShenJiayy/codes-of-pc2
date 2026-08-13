//ad
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
struct per{
	int x,e;
}a[N];
bool cmp(per x,per y){
	if(x.x==y.x)return x.e<y.e;
	return x.x<y.x;
}
int in[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].e;
	}
	sort(a+1,a+1+n,cmp);
	int l,r;
	for(int i=1;i<=n;i++){
		l=i-1,r=i+1;
		while(l>=1){
			if(a[i].e-a[l].e>=abs(a[l].x-a[i].x)){
				in[l]++;
				l--;
			}
			else if(a[l].x==a[l-1].x&&l-1>=1)l--;
			else break;
		}
		while(r<=n){
			if(a[i].e-a[r].e>=abs(a[r].x-a[i].x)){
				in[r]++;
				r++;
			}
			else if(a[r].x==a[r+1].x&&l+1<=n)r++;
			else break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(in[i]==0)ans++;
	}
	int j;
	bool flag=0;
	for(int i=1;i<=n;i++){
		j=i+1;
		flag=0;
		int qw=i;
		while(j<=n){
			if(a[qw].x==a[j].x&&a[qw].e==a[j].e){
				flag=1;
				i=j;
				j++;
			}
			else break;
		}
		if(flag)ans++;
	}
	cout<<ans;
	return 0;
} 
