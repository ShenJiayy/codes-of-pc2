#include<bits/stdc++.h>
using namespace std;
int n;
string s;
void solve1(){
	bool f=1;
	while(f){
		f=0;
		for(int i=0;i<n-2;i++){	
			if (s[i]=='J' && s[i+1]=='O'&& s[i+2]=='I') {
				f=1;
				s[i]='O',s[i+1]='I',s[i+2]='J';
			}
		}
	}
	cout<<s;
}
void solve2(){
	for (int i=1;i<=n/3;i++) cout<<"OI";
	for (int i=1;i<=n/3;i++) cout<<"J";
}
void solve(){
	vector<int> a;
	int b[500020];
	for(int i=0;i<n;i++){
		if (s[i]=='J') a.push_back(1);
		else if (s[i]=='O' && i!=n-1 && s[i+1]=='I') a.push_back(2);
		else if (s[i]=='I' && i!=0 && s[i-1]=='O') continue;
		else{
			a.push_back(3);
			b[a.size()-1]=i;
		} 
	}
	a.push_back(3);
	int cj=0,coi=0;
	for (int i=0;i<a.size();i++){
		if (a[i]==1) cj++;
		if (a[i]==2) coi++;
		if (a[i]==3) {
			for(int i=1;i<=coi;i++) cout<<"OI";
			for(int i=1;i<=cj;i++) cout<<"J";
			cj=0,coi=0;
			if (i!=a.size()-1) cout<<s[b[i]];
		}
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>s;
	solve();
	return 0;
} 
