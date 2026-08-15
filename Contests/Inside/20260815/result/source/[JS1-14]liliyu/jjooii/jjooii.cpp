#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout);
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	int st,ed;
	for(int i = 0;i < s.size();i++){
		if(s[i] == 'J'){
			st = i;
			break;
		}
	}
	for(int i = s.size()-1;i >= st;i--){
		if(s[i] == 'I'){
			ed = i;
			break;
		}
	}
	int cntj = 0,cnto = 0,cnti = 0;
	for(int i = st;i <= ed;i++){
		if(s[i] == 'J'){
			cntj++;
			a[++a[0]] = 1;
			jid[++jid[0]] = cntj;
		}
		if(s[i] == 'O'){
			cnto++;
			a[++a[0]] = 2;
			oid[++oid[0]] = cnto;
		}
		if(s[i] == 'I'){
			cnti++;
			a[++a[0]] = 3;
			iid[++iid[0]] = cnti;
		}
	}
//	for(int i = 1;i <= a[0];i++){
//		cout << a[i] << " ";
//	}
	if(cntj < k || cnto < k || cnti < k){
		cout << -1;
		return 0;
	}
}

