#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1;
int n,cnt,q,x,y,k,a[N],blk[N],L[N],R[N],lz[N],len;
void build(int n){
    len=sqrt(n);
    cnt=(n+len-1)/len;
    for(int i=1;i<=cnt;i++){
        L[i]=(i-1)*len+1;
        R[i]=i*len;
    }
    R[cnt]=n;
    for(int i=1;i<=n;i++) blk[i]=(i-1)/len+1;
    memset(lz,-1,sizeof lz);
}
void upd(int x){
	if(lz[x]==-1) return;
	for(int i=L[x];i<=R[x];i++) a[i]=lz[x];
	lz[x]=-1;
}
int qsum(int x,int y,int k){
	int ans=0;
	if(blk[x]==blk[y]){
		upd(blk[x]);
		for(int i=x;i<=y;i++){
			if(a[i]!=k) a[i]=k;
			else ans++;
		}
		return ans;
	}
	upd(blk[x]);
	for(int i=x;i<=R[blk[x]];i++){
		if(a[i]!=k) a[i]=k;
		else ans++;
	}
	upd(blk[y]);
	for(int i=L[blk[y]];i<=y;i++){
		if(a[i]!=k) a[i]=k;
		else ans++;
	}
	for(int i=blk[x]+1;i<blk[y];i++){
		if(lz[i]!=-1){
			if(lz[i]!=k) lz[i]=k;
			else ans+=len;
		}
		else{
			for(int j=L[i];j<=R[i];j++){
				if(a[j]!=k) a[j]=k;
				else ans++;
			}
			lz[i]=k;
		}
	}
	return ans;
}
signed main(){
    cin>>n;
    q=n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(n);
    while(q--){
        cin>>x>>y>>k;
        cout<<qsum(x,y,k)<<endl;
    }
}
