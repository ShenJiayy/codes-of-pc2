#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int book[N],ed[N],ans[N],ld[N],nw[N];
int n;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ld[i];
		nw[i]=ld[i];
	}
	sort(ld+1,ld+n+1);
	int cnt=n;
	for(int i=1;i<=n;i++){
		nw[i]=lower_bound(ld+1,unique(ld+1,ld+n+1),nw[i])-ld;
	}
	for(int i=n;i>=1;i--){
		if(book[nw[i]]==0){
			book[nw[i]]=i;
		}else{
			ed[i]=book[nw[i]];
			book[nw[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(ed[i]!=0){
			for(int j=i;j<=ed[i];j++){
				nw[j]=nw[i];
			}i=ed[i]-1;
		}
	}
	for(int i=1;i<=n;i++)cout<<ld[nw[i]]<<"\n";
	return 0;
}
