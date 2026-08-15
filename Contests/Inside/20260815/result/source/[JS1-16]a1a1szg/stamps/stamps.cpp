#include<bits/stdc++.h>
using namespace std;
const int N=205;
struct node{
	int dis,tim;
};
struct ee{
	int f,t;
};
int n,l,ans=-1,cnt,uu;
node a[N];
ee fl[N];// 0 left 1 right
string fj(int uuu){
	string u="";
	while(uuu){
		u+=char((uuu%2)+48);
		uuu/=2;
	}
	while(u.size()<n)u+='0';
	reverse(u.begin(),u.end());
//	cout<<u<<"\n";
	return u;
}
int  check(string s){
int sum=0,t=0;
	for(int i=0;i<n;i++){
		if(t>=uu)break;
	//	cout<<cnt<<" "<<i<<"\n";
		if(s[i]=='0'){
			cnt=cnt%l;
			cnt+=l;
			while(t<=uu){
				if(fl[cnt].f==1&&t<=fl[cnt].t){
				sum++;	fl[cnt].f=0;break;
				}//cout<<t;
				t++,cnt--;
				cnt+=l;
				cnt%=l;
			}
		}else{
			cnt=cnt%l;
			cnt+=l;
			while(t<=uu){
				if(fl[cnt].f==1&&t<=fl[cnt].t){
				sum++;	fl[cnt].f=0;break;
				}
				t++,cnt++;
				cnt+=l;
				cnt%=l;
			}
		}
	}//cout<<sum<<"\n";
	return sum;
}
signed main(){
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>a[i].dis;
		
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].tim;uu=max(uu,a[i].tim);
	} 
//	sort(a+1,a+n+1,[](node e,node r){
//		if(e.dis==r.dis)return e.tim<r.tim;
//		return e.dis<r.dis;
//	});
	int yy=pow(2,n)-1;
	for(int i=0;i<=yy;i++){
	cnt=0;
		memset(fl,0,sizeof(fl));
		for(int j=1;j<=n;j++){
			fl[a[j].dis].f=1,fl[a[j].dis].t=a[j].tim;
		}//string p="";
		ans=max(ans,check(fj(i)));
	}
	cout<<ans;
	return 0;
}
