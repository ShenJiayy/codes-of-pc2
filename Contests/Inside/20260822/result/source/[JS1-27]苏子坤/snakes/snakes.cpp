#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,a[1000005],sum[1000005];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int _=read();
	for(int __=1;__<=_;__++){
		sum[0]=0;
		if(__==1){
			n=read();
			for(int i=1;i<=n;i++){
				a[i]=read();
				sum[i]=sum[i-1]+a[i];
			}
		}
		else{
			int ___=read();
			while(___--){
				pair<int,int>change;
				change.first=read(),change.second=read();
				a[change.first]=change.second;
			}
			for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		}
		int ans=n,l=1;
		if(n==3){
			if(a[3]-a[1]>=a[2]){
				if(a[3]>=a[1]+a[2])cout<<1<<'\n';
				else cout<<2<<'\n';
			}
			else cout<<3<<'\n';
			continue;
		}
		for(int i=n;i>=l;i--){
			int t=l;
			while(a[i-1]-sum[i-2]+sum[t]<=a[i]-(sum[t]-sum[l-1])){
				t++;
			}
			ans=n-t+1;
			a[i]-=(sum[t]-sum[l-1]);
			l=t;
		}
		cout<<ans<<endl;
	}
	return 0;
}
