#include<bits/stdc++.h>
using namespace std;
const int maxN=3e5;
int n,q,go[maxN+10];
int d[maxN+10],c[maxN+10];
int main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>go[i];
	for(int i=1;i<=q;i++) cin>>d[i]>>c[i]; 
	if(n==1){
		for(int i=1;i<=q;i++){
			int tot=go[1];
			int n1=ceil(tot*1.0/c[i])*d[i];
			int n2=(tot/c[i])*d[i]+tot%c[i];
			if(d[i]>=c[i]) cout<<tot;
			else cout<<min(n1,n2);
			cout<<endl;
		}
	}
	else{
		unsigned long long ans;
		for(int j=1;j<=n;j++) ans+=go[j];
		for(int i=1;i<=q;i++){
			cout<<ans<<endl;
		}
		
	}
    return 0;
}

