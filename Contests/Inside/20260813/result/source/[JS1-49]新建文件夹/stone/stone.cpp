#include <bits/stdc++.h>
using namespace std;
int n,a[600000],b[600000], u[600000];
priority_queue<int>q[600000];
unordered_map<int,int>m;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	int k=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=k;i++)m[b[i]]=i;
	for(int i=1;i<=n;i++)a[i]=m[a[i]];
	for(int i=1;i<=n;i++){
		while(!q[a[i]].empty()&&a[u[q[a[i]].top()] ]!=a[i]&&u[q[a[i]].top()]){
			q[a[i]].pop();
		}
		if(!q[a[i]].empty()){
			for(int j=q[a[i]].top();j<i;j++){
				if(u[j]){
					int p=u[j];
					u[j]=i;
					j=p+1;
					
				}
				u[j]=i;
			}
		}
		q[a[i]].push(i);
		
	}
//	for(int i=1;i<=n;i++)cout<<u[i]<<' ';
	for(int i=1;i<=n;i++){
		if(u[i]){
			int k=u[i];
			while(i<=k){
				cout<<b[a[k]]<<'\n';
				i++;
			}
			i--;
		}
		else{
			cout<<b[a[i]]<<'\n';
		}
	}
	return 0;
}
