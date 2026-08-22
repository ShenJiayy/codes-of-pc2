#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n;
bool is[N];
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
		}
		int fl=0;
		string s="L",s1="L";
		int l1=2,r1=n*2-1,l2=n-1,r2=n+2;
		while(l1<=r1){
			if(a[l1]==a[l2]||a[r1]==a[r2]||a[l1]==a[r2]||a[r1]==a[l2]){
				if(a[l1]==a[l2]){
					s=s+'L';
					s1='L'+s1;
				}
				if(a[r1]==a[r2]){
					s=s+'R';
					s1='R'+s1;
				}
				l1++,l2--,r1--,r2++;
			}
		}
		if(s.size()+s1.size()==2*n)fl=1;
		string s3="R",s4="R";
		l1=2,r1=n*2-1,l2=n-1,r2=n+2;
		while(l1<=r1){
			if(a[l1]==a[l2]||a[r1]==a[r2]||a[l1]==a[r2]||a[r1]==a[l2]){
				if(a[l1]==a[l2]){
					s3=s3+'L';
					s4='L'+s4;
				}
				if(a[r1]==a[r2]){
					s3=s3+'R';
					s4='R'+s4;
				}
			}l1++,l2--,r1--,r2++;
		}if(s3.size()+s4.size()==2*n)fl=1;	
		s+=s1;
		s3+=s4;
		int u=0;
		for(int l=0;l<s.size();l++){
			if(s[l]>s3[l])u=1;
		}
		if(!fl)cout<<-1<<"\n";
		else {
			if(u==1)cout<<s3<<"\n";
			else cout<<s<<"\n";
	   }
	}
	return 0;
}
