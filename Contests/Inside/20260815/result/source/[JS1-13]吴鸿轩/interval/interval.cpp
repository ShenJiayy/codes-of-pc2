#include<bits/stdc++.h>
using namespace std;
int n,m,maxx=-1,minn=2147483647,maxx1=-1,min1=2147483647;
struct node{
	int l;
	int r;
	int num;
}a[500010];
int g[100010][2010],b[100010];
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		maxx=max(maxx,a[i].r);
		a[i].num=a[i].r-a[i].l;
		for(int j=a[i].l;j<=a[i].r;j++){
			b[j]++;
			g[j][b[j]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[i];j++){
			cout<<g[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<=maxx;i++){
		maxx1=-1,min1=2147483647;
		if(b[i]>=m){
			for(int j=1;j<=b[j];j++){
				maxx1=max(maxx1,a[g[i][j]].num);
				min1=min(min1,a[g[i][j]].num);
			}
			minn=min(maxx1-min1,minn);
		}
	}
	cout<<minn<<endl;
	return 0;
}
