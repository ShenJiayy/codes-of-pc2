#include <bits/stdc++.h>
#define ll long long
using namespace std;
string a,b;
ll q,cnt[100][26],len[100]; 
ll cal(int k,ll x,char c){
	if(k==1){
		int tmp=0;
		for(int i=0;i<x;i++){
			if(a[i]==c) tmp++;
		}
		return tmp;
	}
	if(k==2){
		int tmp=0;
		for(int i=0;i<x;i++){
			if(b[i]==c) tmp++;
		}
		return tmp;
	}
	if(x<=len[k-1]) return cal(k-1,x,c);
	else return cnt[k-1][c-'a']+cal(k-2,x-len[k-1],c);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    cin>>q;
    for(auto c:a){
    	cnt[1][c-'a']++;
	}
	for(auto c:b){
		cnt[2][c-'a']++;
	}
	len[1]=a.size();
	len[2]=b.size();
	for(int i=3;i<=88;i++){
		len[i]=len[i-1]+len[i-2];
		for(int j=1;j<=26;j++){
			cnt[i][j]=cnt[i-1][j]+cnt[i-2][j];
		}
	}
	while(q--){
		int l,r;
		char c;
		cin>>l>>r>>c;
		cout<<cal(88,r,c)-cal(88,l-1,c)<<"\n";
	}
    return 0;
}
