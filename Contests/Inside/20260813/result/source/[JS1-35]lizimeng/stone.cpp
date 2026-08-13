#include<bits/stdc++.h>
using namespace std;
int n,color[200010];
map<int,int> mp;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>color[i];
		mp[color[i]]=i;
	}
//	sort(color+1,color+n+1);
//	int len=unique(color+1,color+n+1)-color-1;
//	for(int i=1;i<=n;i++){
//		c[i]=lower_bound(color+1,color+len+1,c[i])-color;
//	}//li san hua
//	
	for(int i=1;i<=n;i++){
		int lpos=mp[color[i]];
		for(int j=i+1;j<lpos;j++) color[j]=color[i];
		i=lpos;
	}
	for(int i=1;i<=n;i++) cout<<color[i]<<"\n";
	return 0;
}
/*
bu shi ge men
bu ying gai ge yi tian yi chang mo ni sai ma!!!
*/
