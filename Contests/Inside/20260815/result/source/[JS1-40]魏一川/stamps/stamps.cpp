#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,t;
}a[205];
int n,l,ans;
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].t);
	int p[n+1];
	for(int i=0;i<=n;i++)p[i]=i;
	do{
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			node now=a[p[i]];
			int b=a[p[i-1]].x,c=now.x,d;
			if(b>c)d=b-c;
			else d=c-b;
			if(now.t-sum>=d)cnt++;
			sum+=now.t;
		}
		ans=max(ans,cnt);
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}
