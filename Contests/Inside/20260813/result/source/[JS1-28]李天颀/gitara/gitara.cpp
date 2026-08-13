#include <bits/stdc++.h>
using namespace std;
int n,p,ans;
int idx[10]={0,1,1,1,1,1,1};
int gt[10][300010];
int main(){
	freopen("gitara.in","r",stdin);
	freopen("gitara.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>p;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(gt[a][idx[a]-1]==b) continue;
		else if(gt[a][idx[a]-1]<b){
			gt[a][idx[a]] = b;
			idx[a]++;
			ans++;
		}
		else{
			while(gt[a][idx[a]-1]>b){
				gt[a][idx[a]-1] = 0;
				idx[a]--;
				ans++;
			}
			if(gt[a][idx[a]-1]==b) continue;
			else{
				gt[a][idx[a]] = b;
				idx[a]++;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5 15
2 8
2 10
2 12
2 10
2 5
idx = 3;
b = 10;
0 8 10
*/
