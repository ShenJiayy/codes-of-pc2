#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int v,a,x;
}p[500001];
int n,b[500001],s,f,t[500001],v;
bool g[500001];
inline bool cmp(node l,node r){
	return l.a<r.a;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a;
		p[i].v=i;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i].x;
	}
	sort(p+1,p+n+1,cmp);
	for(int i=n;i>=1;i--){
		if(p[i].x!=-1){
			p[i].x=b[p[i].x];
		}
		b[p[i].v]=i;
	}
	for(int i=1;i<=n-2;i++){
		if(p[i].x==n-1){
			s++;
		}
	}
	if(s==n-2&&p[n-1].x==n){
		f=1;
	}
	s=0;
	for(int i=1;i<=n-1;i++){
		if(p[i].x==n){
			s++;
		}
	}
	if(s==n-1){
		f=1;
	}
	if(f==1){
		cout<<"-1\n";
	}
	else{
		s=0;
		for(int i=2;i<=n/2;i++){
			if(p[i].x!=p[i-1].x){
				f=1;
				break;
			}
		}
		if(f==1||p[1].x==-1){
			for(int i=1;i<=n/2;i++){
				s+=p[i].a*(n/2-i+1);
			}
			cout<<s<<'\n';
			for(int i=1,j=n/2+1,k=n/2+2;i<=n/2-1;i++){
				if(p[i].x!=j){
					t[i]=j;
					j=k;
					k++;
				}
				else{
					t[i]=k;
					k++;
				}
				g[t[i]]=1;
			}
			for(int i=n/2+1;i<=n;i++){
				if(!g[i]){
					v=i;
					break;
				}
			}
			if(p[n/2].x!=v){
				t[n/2]=v;
			}
			else{
				for(int i=1;i<=n/2-1;i++){
					if(p[i].x!=v){
						t[n/2]=t[i];
						t[i]=v;
						break;
					}
				}
			}
			for(int i=n/2;i>=1;i--){
				cout<<p[i].v<<' '<<p[t[i]].v<<'\n';
			}
		}
		else{
			for(int i=1;i<=n/2-1;i++){
				s+=p[i].a*(n/2-i+1);
			}
			for(int i=n/2+1;i<=p[1].x-1;i++){
				if(p[i].x!=p[1].x){
					f=i;
					s+=p[i].a;
					break;
				}
			}
			if(f==0){
				if(p[p[1].x].x==p[1].x+1){
					f=p[1].x+2;
				}
				else{
					f=p[1].x+1;
				}
				s+=p[p[1].x].a;
			}
			cout<<s<<'\n'<<p[p[1].x].v<<' '<<p[f].v<<'\n'<<p[n/2].v<<' '<<p[n/2-1].v<<'\n';
			for(int i=n/2-2,j=n;i>=1;i--,j--){
				if(j==p[1].x||j==f){
					j--;
				}
				cout<<p[i].v<<' '<<p[j].v<<'\n';
			}
		}
	}
	return 0;
}
