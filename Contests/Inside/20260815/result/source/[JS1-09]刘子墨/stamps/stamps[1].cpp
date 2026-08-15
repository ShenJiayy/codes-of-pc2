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
const int maxn=205;
nint n,l,x[maxn],t[maxn];
int main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
    n=read();
    l=read();
    for(int i=1;i<=n;i++){
    	x[i]=read();
	}
	for(int i=1;i<=n;i++){
		t[i]=read();
	}
	for(int i=1;i<=n;i++){
		if()
	}
    return 0;
}
