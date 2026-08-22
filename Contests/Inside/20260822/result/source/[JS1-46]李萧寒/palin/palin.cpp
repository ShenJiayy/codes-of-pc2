#include<bits/stdc++.h>
using namespace std;
int x[1000005],nxt[1000005],c[1000005];
struct node{
	int a,b;
}ling[500005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,shangn=500000;
	cin>>t;
	while(t--){
		for(int i=1;i<=shangn;i++){
			ling[i].a=ling[i].b=-1;
		}
		int n;
		cin>>n;
		shangn=n;
		for(int i=1;i<=2*n;i++){
			cin>>x[i];
			if(ling[x[i]].a==-1){
				ling[x[i]].a=i;
			}
			else{
				ling[x[i]].b=i;
			}
		}
		if(n==1){
			cout<<"LL"<<endl;
			continue;
		}
		for(int i=1;i<=2*n;i++){
			if(ling[x[i]].a==i){
				nxt[i]=ling[x[i]].b;
			}
			else{
				nxt[i]=ling[x[i]].a;
			}
		}
		int l=1,r=2*n,L=-1,R=-1,cnt=0;
		bool flag=true;
		L=R=nxt[l];
		c[1]=l,c[2*n]=nxt[l];
		l=2;
		cnt=1;
		while(r-l+1!=n){
			if(L!=l){
				if(nxt[l]==L-1){
					c[++cnt]=l,c[2*n-cnt+1]=L-1;
					L--;
					l++;
					continue;
				}
				else if(nxt[l]==R+1){
					c[++cnt]=l,c[2*n-cnt+1]=R+1;
					R++;
					l++;
					continue;
				}
			}
			if(R!=r){
				if(nxt[r]==L-1){
					c[++cnt]=r,c[2*n-cnt+1]=L-1;
					L--;
					r--;
					continue;
				}
				else if(nxt[r]==R+1){
					c[++cnt]=r,c[2*n-cnt+1]=R+1;
					R++;
					r--;
					continue;
				}
			}
			flag=false;
			break;
		}
		if(flag){
			l=1,r=2*n,cnt=1;
			while(l<=r){
				if(l==c[cnt]){
					cout<<'L';
					l++;
				}
				else{
					cout<<'R';
					r--;
				}
				cnt++;
			}
			cout<<endl;
			continue;
		}
		l=1,r=2*n,L=-1,R=-1,cnt=0;
		flag=true;
		L=R=nxt[r];
		c[1]=r,c[2*n]=nxt[r];
		r=2*n-1;
		cnt=1;
		while(r-l+1!=n){
			if(L!=l){
				if(nxt[l]==L-1){
					c[++cnt]=l,c[2*n-cnt+1]=L-1;
					L--;
					l++;
					continue;
				}
				else if(nxt[l]==R+1){
					c[++cnt]=l,c[2*n-cnt+1]=R+1;
					R++;
					l++;
					continue;
				}
			}
			if(R!=r){
				if(nxt[r]==L-1){
					c[++cnt]=r,c[2*n-cnt+1]=L-1;
					L--;
					r--;
					continue;
				}
				else if(nxt[r]==R+1){
					c[++cnt]=r,c[2*n-cnt+1]=R+1;
					R++;
					r--;
					continue;
				}
			}
			flag=false;
			break;
		}
		if(flag){
			l=1,r=2*n,cnt=1;
			while(l<=r){
				if(l==c[cnt]){
					cout<<'L';
					l++;
				}
				else{
					cout<<'R';
					r--;
				}
				cnt++;
			}
			cout<<endl;
			continue;
		}
		cout<<-1<<endl;
	}
	return 0;
}
