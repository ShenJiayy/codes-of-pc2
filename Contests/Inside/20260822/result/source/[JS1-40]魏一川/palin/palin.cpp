#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000005];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main(){
	freopen("palin2.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n*2;i++)a[i]=read();
		bool fl=0;
		string ans="";
		for(int i=1;i<=n*2;i++)ans+="R";
		for(int mask=0;mask<1<<(n*2);mask++){
			int l=1,r=n*2,b[n*2+5];
			string s="";
			for(int i=0;i<n*2;i++){
				if(mask&(1<<i)){
					b[i+1]=a[r];
					r--;
					s+="R";
				}
				else{
					b[i+1]=a[l];
					l++;
					s+="L";
				}
			}
			bool ok=1;
			for(int i=1;i<=n;i++){
				if(b[i]!=b[n*2+1-i]){
					ok=0;
					break;
				}
			}
			if(ok){
				fl=1;
				ans=min(ans,s);
			}
		}
		if(fl)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
