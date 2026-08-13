#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n,s[N],v[N],cnt,p[N],vis[N];
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	//int k=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
	sort(s+1,s+1+n);
	v[++cnt]=s[1];
	for(int i=2;i<=n;i++){
		if(s[i]!=s[i-1]) v[++cnt]=s[i];
		//cout<<s[i];
	}
	/*for(int i=1;i<=cnt;i++){
		cout<<v[i]<<" "<<i<<" ";
	}*/
	//cout<<"cccc";
	//int k=0;
	for(int i=1;i<=n;i++){
		int l=1,r=cnt;
		while(l<r){
			int mid=(l+r)/2;
			if(v[mid]>a[i]) r=mid-1;
			else if(v[mid]==a[i]){
				l=mid;
				break;
			}
			else l=mid+1;
		}
		vis[l]=i;
	}
	//cout<<vis[2];
	for(int i=1;i<=n;i++){
		int l=1,r=cnt;
		while(l<r){
			int mid=(l+r)/2;
			if(v[mid]>a[i]) r=mid-1;
			else if(v[mid]==a[i]){
				l=mid;
				break;
			}
			else l=mid+1;
		}
		//cout<<l;
		for(int j=i;j<=vis[l];j++) a[j]=a[i];
		i=vis[l];
	}
	/*for(int i=1;i<=n;i++){
		cout<<p[i]<<" ";
	}*/
	for(int i=1;i<=n;i++){
		//p[i]+=p[i-1];
		//if(p[i]!=0) cout<<p[i]<<"\n";
		cout<<a[i]<<"\n";
	}
}
