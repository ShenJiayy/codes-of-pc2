#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
using namespace std;
int n,a[500010],b[500010],num[500010],la[500010];
map<int,int> id;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=a[i];
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++) id[num[i]]=i;
	for(int i=1;i<=n;i++) a[i]=id[a[i]];
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(b[i-1]) la[i]=i-1;
		else la[i]=la[i-1];
	}
	//for(int i=1;i<=n;i++){
	//	cout<<b[i]<<" ";
	//}
	int cnt=0;
	for(int i=n;i>=1;i--){
		cnt+=b[i];
		int c=cnt+b[la[i]];
		if(abs(2*c-n)>=abs(2*cnt-n)){
			cout<<num[i];
			I AK IOI;
		}
	}
	I AK IOI;
}
//100 
