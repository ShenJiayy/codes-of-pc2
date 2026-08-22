#include<bits/stdc++.h>
using namespace std;
int n,b[25],a[45],v[25],vis[25],T;
string ans="Z";
void dfs(int k){
	if(k==n+1){
		int l=0,r=2*n+1,cnt=0;
		string s="";
		for(int i=1;i<=n;i++){
			if(b[i]==1){
				l++;
				v[++cnt]=a[l];
				s+='L';
			}
			else{
				r--;
				v[++cnt]=a[r];
				s+='R';
			}
		}
		r--;l++;
		for(int i=1;i<=n;i++){
			int flag=0;
			if(a[l]==v[cnt]){
				cnt--;
				l++;
				flag=1;
				s+='L';
			}
			else if(a[r]==v[cnt]){
				r--;
				flag=1;
				s+='R';
				cnt--;
			}
			if(flag==0) return;
		}
		if(s<ans) ans=s;
		return;
	}
	b[k]=1;
	dfs(k+1);
	b[k]=0;
	b[k]=0;
	dfs(k+1);
	b[k]=0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){	
		cin>>n;	
		for(int i=1;i<=2*n;i++) cin>>a[i];
		if(n>20){
			int flag=1;
			for(int i=1;i<=n;i++){
				if(a[i]!=a[2*n-i+1]) flag=0;
			}
			if(flag==1){
				for(int i=1;i<=n*2;i++) cout<<"L"; 
				cout<<endl;
			}
			else cout<<-1<<endl;
			continue;
		}
		memset(b,0,sizeof(b));
		ans="Z";
	
		dfs(1);
		if(ans=="Z") cout<<-1<<'\n';
		else cout<<ans<<'\n';
	}
	return 0;
}
