#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct kkk{
	int s,id;
}a[N];
int b[N],ans[N],h[N],g[N];
bool cmp(kkk s1,kkk s2){
	return s1.s<s2.s;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(a+1,a+n+2,cmp);
	sort(b+1,b+1+n);
	//cout<<"11111";
	/*for(int i=1;i<=n+1;i++){
		cout<<a[i].s<<" "<<a[i].id<<"kkk";
	}*/
	for(int i=n+1;i>1;i--){
		h[i]=max(h[i+1],a[i].s-b[i-1]);
		//cout<<h[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		g[i]=max(g[i-1],a[i].s-b[i]);
		//cout<<g[i]<<" ";
	}
	/*for(int i=1;i<=n;i++){
		ans[a[1].id]=max(a[i+1].s-b[i],ans[a[1].id]);
	}*/
	//cout<<"ppp";
	for(int i=1;i<=n+1;i++){
		ans[a[i].id]=max(h[i+1],g[i-1]);
	}
	for(int i=1;i<=n+1;i++){
		cout<<ans[i]<<" ";
	}
}
