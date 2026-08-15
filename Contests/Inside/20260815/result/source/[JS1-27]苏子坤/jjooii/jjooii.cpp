#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,J[200005],O[200005],I[200005],ans;
string s;
int main(){
	freopen("jjooii3.in","r",stdin);
//	freopen("jjooii.out","w",stdout);
	cin>>n>>k>>s;
	l=0,r=n-1;
	while(s[l]!='J')l++;
	while(s[r]!='I')r--;
	for(int i=r;i>=l;i--){
		J[i]=J[i+1]+(s[i]=='J');
		O[i]=O[i+1]+(s[i]=='O');
		I[i]=I[i+1]+(s[i]=='I');
	}
	if(J[l]<k||O[l]<k||I[l]<k){
		cout<<-1;
		return 0;
	}
	int nowj=J[l],nowo=O[l],nowi=I[l];
	bool flag=0;
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(!flag&&s[i]!='J')continue;
		if(!flag&&s[i]=='J')flag=1;
		if(J[i]>0&&O[i]>=k&&I[i]>=k){
			if(s[i]=='J')cnt++;
			if(s[i]=='O'){
				s[i]='J';
				ans++;
			}
			if(s[i]=='I'){
				s[i]='J';
				ans++;
			}
		}
	}
//	if(cnt<k){
//		cout<<-1;
//		return 0;
//	}
	flag=0;
	cnt=0;
	for(int i=l;i<=r;i++){
		if(!flag&&s[i]!='O')continue;
		if(!flag&&s[i]=='O')flag=1;
		if(O[i]>0&&I[i]>=k){
			if(s[i]=='J'){
				s[i]='O';
				ans++;
			}
			if(s[i]=='O')cnt++;
			if(s[i]=='I'){
				s[i]='O';
				ans++;
			}
		}
	}
//	if(cnt<k){
//		cout<<-1;
//		return 0;
//	}
	flag=0;
	for(int i=l;i<=r;i++){
		if(!flag&&s[i]!='I')continue;
		if(flag&&s[i]=='I')flag=1;
		if(I[i]>0){
			if(s[i]=='J'){
				s[i]='I';
				ans++;
			}
			if(s[i]=='O'){
				s[i]='I';
				ans++;
			}
			if(s[i]=='I')cnt++;
		}
	}
//	if(cnt<k){
//		cout<<-1;
//		return 0;
//	}
	cout<<ans;
	return 0;
}
