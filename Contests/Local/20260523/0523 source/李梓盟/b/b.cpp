#include<bits/stdc++.h>
using namespace std;
const int maxN=500000;
int n,s[maxN+10],cmin=INT_MAX,ans;

int main(){
	freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		while(s[i+1]==s[i]) i++;
		int le=i,ri=n-i;
		if(abs(le-ri)<cmin) cmin=abs(le-ri),ans=s[i];
	}
	cout<<ans;
	return 0;
}
