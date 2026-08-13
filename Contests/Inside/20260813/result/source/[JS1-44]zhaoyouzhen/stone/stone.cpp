#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
bool fl=1;
void v1(){
	if(a[1]==1){
		int i=n;
		while(a[i]!=1) i--;
		for(int j=1;j<=i;++j){
			cout<<1<<endl;
		}
		for(int j=i+1;j<=n;++j){
			cout<<2<<endl;
		}
	}
	else{
		int i=n;
		while(a[i]!=2) i--;
		for(int j=1;j<=i;++j){
			cout<<2<<endl;
		}
		for(int j=i+1;j<=n;++j){
			cout<<1<<endl;
		}
	}
}
void v2(){
	for(int i=1;i<=n;++i){
		int j=n;
		while(a[j]!=a[i]) j--;
		for(int k=i;k<=j;++k) cout<<a[i]<<endl;
		i=j;
	}
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>2) fl=0;
 	}
 	if(fl) v1();
 	else v2();
	return 0;
}
