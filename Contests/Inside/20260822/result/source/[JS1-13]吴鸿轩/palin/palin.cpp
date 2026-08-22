#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000010],bl[500010],br[500010],c[500010];
char s[1000010];
bool b1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		b1=0;
		for(int i=1;i<=2*n;i++){
			bl[i]=br[i]=c[i]=0;
		}
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
			if(bl[a[i]]==0){
				bl[a[i]]=i;
			}else{
				br[a[i]]=i;
			}
		}
		int l=1,r=n*2,aa=1,cnt=0,nl,nr;
		int num=br[a[1]],a1,a2;
		nl=num;
		nr=num;
		l++;
		cnt++;
		s[cnt]='L';
		while(cnt<n&&aa==1){
			c[cnt]=num;
			//cout<<num<<endl;
			aa=0;
			a1=br[a[l]];
			a2=bl[a[r]];
			//cout<<l<<" "<<r<<endl;
		//	cout<<a1<<" "<<a2<<endl;
			if(a1<=r){
				if(nr+1==a1){
					cnt++;
					s[cnt]='L';
					num=br[a[l]];
					nr++;
					l++;
					aa=1;
					continue;
				}
				if(nl-1==a1){
					cnt++;
					s[cnt]='L';
					num=br[a[l]];
					nl--;
					l++;
					aa=1;
					continue;
				}	
			}
			if(a2>=l){
				if(nr+1==a2){
					cnt++;
					s[cnt]='R';
					num=bl[a[r]];
					nr++;
					r--;
					aa=1;
					continue;
				}
				if(nl-1==a2){
					cnt++;
					s[cnt]='R';
					nl--;
					num=bl[a[r]];
					r--;
					aa=1;
					continue;
				}
			}
			if(aa==0){
				b1=1;
				break;
			}
		}
		c[cnt]=num;
		int p=cnt;
		while(b1==0){
		//	cout<<c[p]<<" "<<l<<" "<<r<<endl;
			if(c[p]==l){
				l++;
				cnt++;
				s[cnt]='L';
			}else if(c[p]==r){
				r--;
				cnt++;
				s[cnt]='R';
			}else{
				b1=1;
			}
			p--;
		}	
		if(cnt==n*2){
			for(int i=1;i<=cnt;i++){
				cout<<s[i];
			}
			cout<<'\n';
		}else{
			b1=0;
			int l=1,r=n*2,aa=1,cnt=0;
			int num=bl[a[n*2]],a1,a2;
			nl=num;
			nr=num;
			r--;
			cnt++;
			s[cnt]='R';
			while(cnt<n&&aa==1){
				c[cnt]=num;
				aa=0;
				a1=br[a[l]];
				a2=bl[a[r]];
				if(a1<=r){
					if(nr+1==a1){
						cnt++;
						s[cnt]='L';
						nr++;
						num=br[a[l]];
						l++;
						aa=1;
						continue;
					}
					if(nl-1==a1){
						cnt++;
						s[cnt]='L';
						num=br[a[l]];
						nl--;
						l++;
						aa=1;
						continue;
					}	
				}
				if(a2>=l){
					if(nr+1==a2){
						cnt++;
						s[cnt]='R';
						nr++;
						num=bl[a[r]];
						r--;
						aa=1;
						continue;
					}
					if(nl-1==a2){
						cnt++;
						s[cnt]='R';
						nl--;
						num=bl[a[r]];
						r--;
						aa=1;
						continue;
					}
				}
				if(aa==0){
					b1=1;
					break;
				}
			}
			c[cnt]=num;
			int p=cnt;
			while(b1==0){
				if(c[p]==l){
					l++;
					cnt++;
					s[cnt]='L';
				}else if(c[p]==r){
					r--;
					cnt++;
					s[cnt]='R';
				}else{
					b1=1;
				}
				p--;
			}
			if(cnt==n*2){
				for(int i=1;i<=cnt;i++){
					cout<<s[i];
				}
				cout<<'\n';
			}else{
				cout<<-1<<'\n';
			}
		}
	}
	return 0;
}
