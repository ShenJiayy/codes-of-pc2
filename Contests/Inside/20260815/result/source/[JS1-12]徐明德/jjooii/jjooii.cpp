//jjooii
#include<bits/stdc++.h>
using namespace std;
char c;
int n,k;
stack<char>st;
string ss;
int ans;
vector<int>s[3];
int c1,c2,c0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	cin>>n>>k; 
	cin>>ss;
	ss=" "+ss;
	for(int i=1;i<=n;i++){
		c=ss[i];
		if(c=='J')c0++,s[0].push_back(i);
		if(c=='O')c1++,s[1].push_back(i);
		if(c=='I')c2++,s[2].push_back(i);
	}
	if(c0<k||c1<k||c2<k){
		cout<<-1;
		return 0;
	}
	int l=s[0][0];
	int r=s[3][s[3].size()-1];
	if(r<l){
		cout<<-1;
		return 0;
	}
	
	return 0;
} 
