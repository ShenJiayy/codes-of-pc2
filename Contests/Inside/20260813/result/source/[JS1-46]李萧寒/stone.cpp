#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,id;
}a[200005];
bool cmp(node a,node b){
	return a.c<b.c;
}
int d[200005],cnt[200005],change[200005],s[200005];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c;
		d[i]=a[i].c;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		cnt[i]=cnt[i-1];
		if(a[i].c!=a[i-1].c){
			cnt[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(a[mid].c>d[i]){
				r=mid-1;
			}
			else{
				l=mid;
			}
		}
		change[cnt[l]]=d[i];
		d[i]=cnt[l];
	}
	for(int i=n;i>=1;i--){
		if(s[d[i]]==0){
			s[d[i]]=i;
		}
	}
	for(int i=1;i<=n;){
		int l=i;
		for(;i<=s[d[l]];i++){
			cout<<change[d[l]]<<endl;
		}
	}
	return 0;
}
