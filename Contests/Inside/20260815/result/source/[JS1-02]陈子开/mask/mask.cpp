#include<bits/stdc++.h>
using namespace std;
const int N=505;
int h,w,q;
int mp[N][N];
bool book[N][N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("mask.in","r",stdin);
	freopen("mask.out","w",stdout); 
	cin>>h>>w>>q;
	while(q--) {
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1) {
			int c;
			cin>>c;
			if(!book[x][y]) mp[x][y]=c;
			if(!book[x+1][y]) mp[x+1][y]=c;
			if(!book[x][y+1]) mp[x][y+1]=c;
			if(!book[x+1][y+1]) mp[x+1][y+1]=c;
		}
		else {
			book[x][y]=true;
			book[x+1][y]=true;
			book[x][y+1]=true;
			book[x+1][y+1]=true;
		}
	}
	for(int i=1;i<=h;i++) {
		for(int j=1;j<=w;j++) {
			cout<<mp[i][j]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}

