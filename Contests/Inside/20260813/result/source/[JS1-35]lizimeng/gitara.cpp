//100pts
#include<bits/stdc++.h>
using namespace std;
deque<int> now[500010];
int n,p,i,j;
long long ans;
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	cin>>n>>p;
	while(n--){
		cin>>i>>j;
		while(!now[i].empty()&&now[i].front()>j){
			now[i].pop_front();
			ans++;
		}
		if(now[i].empty()||now[i].front()!=j) ans++; 
		if(now[i].front()!=j) now[i].push_front(j);
	}
	cout<<ans;
	return 0;
}
/*
0 h 24 min AC T1
shi bi na xia
*/
