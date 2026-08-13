#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
struct hyoli{
	int x,e,val1,val2;
}a[MAXN];
int n,ans;
stack <hyoli> q;
bool f(hyoli xx,hyoli yy){
	return xx.x<yy.x;
}
int main(){
	freopen("ad.in","r",stdin);
	freopen("ad.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].e);
		a[i].val1=a[i].e-a[i].x;
		a[i].val2=a[i].e+a[i].x;
	}
	sort(a+1,a+n+1,f);
	for(int i=1;i<=n;i++){
		if(!q.empty()){
			if(a[i].val1<=q.top().val1&&a[i].val2<=q.top().val2) continue;
			while(!q.empty()&&a[i].val1>=q.top().val1&&a[i].val2>=q.top().val2) q.pop();
			q.push(a[i]);
		}
		else q.push(a[i]);
	}
	while(!q.empty()){
		ans++;
		q.pop();
	}
	printf("%d",ans);
	return 0;
}
