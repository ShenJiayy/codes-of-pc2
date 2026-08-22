#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int had[66];
signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k,s=0;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		s|=a;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		had[a]=1;
	}
	int cnt=0;
	for(int i=0;i<k;i++){
		if(had[i]){
			if((s>>i)&1){
				cnt++;
			}
		}
		else{
			cnt++;
		}
	}
	cout<<(1<<cnt)-n;
	return 0;
}
