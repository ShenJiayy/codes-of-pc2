// stone
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
int n,len;
int a[MAXN],ans[MAXN];
int lst[MAXN],val[MAXN],id[MAXN];
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		val[i]=a[i];
	}
	sort(val+1,val+n+1);
	len=unique(val+1,val+n+1)-(val+1);
	for(int i=1;i<=n;i++)
	id[i]=lower_bound(val+1,val+len+1,a[i])-val;
	for(int i=1;i<=n;i++) lst[id[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=lst[id[i]];j++) ans[j]=a[i];
		i=lst[id[i]];
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}
