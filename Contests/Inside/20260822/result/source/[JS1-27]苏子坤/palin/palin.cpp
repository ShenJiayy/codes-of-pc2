#include<bits/stdc++.h>
using namespace std;
int n,a[1000005];
string ret,flag;
bool check(string s){
	for(int i=0;i<n;i++){
		if(s[i]!=s[2*n-1-i])return 0;
	}
	return 1;
}
string _min(string x,string y){
	for(int i=0;i<x.size();i++){
		if(x[i]=='L'&&y[i]=='R')return x;
		if(x[i]=='R'&&y[i]=='L')return y;
	}
	return x;
}
void dfs(int l,int r,string ans,string choice){
	if(l>r){
		if(check(ans))ret=_min(ret,choice);
		return;
	}
	char L=a[l]+'0',R=a[r]+'0';
	dfs(l+1,r,ans+L,choice+'L');
	dfs(l,r-1,ans+R,choice+'R');
}
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int _=read();
	while(_--){
		ret="",flag="";
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
			ret+='R',flag+='R';
		}
		dfs(1,2*n,"","");
		if(ret==flag)cout<<-1<<endl;
		else cout<<ret<<endl;
	}
	return 0;
}
