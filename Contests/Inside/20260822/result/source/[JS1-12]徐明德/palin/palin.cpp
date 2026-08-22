//palin 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
bool f[N];
int a[N*2];
int tot;
int n;
int x[N];//ai靠前位置 
int y[N];//ai靠后位置  
int ans[N*2];
int nll,nrr;
void solve(){
	cin>>n;
	fill(f+1,f+1+n,0);
	fill(ans+1,ans+1+n*2,0);
	for(int i=1;i<=n*2;i++){
		cin>>a[i];
		if(f[a[i]]==1){
			y[a[i]]=i;
			f[a[i]]=0;
		}
		else{
			x[a[i]]=i;
			f[a[i]]=1;
		}
	}
	int l=0,r=2*n+1;
	int nl=-1,nr=-1; 
	for(int k=1;k<=n;k++){
		if(nl==-1||y[a[l+1]]==nl-1||y[a[l+1]]==nr+1||x[a[r-1]]==nl-1||x[a[r-1]]==nr+1){
			if(abs(y[a[l+1]]-x[a[r-1]])==1&&nl==-1){
				if(a[l+1]<=a[r-1]){
					l++;
					ans[l]=k;
					ans[y[a[l]]]=n*2-k+1;
					nl=nr=y[a[l]];
					continue;
				}
				else{
					r--;
					ans[r]=k;
					ans[x[a[r]]]=n*2-k+1;
					nl=nr=x[a[r]];
					continue;
				}
			}
			if(y[a[l+1]]==nl-1||y[a[l+1]]==nr+1){
				if(x[a[r-1]]==nl-1||x[a[r-1]]==nr+1){
					if(a[l+1]<=a[r-1]){
						/*if(a[l+1]==a[r-1]&&(l<nl-1||r>nr+1)&&k!=n){
							cout<<-1<<endl;
							return ;
						}*/
						l++;
						ans[l]=k;
						ans[y[a[l]]]=n*2-k+1;
						if(y[a[l]]==nl-1)nl--;
						else nr++;
						continue;
					}
					else {
						r--;
						ans[r]=k;
						ans[x[a[r]]]=n*2-k+1;
						if(x[a[r]]==nl-1)nl--;
						else nr++;
						continue;
					}
				}
				else{
					l++;
					ans[l]=k;
					ans[y[a[l]]]=n*2-k+1;
					if(y[a[l]]==nl-1)nl--;
					else nr++;
					continue;
				}
			}
			else{
				r--;
				ans[r]=k;
				ans[x[a[r]]]=n*2-k+1;
				if(x[a[r]]==nl-1)nl--;
				else nr++;
				continue;
			}
		}
		else{
			continue;
		}
	}
	int ll=1,rr=n*2;
	vector<char>kkk;
	int cnt=1;
	while(ll<=rr){
		if(ans[ll]!=cnt&&ans[rr]!=cnt){
			cout<<-1<<endl;
			return ;
		}
		if(ans[ll]==cnt){
			kkk.push_back('L');
			ll++;
		}
		else kkk.push_back('R'),rr--;
		cnt++;
	}
	for(int i=0;i<kkk.size();i++){
		cout<<kkk[i];
	}
	cout<<endl;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int _;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}
