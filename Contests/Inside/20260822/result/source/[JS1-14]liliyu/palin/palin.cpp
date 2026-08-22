#include<bits/stdc++.h>
using namespace std;
int a[1000006];
struct point{
	int l,r;
} pos[1000006];
inline void init(){
	for(int i = 1;i <= 1000004;i++){
		a[i] = 0;
		pos[i].l = 0;
		pos[i].r = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		init();
		int n;
		cin >> n;
		string ans1,ans2;
		string ans3,ans4;
		for(int i = 1;i <= 2 * n;i++){
			cin >> a[i];
			if(pos[a[i]].l != 0) pos[a[i]].r = i;
			else pos[a[i]].l = i;
		}
		int cnt = 0;
		int check_l,check_r,kuai_l,kuai_r;
		check_l = 1,check_r = 2 * n,kuai_l = pos[a[check_l]].r,kuai_r = kuai_l;
		ans1 += "L",ans2 += "L";
		cnt += 2;
		check_l++;
		bool no_ans1 = false;
		while(!no_ans1 && cnt < n * 2){
			bool find = false;
//			cout << check_l << " " << kuai_l;
			if(!find && check_l < kuai_l){
				int nxt = pos[a[check_l]].r;
				if(nxt == kuai_l - 1){
					ans1+="L";
					ans2+="L";
					kuai_l--;
					cnt+=2;
					check_l++;
					find = true;
//					cout << "op1\n";
				}
				else if(nxt == kuai_r + 1){
					ans1+="L";
					ans2+="R";
					kuai_r++;
					cnt+=2;
					check_l++;
					find = true;
//					cout << "op2\n";
				}
			}
			if(!find && check_r > kuai_r){
				int nxt = pos[a[check_r]].l;
				if(nxt == kuai_l - 1){
					ans1+="R";
					ans2+="L";
					kuai_l--;
					cnt+=2;
					check_r--;
					find = true;
//					cout << "op3\n";
				}
				else if(nxt == kuai_r + 1){
					ans1+="R";
					ans2+="R";
					kuai_r++;
					cnt+=2;
					check_r--;
					find = true;
//					cout << "op4\n";
				}
			}
			if(!find) no_ans1 = true;
		}
		
		cnt = 0;
		check_l,check_r,kuai_l,kuai_r;
		check_l = 1,check_r = 2 * n,kuai_l = pos[a[check_r]].l,kuai_r = kuai_l;
		ans3 += "R",ans4 += "L";
		cnt += 2;
		check_r--;
		bool no_ans2 = false;
		while(!no_ans2 && cnt < n * 2){
			bool find = false;
//			cout << check_l << " " << kuai_l;
			if(!find && check_l < kuai_l){
				int nxt = pos[a[check_l]].r;
				if(nxt == kuai_l - 1){
					ans3+="L";
					ans4+="L";
					kuai_l--;
					cnt+=2;
					check_l++;
					find = true;
//					cout << "op1\n";
				}
				else if(nxt == kuai_r + 1){
					ans3+="L";
					ans4+="R";
					kuai_r++;
					cnt+=2;
					check_l++;
					find = true;
//					cout << "op2\n";
				}
			}
			if(!find && check_r > kuai_r){
				int nxt = pos[a[check_r]].l;
				if(nxt == kuai_l - 1){
					ans3+="R";
					ans4+="L";
					kuai_l--;
					cnt+=2;
					check_r--;
					find = true;
//					cout << "op3\n";
				}
				else if(nxt == kuai_r + 1){
					ans3+="R";
					ans4+="R";
					kuai_r++;
					cnt+=2;
					check_r--;
					find = true;
//					cout << "op4\n";
				}
			}
			if(!find) no_ans2 = true;
		}
		
		if(no_ans1 && no_ans2) cout << -1 << '\n';
		else if(no_ans2 ||(!no_ans2 && !no_ans1)){
			cout << ans1;
			for(int i = ans2.size();i > 0;i--){
				cout << ans2[i-1];
			}
			cout << '\n';
		}
		else if(no_ans1){
			cout << ans3;
			for(int i = ans4.size();i > 0;i--){
				cout << ans4[i-1];
			}
			cout << '\n';
		}
	}
}
