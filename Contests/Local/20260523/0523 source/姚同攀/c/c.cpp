#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,a[N];
ll ans;
ll f[N][5];
bool T3(){
	for(int i=1;i<=n;++i) if(a[i]%3) return false;
	return true;
}
bool T4(){
	for(int i=1;i<=n;++i) if(a[i]!=2) return false;
	return true;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(n==1){
		printf("%d",a[1]/3);
		return 0;
	}
	if(T3()){		//三的倍数 
		for(int i=1;i<=n;++i) ans+=a[i]/3;
		printf("%lld",ans);
		return 0;
	}
	if(T4()){		//全是2 
		printf("%d",n*2/3);
		return 0;
	}
	printf("0");
//	for(int i=1;i<=n;++i){
//		for(int j=0;j<5;++j){
//			int s=a[i]-j;
//			if(s>0){
//				if(i>1) f[i][j]=max(f[i][j],f[i-1][2]+1+(s-1)/3);	//2+1
//				if(i>2) f[i][j]=max(f[i][j],f[i-2][1]+f[1+1+(s-1)/3);	//1+1+1
//			}
//			if(s>1){
//				if(i>1){
//					f[i][j]=max(f[i][j],f[i-1][1]+1+(s-2)/3);
//					f[i][j]=max
//				}
//			}
//		}
//	}
	return 0;
} 
