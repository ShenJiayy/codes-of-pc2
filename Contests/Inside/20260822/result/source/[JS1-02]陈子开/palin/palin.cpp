#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[2*N];
vector<char> ansl,ansr;
vector<int> ans;
pair<int,int> pos[N];
bool ed;
int n;
int now;
void dfsl(int l,int r,int pl,int pr);
void dfsr(int l,int r,int pl,int pr);

void checkl1(int l,int r,int pl,int pr) {
	if(a[l]==a[pl-1]) {
		ans.push_back(a[l]);
//		ansl.push_back('L');
		now++;
		dfsl(l+1,r,pl-1,pr);
		now--;
		ans.pop_back();
//		ansl.pop_back();
	}
	if(a[r]==a[pl-1]) {
		ans.push_back(a[r]);
//		ansl.push_back('R');
		now++;
		dfsl(l,r-1,pl-1,pr);
		now--;
		ans.pop_back();
//		ansl.pop_back();
	}
	return ;
}
void checkl2(int l,int r,int pl,int pr) {
	if(a[l]==a[pr+1]) {
		ans.push_back(a[l]);
//		ansl.push_back('L');
		now++;
		dfsl(l+1,r,pl,pr+1);
		now--;
		ans.pop_back();
//		ansl.pop_back();
	}
	if(a[r]==a[pr+1]) {
		ans.push_back(a[r]);
//		ansl.push_back('R');
		now++;
		dfsl(l,r-1,pl,pr+1);
		now--;
		ans.pop_back();
//		ansl.pop_back();
	}
	return ;
}
void dfsl(int l,int r,int pl,int pr) {
//	cerr<<l<<' '<<r<<' '<<pl<<' '<<pr<<'\n';
	if(now==n) {
		ed=true;
		return ;
	}
	if(a[l]==a[r]) {
		ans.push_back(a[l]);
		ans.push_back(a[r]);
		now++;
		dfsl(l+1,r-1,pl,pr);
	}
	else if(a[pl-1]<a[pr+1]) {
		checkl1(l,r,pl,pr);
		if(ed) return ;
		checkl2(l,r,pl,pr);
		if(ed) return ;
	}
	else {
		checkl2(l,r,pl,pr);
		if(ed) return ;
		checkl1(l,r,pl,pr);
		if(ed) return ;
	}
	return ;
}


void checkr1(int l,int r,int pl,int pr) {
	if(a[l]==a[pl-1]) {
		ans.push_back(a[l]);
//		ansr.push_back('L');
		now++;
		dfsr(l+1,r,pl-1,pr);
		now--;
		ans.pop_back();
//		ansr.pop_back();
	}
	if(a[r]==a[pl-1]) {
		ans.push_back(a[r]);
//		ansr.push_back('R');
		now++;
		dfsr(l,r-1,pl-1,pr);
		now--;
		ans.pop_back();
//		ansr.pop_back();
	}
	return ;
}
void checkr2(int l,int r,int pl,int pr) {
	if(a[l]==a[pr+1]) {
		ans.push_back(a[l]);
//		ansr.push_back('L');
		now++;
		dfsr(l+1,r,pl,pr+1);
		now--;
		ans.pop_back();
//		ansr.pop_back();
	}
	if(a[r]==a[pr+1]) {
		ans.push_back(a[r]);
//		ansr.push_back('R');
		now++;
		dfsr(l,r-1,pl,pr+1);
		now--;
		ans.pop_back();
//		ansr.pop_back();
	}
	return ;
}
void dfsr(int l,int r,int pl,int pr) {
	if(now==2*n) {
		ed=true;
		return ;
	}
	if(a[l]==a[r]) {
		ans.push_back(a[l]);
		ans.push_back(a[r]);
		now++;
		dfsr(l+1,r-1,pl,pr);
	}
	else if(a[pl-1]<a[pr+1]) {
		checkr1(l,r,pl,pr);
		if(ed) return ;
		checkr2(l,r,pl,pr);
		if(ed) return ;
	}
	else {
		checkr2(l,r,pl,pr);
		if(ed) return ;
		checkr1(l,r,pl,pr);
		if(ed) return ;
	}
	return ;
}



