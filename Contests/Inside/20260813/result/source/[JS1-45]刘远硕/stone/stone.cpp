#include<bits/stdc++.h>
using namespace std;
int n,a[200010],b[200010],cc[200030],ccc[200030];
vector<int> c[2005];
map<int,int> mp;
void sv1 (){
	for (int i=0;i<=n;i++)
		for (int j=1;j<=n;j++)
			c[i].push_back(0);
	for (int i=1;i<=n;i++) {
		c[i]=c[i-1];
		if (c[i][a[i]]) {
			for (int j=c[i][a[i]];j<i;j++) a[j]=a[i];
			c[i]=c[c[i][a[i]]];
		}
		c[i][a[i]]=i;
	}
	for (int i=1;i<=n;i++) cout<<b[a[i]]<<"\n";
}

void sv2(){
	for (int i=n;i>=1;i--){
		cc[i]=ccc[a[i]];
		ccc[a[i]]=i;
	}
	int i=1;
	cout<<b[a[1]]<<"\n";
	while(i<n){
		int ccccc=b[a[i]],cccccc=cc[i];
		for (i++;i<cccccc && i<=n;i++) cout<<ccccc<<"\n";
		cout<<b[a[i]]<<"\n";
	}
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	int mx=-1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		b[i]=a[i];
		mx=max(mx,a[i]);
	}
	sort(b+1,b+1+n);
	int len=unique(b+1,b+1+n)-b;
	for (int i=1;i<=len;i++) mp[b[i]]=i;
	for (int i=1;i<=n;i++) a[i]=mp[a[i]];
	if (n<=2000) sv1();
	else sv2();
	
	
	return 0;
}
