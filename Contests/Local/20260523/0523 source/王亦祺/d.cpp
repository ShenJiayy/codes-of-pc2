#include<iostream>
#include<algorithm>
#include<fstream>
#define int long long
using namespace std;

inline int read(){
	int num=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		num=num*10+(int)ch-48;
		ch=getchar();
	}
	return num*sign;
}

int L,R,MID,n,q,cst,dwn,arr[300005],sum[300005]={};

inline int getcost(int x){
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)/2;
		if(arr[mid]<x*dwn) l=mid+1;
		else r=mid;
	}
	return max(sum[l]-dwn*x*(n-l+1),0ll);
}

signed main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++) arr[i]=read();
	sort(&arr[1],&arr[n+1]);
	for(int i=n;i>=1;i--) sum[i]=sum[i+1]+arr[i];
	for(int i=1;i<=q;i++){
		cst=read();
		dwn=read();
		L=0,R=arr[n]/dwn+1,MID;
		while(L<R){
			MID=(L+R)/2+1;
			if(getcost(MID-1)-getcost(MID)<cst) R=MID-1;
			else L=MID;
		}
		cout<<getcost(L)+cst*L<<"\n";
	}
	return 0;
}
