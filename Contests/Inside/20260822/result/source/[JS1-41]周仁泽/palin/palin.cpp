// palin
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+7;
int T,n,m,a[MAXN];
int b[MAXN];
bool t[MAXN];
char ch[MAXN];
string ans="-1";
string Min(string s1,string s2){
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='L'&&s2[i]=='R') return s1;
		else if(s1[i]=='R'&&s2[i]=='L') return s2;
	}
	return s1;
}
void dfs(int x,int l,int r){
	if(x>n){
		string s;
		for(int i=1;i<=n;i++) s.push_back(ch[i]);
		if(ans=="-1") ans=s;
		else ans=Min(ans,s);
		return;
	}
	else if(x>m){
		int now=b[n-x+1];
		if(a[l]==now){
			b[x]=a[l];
			ch[x]='L';
			dfs(x+1,l+1,r);
			b[x]=0;
			ch[x]='\0'; 
		}
		if(a[r]==now){
			b[x]=a[r];
			ch[x]='R';
			dfs(x+1,l,r-1);
			b[x]=0;
			ch[x]='\0';
		}
	}
	else{
		if(t[a[l]]==0){
			b[x]=a[l];
			ch[x]='L';
			t[a[l]]=1;
			dfs(x+1,l+1,r);
			b[x]=0;
			ch[x]='\0';
			t[a[l]]=0;
		}
		if(t[a[r]]==0){
			b[x]=a[r];
			ch[x]='R';
			t[a[r]]=1;
			dfs(x+1,l,r-1);
			b[x]=0;
			ch[x]='\0';
			t[a[r]]=0;
		}
	}
	return;
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--){
		ans="-1";
		memset(b,0,sizeof(b));
		memset(t,0,sizeof(t));
		for(int i=0;i<MAXN;i++) ch[i]='\0';
		cin>>m;
		n=2*m;
		for(int i=1;i<=n;i++) cin>>a[i];
		dfs(1,1,n);
		cout<<ans<<endl;
	}
	return 0;
}
