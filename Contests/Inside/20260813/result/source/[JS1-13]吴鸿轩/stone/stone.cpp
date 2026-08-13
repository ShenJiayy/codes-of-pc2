#include<bits/stdc++.h>
using namespace std;
int n,a[200010],x;
struct node{
	int sum;
}t[800010];
void pushup(int p){
	if((t[p<<1].sum==t[p<<1|1].sum)&&t[p<<1].sum!=0){
		t[p].sum=t[p<<1].sum;
	}else{
		t[p].sum=0;
	}
}
void pushdown(int p,int l,int r){
	if(t[p].sum==0){
		return;
	}
	t[p<<1].sum=t[p].sum;
	t[p<<1|1].sum=t[p].sum;
	t[p].sum=0;
}
int cha(int p,int l,int r,int x){
	if(t[p].sum==x){
		return r;
	}
	if(l==r){
		return -1;
	}
	int mid=(l+r)>>1;
	int ans;
	ans=cha(p<<1|1,mid+1,r,x);
	if(ans==-1){
		ans=cha(p<<1,l,mid,x);
	}
	return ans;
}
int cha2(int p,int l,int r,int x){
	if(l==r){
		return t[p].sum;
	}
	int mid=(l+r)/2;
	if(x<=mid){
		cha2(p<<1,l,mid,x);
	}else{
		cha2(p<<1|1,mid+1,r,x);
	}
}
void gai(int p,int l,int r,int k,int x){
	if(l==r){
		t[p].sum=x;
		return;
	}
	pushdown(p,l,r);
	int mid=(l+r)>>1;
	if(k<=mid){
		gai(p<<1,l,mid,k,x);
	}else{
		gai(p<<1|1,mid+1,r,k,x);
	}
	pushup(p);
}
void gai2(int p,int l,int r,int x,int y,int k){

	if(l>=x&&r<=y){
		t[p].sum=k;
		//cout<<t[p].sum<<'\n';
		pushup(p>>1);
		return;
	}
	
	pushdown(p,l,r);
	int mid=(l+r)>>1;
	if(y<=mid){
		gai2(p<<1,l,mid,x,y,k);
	}else if(x>mid){
		gai2(p<<1|1,mid+1,r,x,y,k);
	}else{
		gai2(p<<1,l,mid,x,y,k);
		gai2(p<<1|1,mid+1,r,x,y,k);
	}
	pushup(p);
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		int cnt=cha(1,1,n,x);
		//cout<<cnt<<endl;
		if(cnt!=-1){
			//cout<<1<<'\n';
			gai2(1,1,n,cnt+1,i-1,x);
			//cout<<1<<'\n';
		}
		gai(1,1,n,i,x);
	}
	for(int i=1;i<=n;i++){
		cout<<cha2(1,1,n,i)<<'\n';
	}
	return 0;
}
