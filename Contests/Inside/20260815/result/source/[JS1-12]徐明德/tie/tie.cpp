//tie
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
int a[N],b[N],qwq[N];
int cha1[N],cha2[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
		qwq[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	sort(a+1,a+n+2);
	for(int i=1;i<=n;i++){
		cha1[i]=max(max(cha1[i-1],cha1[i]),a[i]-b[i]);
	}
	for(int i=n;i>=1;i--){
		cha2[i]=max(max(cha2[i+1],cha2[i]),a[i+1]-b[i]);
	}
	int pos;
	for(int i=1;i<=n+1;i++){
		pos=lower_bound(a+1,a+n+2,qwq[i])-a;
		cout<<max(cha1[pos-1],cha2[pos])<<" ";
	}
	return 0;
} 
