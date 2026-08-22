//zoo 
#include<bits/stdc++.h>
using namespace std;
#define ull __int128
const int N=1e6+10;
int n,m,C,k;
ull a[N],sum,all;
vector<int>c[100];
map<int,int>mp; 
__int128 ans=1;
void opt(__int128 x){
	stack<int>st;
	while(x){
		st.push(x%10);
		x/=10;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
}
__int128 read(){
	__int128 x=0;
	string ss;
	cin>>ss;
	int wei=ss.size();
	for(int i=0;i<wei;i++){
		x*=10;
		x+=ss[i]-'0';
	}
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>C>>k;
	for(int i=1;i<=n;i++){
		a[i]=read();
		all|=a[i];
	}
	sum=all;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		c[x].push_back(y);//第x位要买饲料y 
	}
	int cnt=0;
	while(sum>0){
		if(sum&1){
			for(int i=0;i<c[cnt].size();i++){
				mp[c[cnt][i]]=1;
			}
		}
		cnt++;
		sum>>=1;
	}
	bool flag=0;
	for(int i=0;i<k;i++){
		flag=0;
		for(int j=0;j<c[i].size();j++){
			if(mp[c[i][j]]!=1){
				flag=1;
				break;
			}
		}
		if(!flag){
			ans<<=1;
		}
	}
	ans-=n;
	opt(ans);
	return 0;
}
