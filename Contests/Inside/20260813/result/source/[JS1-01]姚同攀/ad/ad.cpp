#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
int lsh[N<<1]={-2147483647},tot;
int rk(int x){
	return lower_bound(lsh+1,lsh+tot+1,x)-lsh;
}
struct P{ int x,v;} p[N];
bool cmp(P a,P b){
	return a.x<b.x;
}
struct BIT{
	int d[N<<1];
	int lb(int x){ return x&-x;}
	void upd(int o,int x){
		while(o<N*2){
			d[o]+=x;
			o+=lb(o);
		}
	}
	int que(int o){
		int res=0;
		while(o){
			res+=d[o];
			o-=lb(o);
		}
		return res;
	}
}l,r;
int flg1=1;
void sub1(){
	int res=0;
	for(int i=1;i<=n;++i)
		if(p[i].x>p[i-1].x)
			++res;
	printf("%d",res);
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int x,v;
		scanf("%d%d",&x,&v);
		p[i]={x,v};
		lsh[i]=x-v;
		lsh[i+n]=x+v;
		if(i>1&&p[i].v!=p[i-1].v) flg1=0;
	}
	sort(lsh+1,lsh+n+n+1);
	sort(p+1,p+n+1,cmp);
	if(flg1){
		sub1();
		return 0;
	}
	return 0;
} 
