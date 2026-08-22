#include <bits/stdc++.h>
using namespace std;
inline int read() { int x=0,f=1;char ch=getchar(); while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();} while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();} return x*f;}
void print(int x){if(x<0){putchar('-');x=-x;}if(x>9)print(x/10);putchar(x%10+'0');}
int t,n,a[1000010],val[500010];
bool dfs(string s,int l,int r,string s2){
	int len=s.size();
	if(len==2*n){
		cout<<s<<endl;
		return 1;
	}
	else if(len>=n){
		int x=n-len+n-1;
		if(a[l]==s2[x]-'0'&&dfs(s+'L',l+1,r,s2+char(a[l]+'0'))) return 1;
        if(a[r]==s2[x]-'0'&&dfs(s+'R',l,r-1,s2+char(a[r]+'0'))) return 1;
		return 0;
	}
	else{
		if(!val[a[l]]){
			val[a[l]]=1;
			if(dfs(s+'L',l+1,r,s2+char(a[l]+'0'))) return 1;
			val[a[l]]=0;
		}
		if(!val[a[r]]){
			val[a[r]]=1;
			if(dfs(s+'R',l,r-1,s2+char(a[r]+'0'))) return 1;
			val[a[r]]=0;
		}
		return 0;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		memset(val,0,sizeof val);
		for(int i=1;i<=n*2;++i) a[i]=read();
		if(!dfs("",1,n*2,"")) cout<<"-1\n";
	}
	return 0;
}

