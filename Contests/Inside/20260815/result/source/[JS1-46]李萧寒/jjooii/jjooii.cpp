#include<bits/stdc++.h>
using namespace std;
int J[200005],I[200005],O[200005];
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		J[i]=J[i-1];
		I[i]=I[i-1];
		O[i]=O[i-1];
		if(s[i]=='J'){
			J[i]++;
		}		
		else if(s[i]=='I'){
			I[i]++;
		}
		else{
			O[i]++;
		}
	}
	if(J[n]<k||I[n]<k||O[n]<k){
		cout<<-1;
		return 0;
	}
	int jb=-1,ob=-1,ib=-1,je=-1,oe=-1,ie=-1;
	for(int i=1;i<=n;i++){
		if(J[i]==k){
			je=i;
			break;
		}
		if(J[i]==1&&jb==-1){
			jb=i;
		}
	}
	if(je==-1){
		cout<<-1;
		return 0;
	}
	ob=je+1;
	for(int i=je+1;i<=n;i++){
		if(O[i]-O[je]==k){
			oe=i;
			break;
		}
	}
	if(oe==-1){
		cout<<-1;
		return 0;
	}
	ib=oe+1;
	for(int i=oe+1;i<=n;i++){
		if(I[i]-I[oe]==k){
			ie=i;
			break;
		}
	}
	if(ie==-1){
		cout<<-1;
		return 0;
	}
	int mi=(ie-jb+1)-3*k;
	jb++;
	while(jb+3*k-1<=n){
		if(s[jb-1]=='J'){
			while(je<=n&&J[je]-J[jb-1]<k)je++;
			if(J[je]-J[jb-1]<k){
				cout<<mi;
				return 0;
			}
			ob=je+1;
			while(oe<=n&&O[oe]-O[ob-1]<k)oe++;
			if(O[oe]-O[ob-1]<k){
				cout<<mi;
				return 0;
			}
			ib=oe+1;
			while(ie<=n&&I[ie]-I[ib-1]<k)ie++;
			if(I[ie]-I[ib-1]<k){
				cout<<mi;
				return 0;
			}
			mi=min(mi,ie-jb+1);
		}
		jb++;
	}
	cout<<mi;
	return 0;
}
