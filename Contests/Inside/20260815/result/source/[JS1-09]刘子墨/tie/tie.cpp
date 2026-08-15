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

const int maxn=2e5+10;
struct node{
	nint v,id,s;
}a[maxn];
static inline __attribute__((always_inline)) bool cmp1(node a,node b){
	return a.v>b.v;
}
static inline __attribute__((always_inline)) bool cmp2(nint a,nint b){
	return a>b;
}
nint n,b[maxn],mx=-1,f[maxn];
int main(){
    freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	n=read();
	for(int i=1;i<=n+1;i++)a[i]=(node){read(),i};
	for(int i=1;i<=n;i++)b[i]=read();
	sort(a+1,a+n+2,cmp1);
	for(int i=1;i<=k;i++){
		cout<<a[i].v-b[i];
	}
    return 0;
}
