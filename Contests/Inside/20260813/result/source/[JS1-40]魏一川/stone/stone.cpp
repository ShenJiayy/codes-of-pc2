#include<bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005],l[200005];
struct node{
	int color,left,right;
};
vector<node>v;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int cnt=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+cnt+1,a[i])-b;
	for(int i=1;i<=n;i++){
		v.push_back({a[i],l[a[i]],i});
		l[a[i]]=i;
	}
	for(int i=0;i<v.size();i++){
		if(v[i].color!=a[v[i].left]||v[i].color!=a[v[i].right])continue;
		for(int j=v[i].left;j<=v[i].right;j++)a[j]=v[i].color;
	}
	for(int i=1;i<=n;i++)cout<<b[a[i]]<<"\n";
	return 0;
}
