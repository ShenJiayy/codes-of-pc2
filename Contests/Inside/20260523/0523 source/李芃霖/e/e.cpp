#include<bits/stdc++.h>
using namespace std;
#define LLM INT_MAX
#define set_it set<int>::iterator
const int N=6e5+5;
template<class T>
inline T read(){
	T x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar(); 
	}
	return x;
}
template<class T>
inline void write(T x){
	if(x<10){putchar(x+'0');return ;}
	write(x/10);
	putchar(x%10+'0');
	return ;
}
int fa[N],n,m;
set<int> st[N];
int get(int x){
	if(fa[x]==x) return x;
	else return fa[x]=get(fa[x]);
}
void join(int x,int y){
	x=get(x);y=get(y);
	if(x==y) return ;
	if(st[x].size()>st[y].size()) swap(x,y);
	fa[x]=y;
	for(set_it it=st[x].begin();it!=st[x].end();++it){
		st[y].insert(*it);
	}
	st[x].clear();
	return ;
}
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	n=read<int>();
	m=read<int>();
	for(int i=1;i<=2*n;i++){st[i].insert((i+1)/2);fa[i]=i;}
	for(int i=1;i<=m;i++){
		int x,y;
		x=read<int>();
		y=read<int>();
		join(x*2-1,y*2);
	}
	for(int i=1;i<=n;i++){
		write<int>(n-st[get(2*i-1)].size());
		putchar('\n');
	}
	return 0;
}
