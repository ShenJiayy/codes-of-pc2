#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN],ed[MAXN],hd[MAXN];
bool t[MAXN];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int tot=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;i++) b[i]=lower_bound(a+1,a+tot+1,b[i])-a;
	for(int i=1;i<=n;i++){
		int x=b[i];
		if(ed[x]==0||t[ed[x]]) ed[x]=i;
		else if(!t[ed[x]]){
			hd[x]=i;
			for(int j=ed[x]+1;j<hd[x];j++){
				if(t[j]) break;
				t[j]=true;
			}
			for(int j=hd[x]-1;j>ed[x];j--){
				if(t[j]) break;
				t[j]=true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(hd[b[i]]>i&&ed[b[i]]==i&&!t[i]){
			int x=b[i];
			for(;i<=hd[x];i++) printf("%d\n",a[x]);
			i--;
		}
		else printf("%d\n",a[b[i]]);
	}
	return 0;
}
