#include <bits/stdc++.h>
#ifdef __unix__
#define gc getchar_unlocked
#else
#define gc _getchar_nolock
#endif

using namespace std;
using nint=long long;
//using nint=__int128;
static inline __attribute__((always_inline)) nint read(){
    int c=gc();
    nint k=0,f=1;
    for(;!isdigit(c);c=gc()){
        if(c=='-')f=-1;
    }
    for(;isdigit(c);c=gc()){
        k=k*10+(c^48);
    }
    return k*f;
}
inline void print(nint x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

const int maxq=2e5+5;
const int maxn=505;

nint h,w,t,q[maxq],x[maxq],y[maxq],c[maxq],mp[maxn][maxn];
bool vis[maxn][maxn];
int main(){
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout);
    h=read(),w=read(),t=read();
    for(int i=1;i<=t;i++){
    	q[i]=read();
    	x[i]=read();
    	y[i]=read();
    	if(q[i]==1)c[i]=read();
	}
	for(int i=1;i<=t;i++){
		int xi=x[i],yi=y[i],ci=c[i];
		if(q[i]==1){
			if(!vis[xi][yi]&&xi<=h&&yi<=w&&xi>0&&yi>0){
				mp[xi][yi]=ci;
			}
			if(!vis[xi+1][yi]&&xi+1<=h&&yi<=w&&xi+1>0&&yi>0){
				mp[xi+1][yi]=ci;
			}
			if(!vis[xi][yi+1]&&xi<=h&&yi+1<=w&&xi>0&&yi+1>0){
				mp[xi][yi+1]=ci;
			}
			if(!vis[xi+1][yi+1]&&xi+1<=h&&yi+1<=w&&xi+1>0&&yi+1>0){
				mp[xi+1][yi+1]=ci;
			}
		}
		else{
			vis[xi][yi]=vis[xi+1][yi]=vis[xi][yi+1]=vis[xi+1][yi+1]=1;
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			print(mp[i][j]);
			printf(" ");
		}
		printf("\n");
	}
    return 0;
}
