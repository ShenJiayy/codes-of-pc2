#include<bits/stdc++.h>
using namespace std;
int n,x[500010],e[500010];
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>e[i];
	}
	sort(x+1,x+1+n);
	int tot=unique(x+1,x+1+n)-(x+1);
	cout<<tot<<'\n';
	return 0;
}
