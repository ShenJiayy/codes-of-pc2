#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k;
int sum[3][N]; //第i个位置前面有几个相同字符
int d[3][N]; //删去前面所有不同字符所需的次数 
int joi[3][N], tot[3]; //第i个某字符所在的位置 
int jo[N], oi[N];
int pos[N]; //排名 
char s[N];

int getid(char c){
	if(c == 'J') return 0;
	else if(c == 'O') return 1;
	else return 2;
}

int main(){
	freopen("jjooii.in", "r", stdin);
	freopen("jjooii.out", "w", stdout);
	cin>>n>>k;
	int tjo=0, toi=0;
	for(int i=1; i<=n; i++){
		cin>>s[i];
		int id = getid(s[i]);
		sum[id][i] = sum[id][i-1] + 1;
		sum[(id+1)%3][i] = sum[(id+1)%3][i-1];
		sum[(id+2)%3][i] = sum[(id+2)%3][i-1];
		joi[id][++tot[id]] = i;
		pos[i] = tot[id];
		d[id][i] = i - sum[(id+1)%3][i] - sum[(id+2)%3][i];
		if(id == 1){
//			if(s[i-1] == 'J' && sum[0][i-1]>=k) jo[++tjo] = i;
			if(s[i-1] == 'J') jo[++tjo] = i;
		}
		if(id == 2){
//			if(s[i-1] == 'O' && sum[1][i-1]>=k && sum[0][i-1]>=k) oi[++toi] = i-1;
			if(s[i-1] == 'O') oi[++toi] = i-1;
		}
	}
	int ans = INT_MAX;
//	for(int i=1; i<=tjo; i++){
//		for(int j=1; j<=toi; j++){
//			if(oi[j] < jo[i]) continue;
//			if(sum[1][oi[j]]-sum[1][jo[i]-1]<=k) continue; //o的个数 
//			int res = (oi[j]-jo[i]+1) - (sum[1][oi[j]]-sum[1][jo[i]-1]); //o-o中要删掉的数
//			res +=  (jo[i]-1-joi[0][pos[jo[i]-1]-k+1]+1) - (sum[0][jo[i]-1]-sum[0][joi[0][pos[jo[i]-1]-k+1]-1]);
//			res +=  (joi[2][pos[oi[i]+1]+k-1]-oi[i]-1+1) - (sum[2][joi[2][pos[oi[i]+1]+k-1]]-sum[2][oi[i]+1-1]);
//			cout<<res<<endl;
//			ans = min(ans, res);
//		}
//	}
	if(ans != INT_MAX) cout<<ans;
	else cout<<-1;
	return 0;
}
