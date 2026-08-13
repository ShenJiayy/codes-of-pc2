#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
const int M=5e5+5;
int poi[7];
int n,p;
int x,y,ans=0;
struct st{
	int a[N];
	int t=0;
	void push(int x){
		a[++t]=x;
	}
	int top(){
		return a[t];
	}
	void pop(){
		t--;
	}
	int empty(){
		return t==0?1:0;
	}
}h[7];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
	//	int fl=1;
//	int o=a[x].empty();
//	cout<<1 
			while((!h[x].empty())&&h[x].top()>y){
			ans++;
			h[x].pop();
		    }
	
		if(h[x].top()!=y){
		ans++;
		h[x].push(y);
		}
	//	if(fl)
	
	}
	cout<<ans;
	return 0;
}
