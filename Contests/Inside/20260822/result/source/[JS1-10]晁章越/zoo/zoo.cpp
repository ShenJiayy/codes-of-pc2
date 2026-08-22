#include<bits/stdc++.h>
#define int __int128
using namespace std;
inline int in(){
	char c=getchar();
	int f=1,k=0;
	for(;!isdigit(c);c=getchar()) f=(c=='-')?-1:1;
	for(;isdigit(c);c=getchar()) k=10*k+c-'0';
	return f*k;
}
inline void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else out(x/10),putchar(x%10+'0');
	return;
}
constexpr int N=1e6+10;
int n,m,c,k,cnt,p,q,a[N];
bool cani[N];
signed main(){
    freopen("zoo1.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=in(),m=in(),c=in(),k=in();
    for(int i=1;i<=n;i++) a[i]=in();
    for(int i=1;i<=m;i++) p=in(),q=in(),cani[p]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++)
            if(a[i]&(1<<j)) cani[j]=0;
    for(int i=0;i<k;i++) cnt+=(!(bool)cani[i]);
    out((1<<cnt)-n);
	return 0;
}
