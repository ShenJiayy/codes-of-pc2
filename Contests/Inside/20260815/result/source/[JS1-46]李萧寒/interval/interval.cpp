#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,len;
}x[500005];
bool cmp(node a,node b){
	return a.len<b.len;
}
int cnt[1000005],d[100005],alllen[500005];
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i].l>>x[i].r;
		cnt[i*2]=x[i].r;
		cnt[i*2-1]=x[i].l;
		x[i].len=x[i].r-x[i].l+1;
	}
	sort(x+1,x+1+n,cmp);
	sort(cnt+1,cnt+1+2*n);
	int mi=INT_MAX;
	if(n<=2000){
		for(int i=1;i<=2*n;i++){
			int c=0;
			for(int j=1;j<=n;j++){
				if(x[j].l<=cnt[i]&&cnt[i]<=x[j].r){
					alllen[++c]=x[j].len;
				}
			}
			if(c>=m){
				for(int j=1;j+m-1<=c;j++){
					mi=min(alllen[j+m-1]-alllen[j],mi);
				}
			}
		}
		if(mi==INT_MAX){
			cout<<-1;
			return 0;
		}
		cout<<mi;
		return 0;
	}
	for(int i=1;i<=n;i++){
		d[x[i].r+1]--;
		d[x[i].l]++;
	}
	for(int i=1;i<=100000;i++){
		d[i]+=d[i-1];
	}
	for(int i=1;i<=100000;i++){
		if(d[i]==n){
			for(int i=1;i+m-1<=n;i++){
				mi=min(mi,x[i+m-1].len-x[i].len);
			}
			cout<<mi;
			return 0;
		}
	}
	if(2*n<=100000){
		for(int i=1;i<=2*n;i++){
			if(d[cnt[i]]<m){
				continue;
			}
			int c=0;
			for(int j=1;j<=n;j++){
				if(x[j].l<=cnt[i]&&cnt[i]<=x[j].r){
					alllen[++c]=x[j].len;
				}
			}
			if(c>=m){
				for(int j=1;j+m-1<=c;j++){
					mi=min(alllen[j+m-1]-alllen[j],mi);
				}
			}
		}
		if(mi==INT_MAX){
			cout<<-1;
			return 0;
		}
		cout<<mi;
		return 0;
	}
	for(int i=1;i<=100000;i++){
		if(d[i]<m){
			continue;
		}
		int c=0;
		for(int j=1;j<=n;j++){
			if(x[j].l<=i&&i<=x[j].r){
				alllen[++c]=x[j].len;
			}
		}
		for(int j=1;j+m-1<=c;j++){
			mi=min(alllen[j+m-1]-alllen[j],mi);
		}
	}
	if(mi==INT_MAX){
		cout<<-1;
		return 0;
	}
	cout<<mi;
	return 0;
}
