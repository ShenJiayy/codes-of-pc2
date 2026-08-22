#include <bits/stdc++.h>
using namespace std;
int t,n,idx;
deque<int> arr;
int minn[1000010];
bool lr[1000010];
bool ans[1000010];
bool check(deque<int> qu){
	while(!qu.empty()){
		if(qu.front()==qu.back()){
			qu.pop_back();
			qu.pop_front();
		}
		else{
			return false;
		}
	}
	return true;
}
bool issml(deque<int> qu){
	int cnt = 1;
	while(!qu.empty()){
		if(qu.front()>minn[cnt]) return false;
		else if(qu.front()<minn[cnt]) return true;
		cnt++;
		qu.pop_front();
	}
	return true;
}
void gx(){
	if(lr[1]){
		int cnt = 1;
		while(lr[cnt]){
			lr[cnt] = false;
			cnt++;
		}
		lr[cnt] = true;
	}
	else{
		lr[1] = true;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		memset(lr,0,sizeof(lr));
		memset(minn,0x3f,sizeof(minn));
		cin>>n;
		
		for(int i=1;i<=2*n;i++){
			int x;
			cin>>x;
			arr.push_front(x);
		}
		if(check(arr)){
			for(int i=1;i<n;i++) cout<<"LR";
			cout<<"LL";
			continue;
		}
		if(n>10){
			cout<<-1<<endl;
			continue;
		}
//		while(!arr.empty()){
//			cout<<arr.back()<<" ";
//			arr.pop_back();
//		}
		bool flag = false;
		for(int k=1;k<=(long long)pow(2,n*2);k++){
			deque<int> q;
			int l=1,r=2*n;
			bool book[100010];
			for(int i=1;i<=2*n;i++){
				int ts[100010];
				int ccnt=1;
				while(!arr.empty()){
					ts[ccnt] = arr.back();
					ccnt++;
					arr.pop_back();
				}
				if(lr[i]){
					q.push_front(ts[r]);
					r--;
					book[i] = true;
//					cout<<"in r "<<endl;
				}
				else{
					q.push_front(ts[l]);
					l++;
					book[i] = false;
//					cout<<"in l "<<endl;
				}
//				cout<<l<<" "<<r<<endl;
			}
//			for(int i=1;i<=2*n;i++) cout<<book[i]<<" ";
//			cout<<endl;
//			while(!q.empty()){
//				cout<<q.back()<<" ";
//				q.pop_back();
//			}
//			cout<<endl<<endl;
//			cout<<check(q)<<endl;
			if(check(q)){
				flag = true;
				
				if(issml(q)){
					int tt = 1;
//					cout<<114514<<endl<<endl;
					while(!q.empty()){
						minn[tt] = q.front();
						tt++;
						q.pop_front();
					}
					for(int i=1;i<=n*2;i++) ans[i] = book[i];
				}
			}
			gx();
		}
		if(!flag) cout<<-1<<endl;
		else{
			for(int i=1;i<2*n;i++){
				if(ans[i]) cout<<'R';
				else cout<<'L';
			}
			cout<<'L';
			cout<<endl;
		}
	}
	return 0;
}
/*
0 0 0 0 0 0 0
*/
