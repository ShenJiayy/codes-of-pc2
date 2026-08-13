#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+50;
template<class T>
inline T read(){
	T x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar(); 
	}
	return x*f;
}
template<class T>
inline void write(T x){
	if(x<0){putchar('-');write(-x);return ;}
	if(x<10){putchar(x+'0');return ;}
	write(x/10);
	putchar(x%10+'0');
	return ;
}
string s;ll n,cnt=0,sum=0,tcnt;
struct oi{ll id,fj;char ch;};
vector<oi> v;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read<ll>();
	cin>>s;s='*'+s;
	for(ll i=1;i<=n;i++){
		if(s[i]=='J') cnt++;
		else{
			v.push_back({i,cnt,s[i]});
			cnt=0;
		}
	}tcnt=cnt;
	cnt=0;
	for(ll i=0;i<v.size();i++){
		oi tmp=v[i];cnt+=tmp.fj;
		if((i==0&&v[i].ch=='I')||(i!=0&&v[i-1].ch=='I'&&v[i].ch=='I')||(i!=v.size()-1&&v[i+1].ch=='O'&&v[i].ch=='O')||(i==v.size()-1&&v[i].ch=='O')){
			for(ll j=1;j<=cnt;j++){
				putchar('J');sum++;
			}
			cnt=0;
		}
		putchar(v[i].ch);sum++;
	}
	for(ll j=1;j<=cnt+tcnt;j++){
		putchar('J');sum++;
	}putchar('\n');
	return 0;
} 
