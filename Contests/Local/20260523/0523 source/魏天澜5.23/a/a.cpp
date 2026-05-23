#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pii;
#define fi first
#define se second
const int N = 5e5+10;
int n;
pii e[N];
vector<pii>p1;
vector<pii>p4;
vector<pii>now;
int cur = 0;
//fi==1 oi
//fi==2 o
//fi==3 i
//fi==4 j
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n;
	string s;
	cin>>s;
	s = " "+s;
	int i = 1;
	while(i<=n){
		if(s[i]=='O'){
			if(s[i+1]=='I'&&i+1<=n){
				i+=2;
				int cnt = 1;
				while(i+1<=n&&s[i]=='O'&&s[i+1]=='I'){
					i+=2;
					cnt++;
				}
				e[++cur] = {1,cnt};
				//e.push_back({1,cnt});
			}
			else{
				e[++cur] = {2,1};
				i++;
				//e.push_back({2,1});
			}
		}
		else if(s[i]=='I'){
			e[++cur] = {3,1};
			i++;
			//e.push_back({3,1});
		}
		else if(s[i]=='J'){
			i++;
			int cnt = 1;
			while(i<=n&&s[i]=='J'){
				cnt++;
				i++;
			}
			e[++cur] = {4,cnt};
			//e.push_back({4,cnt});
		}
	}
	int j = 1;
	while(j<=cur){
		//Çå¿Õvector 
		if(j<cur&&e[j].fi==4&&e[j+1].fi==1){
			p4.push_back(e[j]);
			p1.push_back(e[j+1]);
			j+=2;
			while(j<cur&&e[j].fi==4&&e[j+1].fi==1){
				p4.push_back(e[j]);
				p1.push_back(e[j+1]);
				j+=2;
			}
			for(int k = 0;k<p1.size();k++)now.push_back(p1[k]);
			for(int k = 0;k<p4.size();k++)now.push_back(p4[k]);
			p1.clear();
			p4.clear();
		}
		else now.push_back(e[j]),j++;
	}
//	for(int j = 1;j<cur;j++){
//		if(e[j].fi==4&&e[j+1].fi==1)swap(e[j],e[j+1]);
//	}
	
	for(int j = 0;j<now.size();j++){
		if(now[j].fi==1){
			for(int k = 1;k<=now[j].se;k++){
				cout<<"OI";
			}
		}
		if(now[j].fi==2){
			cout<<"O";
		}
		if(now[j].fi==3){
			cout<<"I";
		}
		if(now[j].fi==4){
			for(int k = 1;k<=now[j].se;k++){
				cout<<"J";
			}
		}
	}
	return 0;
}
