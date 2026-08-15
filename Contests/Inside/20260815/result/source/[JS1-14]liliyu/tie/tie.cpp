#include<bits/stdc++.h>
using namespace std;
int n,b[200010],delt[200010],delt2[200010],sd[200010],sd2[200010];
struct Tie{
	int l,id;
}a[200010],ans[200010];
bool cmp(Tie A,Tie B){
	if(A.l != B.l) return A.l < B.l;
	return A.id < B.id;
}
bool cmp2(Tie A,Tie B){
	return A.id < B.id;
}
int main(){
	freopen("tie.in","r",stdin);
	freopen("tie.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n + 1;i++){
		cin >> a[i].l;
		a[i].id = i;
	}
	for(int j = 1;j <= n;j++){
		cin >> b[j];
	}
	sort(a+1,a+n+2,cmp);
	sort(b+1,b+n+1);
	for(int i = 1;i <= n;i++){
		delt[i] = max(a[i].l - b[i],0);
		delt2[i] = max(a[i + 1].l - b[i],0);
	}
	for(int i = 1;i <= n;i++){
		sd[i] = max(sd[i-1],delt[i]);
	}
	for(int i = n;i >= 1;i--){
		sd2[i] = max(sd2[i+1],delt2[i]);
	}
	for(int i = 1;i <= n+1;i++){
		ans[i].l = max(sd[i-1],sd2[i]);
		ans[i].id = a[i].id;
	}
	sort(ans+1,ans+n+2,cmp2);
	for(int i = 1;i <= n+1;i++){
		cout << ans[i].l << " ";
	}
}

