#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
struct node{
	int t,id;
}a[1000005];
int T,n;
bool cmp(node x,node y){
	if(x.t==y.t)return x.id>y.id;
	else return x.t>y.t;
}
int main(){
	freopen("snakes2.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++){
		if(i==1){
			n=read();
			for(int j=1;j<=n;j++){
				a[j].t=read();
				a[j].id=j;
			}
		}
		else{
			int k=read();
			for(int j=1;j<=k;j++){
				int x=read(),y=read();
				a[x].t=y;
			}
		}
		int cnt=1;
		while(1){
			if(cnt+1==n){
				if(a[n].t>=a[cnt].t){
					cnt++;
					a[n].t-=a[cnt].t;
				}
				break;
			}
			else if(a[n].t-a[cnt].t>=a[n-1].t){
				a[n].t-=a[cnt].t;
				cnt++;
			}
			else break;
		}
		cout<<n-cnt+1<<"\n";
	}
	return 0;
}
