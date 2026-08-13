#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[300010],qzh[300010];
int query(int l,int r){
	return qzh[r]-qzh[l-1];
}
int check(int x){
	if(x<0){
		x=0;
	}
	if(x>=a[n]){
		return 0;
	}
	int L=0,R=n,ef=0;
	while(L<=R){
		int mid=(L+R)/2;
		if(a[mid]<=x){
			ef=mid;
			L=mid+1;
		}
		else{
			R=mid-1;
		}
	}
	if(ef>=n){
		return 0;
	}
	ef++;
//	printf(">>%lld %lld\n",x,query(ef,n)-(n-ef+1)*x);
	return query(ef,n)-(n-ef+1)*x;
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	int x;
	for(int i=1;i<=q;i++){
		int hq,yh;
		scanf("%lld%lld",&hq,&yh);
		if(check(yh)+hq>qzh[n]){
			printf("%lld\n",qzh[n]);
			continue;
		}
		int L=1,R=a[n]/yh+100,ans=0;
		while(L<=R){
			int mid=(L+R)/2;
//			printf("%lld %lld %lld %lld\n",L,R,mid,check(mid*yh)+hq<check((mid-1)*yh));
			if(check(mid*yh)+hq<check((mid-1)*yh)){
//				printf("*");
				ans=mid;
				L=mid+1;
			}
			else{
				R=mid-1;
			}
		}
		printf("%lld\n",check(ans*yh)+hq*ans);
	}
	return 0;
}
