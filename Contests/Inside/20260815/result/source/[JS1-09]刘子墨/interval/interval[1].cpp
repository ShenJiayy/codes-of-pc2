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
const int maxn=5e5+5;
struct node{
	int l,r,ln;
}q[maxn];
bool cmp(node a,node b){
	if(a.l!=b.l)return a.l<b.l;
	return a.r<b.r;
}
bool cmp2(node a,node b){
	return a.ln<b.ln;
}

nint n,m,l[maxn],r[maxn],ln[maxn],ans[maxn],t,s=maxn;
int main(){
	freopen("interval.in","r",stdin);
	freopen("interval.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
    	q[i].l=read();q[i].r=read();
    	q[i].ln=q[i].r-q[i].l;
	}
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++){
		int xm=q[i].r;
		for(int j=1;j<=n;j++)ans[j]=0;
		t=0;
		for(int j=i+1;j<=n;j++){
			if(q[j].l<=xm&&q[j].r>=xm){
				ans[++t]=q[j].ln;
			}
		}
		sort(ans+1,ans+t+1);
		if(t<m)ans[m]=maxn;
		s=min(ans[m]-ans[1]-1,s);
	}
	if(s=maxn){
		cout<<-1;
		return 0;
	}
	print(s);
    return 0;
}