void solve() {
	{//¶ÁÈë£¬ÒÑÍê³É 
	memset(a,0x3f,sizeof a);
	cin>>n;
	for(int i=1;i<=2*n;i++) {
		cin>>a[i];
		if(pos[a[i]].first==0) {
			pos[a[i]].first=i;
		}
		else {
			pos[a[i]].second=i;
		}
	}
	}
	
	bool ifl=true,ifr=true;
	int l,r;
	//³¢ÊÔ×ó°ë±ß
	{ed=false;
	l=r=pos[a[1]].second;
	ans.push_back(a[1]);
	now=1;
	dfsl(2,2*n,l,r);
	cerr<<ans.size()<<'\n';
	if(ans.size()<20) ifl=false;
	else {
		l=1,r=n;
		for(int i=0;i<n;i++){
			int t=ans[i];
			if(a[l]==t) {
				ansl.push_back('L');
				l++;
			}
			else {
				ansl.push_back('R');
				r--;
			}
		}
		for(int i=n-1;i>=0;i--) {
			int t=ans[i];
			if(a[l]==t) {
				ansl.push_back('L');
				l++;
			}
			else {
				ansl.push_back('R');
				r--;
			}
		}
	}
//	for(int i=0;i<n;i++) cerr<<ans[i]<<' ';
//	for(int i=0;i<2*n;i++) cerr<<ansl[i]<<' ';
	ans.clear();}
	
	//³¢ÊÔÓÒ°ë±ß
	{ed=false;
//	ansr.push_back('R');
	l=r=pos[a[2*n]].first;
	ans.push_back(a[2*n]);
	now=1;
	dfsr(1,2*n-1,l,r);
	cerr<<ans.size()<<'\n';
	if(ans.size()<n) ifr=false;
	else {
		l=1,r=n;
		l=1,r=n;
		for(int i=0;i<n;i++){
			int t=ans[i];
			if(a[l]==t) {
				ansr.push_back('L');
				l++;
			}
			else {
				ansr.push_back('R');
				r--;
			}
		}
		for(int i=n-1;i>=0;i--) {
			int t=ans[i];
			if(a[l]==t) {
				ansr.push_back('L');
				l++;
			}
			else {
				ansr.push_back('R');
				r--;
			}
		}
	}
	for(int out:ans) cerr<<out<<' ';
	ans.clear();}
	
	{//Êä³öÒÑÍê³É£¬ÒÑ×¢ÊÍ 
	if(!ifl&&!ifr) {
		cout<<"-1\n";
		ansl.clear();
		ansr.clear();
		return ;
	}
	if(!(ifl&&ifr)) {
		if(ifl) {
			for(char c:ansl) {
				cout<<c;
			}
			cout<<'\n';
		}
		else {
			for(char c:ansr) {
				cout<<c;
			}
			cout<<'\n';
		}
		ansl.clear();
		ansr.clear();
		return ;
	}
	if(a[1]<a[n]) {
		for(char c:ansl) {
			cout<<c;
		}
	}
	else {
		for(char c:ansr) {
			cout<<c;
		}
	}
	cout<<'\n';}
	ansl.clear();
	ansr.clear();
	memset(pos,0,sizeof pos);
	return ;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("palin2.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	while(T--) solve();
	return 0;
}
/*
1
20
13 18 2 3 19 7 8 15 4 12 13 18 20 17 2 1 5 6 10 14
11 9 16 3 19 16 9 7 11 14 10 6 5 1 17 8 15 20 12 4
*/
//RRLLRRRRLRRRRRRRRRLLRRRRLRRRRRRRRLLRRRRL 
