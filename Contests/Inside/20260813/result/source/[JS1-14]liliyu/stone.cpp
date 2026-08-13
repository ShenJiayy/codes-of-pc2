#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 200005;
vector<int> a;
int stone[N],ban[N];
int pre_id[N],pos[N],che[N],ed[N],st[N];
int query(int x){
	return che[pos[x]] == -1 ? ban[x] : che[pos[x]];
}
void push_down(int x){
	if(che[x] == -1) return;
	for(int i = st[x];i <= ed[x];i++) ban[i] = che[x];
	che[x] = -1;
}
void change(int L,int R,int d){
	int p = pos[L],q = pos[R];
	if(p == q){
		push_down(p);
		for(int i = L;i <= R;i++) ban[i] = d;
	}else{
		push_down(p);
		push_down(q);
		for(int i = p + 1;i <= q - 1;i++){
			che[i] = d;
		}
		for(int i = L;i <= ed[p];i++) ban[i] = d;
		for(int i = st[q];i <= R;i++) ban[i] = d;
	}
}
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	int len = sqrt(n);
	int t = n/len;
	if(n % len) t++;
	for(int i = 1;i <= t;i++){
		st[i] = (i - 1) * len + 1;
		ed[i] = i * len; 
	}
	ed[t] = n;
	for(int i = 1;i <= n;i++)
		pos[i] = (i - 1)/len + 1;
	for(int i = 1;i <= n;i++){
		cin >> stone[i];
		a.push_back(stone[i]);
		che[i] = -1;pre_id[i] = -1;
	}
	sort(a.begin(),a.end()); 
	a.erase(unique(a.begin(),a.end()),a.end());
	for(int i = 1;i <= n;i++){
		int now_pos = lower_bound(a.begin(),a.end(),stone[i]) - a.begin() + 1;
		if(pre_id[now_pos] == -1){
			pre_id[now_pos] = i;
			continue;
		}
		int found = query(pre_id[now_pos]);
		if(found == 1){
			pre_id[now_pos] = i;
			continue;
		}
		if(i - 1 >= pre_id[now_pos] + 1){
			change(pre_id[now_pos] + 1,i - 1,1); 
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(query(i) == 1) cout << ans << "\n";
		else{
			cout << stone[i] << "\n";
			ans = stone[i];
		}
	}
}

