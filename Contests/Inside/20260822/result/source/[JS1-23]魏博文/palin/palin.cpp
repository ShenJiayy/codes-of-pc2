#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N*2],p[N][2];
char s[N*2];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
			if(p[a[i]][0]==0) p[a[i]][0]=i;
			else p[a[i]][1]=i;
		}
		for(int i=1;i<=n*2;i++) s[i]=' ';
		int l=2,r=n*2,cnt=1,q1=p[a[1]][1],q2=p[a[1]][1];
		//cout<<q1<<q2;
		s[1]='L';s[n*2]='L';
		while(cnt<=n){
			//cout<<l<<" "<<r<<" "<<cnt<<'\n';
			if(cnt==n) break;
			if(p[a[l]][1]+1==q1){
				s[++cnt]='L';
				s[n*2-cnt+1]='L';
				q1--;
				l++;
			}
			else if(p[a[l]][1]-1==q2){
				s[++cnt]='L';
				s[n*2-cnt+1]='R';
				q2++;
				l++;
			}
			else if(p[a[r]][0]+1==q1){
				s[++cnt]='R';
				s[n*2-cnt+1]='L';
				q1--;
				r--;
			}
			else if(p[a[r]][0]-1==q2){
				s[++cnt]='R';
				s[n*2-cnt+1]='R';
				q2++;
				r--;
			}
			else break;
		}
		if(cnt==n){
			for(int i=1;i<=n*2;i++){
				cout<<s[i];
			}
			cout<<"\n";
			continue;
		}
		for(int i=1;i<=n*2;i++) s[i]=' ';
	    l=1,r=n*2-1,cnt=1,q1=p[a[n*2]][0],q2=p[a[n*2]][0];
		s[1]='R';s[n*2]='L';
		while(cnt<=n){
			if(cnt==n) break;
			if(p[a[l]][1]+1==q1){
				s[++cnt]='L';
				s[n*2-cnt+1]='L';
				q1--;
				l++;
			}
			else if(p[a[l]][1]-1==q2){
				s[++cnt]='L';
				s[n*2-cnt+1]='R';
				q2++;
				l++;
			}
			else if(p[a[r]][0]+1==q1){
				s[++cnt]='R';
				s[n*2-cnt+1]='L';
				q1--;
				r--;
			}
			else if(p[a[r]][0]-1==q2){
				s[++cnt]='R';
				s[n*2-cnt+1]='R';
				q2++;
				r--;
			}
			else break;
		}
		if(cnt==n){
			for(int i=1;i<=n*2;i++){
				cout<<s[i];
			}
			cout<<"\n";
			continue;
		}
		cout<<"-1\n";
	}
}                                                                                                                        
