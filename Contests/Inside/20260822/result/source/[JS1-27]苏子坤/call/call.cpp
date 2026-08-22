#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
struct fun{
	int op,p,v;
	vector<int>q;
}f[100005];
int n,m,a[100005],addcs[100005],tag=1;
set<int>st;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		f[i].op=read();
		if(f[i].op==1){
			f[i].p=read(),f[i].v=read();
			st.insert(f[i].p);
		}
		if(f[i].op==2)f[i].v=read();
		if(f[i].op==3){
			int t=read();
			while(t--){
				int tt=read();
				f[i].q.push_back(tt);
			}
		}
	}
	int _=read();
	deque<int>id;
	while(_--){
		int t=read();
		if(f[t].op!=3)id.push_back(t);
		else{
			for(auto i:f[t].q)id.push_back(i);
		}
	}
	while(!id.empty()){
		fun now=f[id.front()];
		id.pop_front();
		if(now.op==1)a[now.p]+=now.v;
		else if(now.op==2){
			tag*=now.v;
			for(auto i:st)a[i]*=now.v;
		}
		else{
			stack<int>cache;
			for(auto i:now.q)cache.push(i);
			while(!cache.empty()){
				id.push_front(cache.top());
				cache.pop();
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!st.count(i))cout<<a[i]*tag<<" ";
		else cout<<a[i]<<" ";
	}
	return 0;
}
