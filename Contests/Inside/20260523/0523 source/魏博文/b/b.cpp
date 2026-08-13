#include<bits/stdc++.h>
using namespace std;
int a[500001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=a[1],m=n-2;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]&&i+1<=n) continue;
		else if(n-i>=1&&abs(i-n+i)<m){
			m=abs(i+i-n);maxn=a[i];
			//cout<<m<<" ";
		}
	}
	cout<<maxn;
} 
