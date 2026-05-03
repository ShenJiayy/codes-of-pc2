#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
using namespace std;
namespace IO{//这份代码拿来学fread也是很不错的
	const int Buffsize=1<<23;
	char c[Buffsize],*ch=c;
	void INIT(){fread(c,1,Buffsize,stdin);}
	int x,l;
	int read(){
		x=0,l=1;
		while(!isdigit(*ch)) {if ((*ch)=='-') l=-1; ch++;}
		while(isdigit(*ch)) x=x*10+(*ch^48),ch++;
		return x*l;
	}
}
using namespace IO;
priority_queue<int> q;
int a[805],b[805];
int main(){
	INIT(); int n=read(),m=read(),k=read(),o,oo;
	q.push(0); int op=800,ans=0;
	while(n--){
		For(j,1,m) a[j]=read(); sort(a+1,a+1+m);
		o=oo=0; while(!q.empty()) b[++o]=q.top(),q.pop();
		For(i,1,m)
			for(int j=o;j>=1;--j){//在这里b数组单调不升,所以倒着来
				if (oo<k) q.push(a[i]+b[j]),++oo;
				else if (q.top()<=a[i]+b[j]) break; //关键优化
				else q.pop(),q.push(a[i]+b[j]);
			}
	}
	o=0;
	while(!q.empty()) b[++o]=q.top(),q.pop();
	for(int i=o;i>=1;--i) printf("%d ",b[i]);
	return 0;
}
