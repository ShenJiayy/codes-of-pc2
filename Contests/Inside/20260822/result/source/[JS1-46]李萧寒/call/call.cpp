#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
inline int read(){
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k*f;
}
int w[400005],lzy[400005],l[100005],a[100005],la[100005],lala[100005],n;
vector<int>v[100005];
int ls(int x){
	return x*2;
}
int rs(int x){
	return x*2+1;
}
void build(int p,int l,int r){
	if(l==r){
		w[p]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
}
void update(int p,int L,int R,int d,int x,int op){
	if(op==2){
		lzy[1]*=x;
		lzy[1]%=mod;
		return;
	}
	if(L==R){
		w[p]*=lzy[p];
		w[p]+=x;
		lzy[p]=1;
		w[p]%=mod;
		return;
	}
	lzy[ls(p)]*=lzy[p];
	lzy[ls(p)]%=mod;
	lzy[rs(p)]*=lzy[p];
	lzy[rs(p)]%=mod;
	lzy[p]=1;
	int mid=(L+R)/2;
	if(d<=mid){
		update(ls(p),L,mid,d,x,op);
	}
	else{
		update(rs(p),mid+1,R,d,x,op);
	}
}
void change(int x){
	if(l[x]==1){
		update(1,1,n,lala[x],la[x],1);
		return;
	}
	if(l[x]==2){
		update(1,1,n,1,la[x],2);
		return;
	}
	for(int i=0;i<la[x];i++){
		change(v[x][i]);
	}
}
void build2(int p,int l,int r){
	if(l==r){
		a[l]=w[p];
        return;
	}
	int mid=(l+r)/2;
	build2(ls(p),l,mid);
	build2(rs(p),mid+1,r);
}
signed main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	for(int i=1;i<=400000;i++){
		lzy[i]=1;
	}
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	build(1,1,n);
	int q=read();
	for(int i=1;i<=q;i++){
		int op=read();
		l[i]=op;
		if(op==1){
			lala[i]=read();
			la[i]=read();
		}
		else if(op==2){
			la[i]=read();
		}
		else{
			la[i]=read();
			for(int j=1;j<=la[i];j++){
				int aa=read();
				v[i].push_back(aa);
			}
		}
	}
	int dd=read();
	while(dd--){
		int sa=read();
		change(sa);
	}
	for(int i=1;i<=n;i++){
		update(1,1,n,i,0,1);
	}
	build2(1,1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
