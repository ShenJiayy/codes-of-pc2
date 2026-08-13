#include <bits/stdc++.h>
using namespace std;
string a;
int n,f,e,l=1,len=1;
bool ba=0;
void en(int f,int e){
	ba=1;
	for(int j=1;j<=e;++j) cout<<"OI";
	for(int j=1;j<=f;++j) cout<<"J";
	return;
}
signed main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>a;
	for(int i=0;i<n;++i){
		if(ba){
			if(a[i]=='J'){
				ba=0;
				f++;
			}
			else cout<<a[i];
		}
		else{
			if(a[i]=='J') f++;
			else if(a[i]=='O'){
				if(a[i+1]=='I'){
					i++;
					e++;
				}
				else{
					en(f,e);
					f=0;
					e=0;
					cout<<"O";
				}
			}
			else{
				en(f,e);
				f=0;
				e=0;
				cout<<"I";
			}
		}
	}
	en(f,e);
	return 0;
}
