#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5;
int n,s[maxN+10],tot;
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i];
    if(n==0) cout<<n;
	if(n==1) cout<<s[1]/3;
	if(n==2) cout<<(s[1]+s[2])/3;
	int flag=1,flag2=1;
	for(int i=1;i<=n;i++){
		if(s[i]!=2) flag=0;
		if(s[i]%3!=0) flag2=0;
		tot+=s[i];
	}
	if(flag) cout<<n/2*2;
	else if(flag2) cout<<tot/3;
    return 0;
}

