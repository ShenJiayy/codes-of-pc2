#include<bits/stdc++.h>
#define I return
#define AK 0
#define IOI
using namespace std;
int n,a[500010],m,b[500010];
//a[i]:连续OI字串最长延伸长度  
string s,ss; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	cin>>s;
	s=" "+s;
	ss=" ";
	for(int i=1;i<=n;i++){
		if(s[i]!='J'){
			ss+=" ";
			ss[++m]=s[i];
		}
		else b[m]++;
	}
	for(int i=m-1;i>=1;i--){
		if(ss[i]=='O'&&ss[i+1]=='I'){
			a[i-1]=a[i+1]+2;
		}
	}
	for(int i=0;i<=m+1;i++){
		//cout<<b[i];
		if(!a[i]) continue;
		b[i+a[i]]+=b[i];
		b[i]=0;
	}
	for(int i=0;i<=m;i++){
		if(i) cout<<ss[i];
		for(int j=1;j<=b[i];j++) cout<<'J';
	}
	for(int i=1;i<=b[m+1];i++) cout<<'J';
	I AK IOI;
}
//100 
