#include<bits/stdc++.h>

#define L t<<1
#define R L|1
#define l(a) ST[a].l
#define r(a) ST[a].r
#define m(a) ST[a].Max
#define z(a) ST[a].lz

using namespace std;
const int Maxn = 1e6+10;
const int Inf = 0x7f7f7f7f;
int n, m;

struct seg{
	int l, r, len;
}s[Maxn];

bool cmp(seg x, seg y){
	return x.len < y.len;
}

struct SegmentTree{
	int l, r, Max, lz;
}ST[Maxn<<2]; 

void build(int t, int l, int r){
	l(t) = l, r(t) = r, m(t) = z(t) = 0;
	if( l == r )  return ;
	int mid = (l+r) >> 1;
	build(L, l, mid), build(R, mid+1, r);
}

void pushdown(int t){
	m(L) += z(t), z(L) += z(t);
	m(R) += z(t), z(R) += z(t);
	z(t) = 0;
}

void modify(int t, int l, int r, int v){
	if( r < l(t) || r(t) < l )  return ;
	if( l <= l(t) && r(t) <= r ){
		m(t) += v, z(t) += v;
		return ;
	}
	pushdown(t);
	modify(L, l, r, v), modify(R, l, r, v);
	m(t) = max(m(L), m(R));
}

vector<int> v;

int find(int x){
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int main(){
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
	scanf("%d %d", &n, &m);
	for(int i=1;i<=n;i++){
		scanf("%d %d", &s[i].l, &s[i].r);
		s[i].len = s[i].r - s[i].l;
		v.push_back(s[i].l), v.push_back(s[i].r);
	}
	build(1, 1, 2*n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	sort(s+1, s+1+n, cmp);
	int ans = Inf;
	for(int i=1,l=1;i<=n;i++){
		s[i].l = find(s[i].l), s[i].r = find(s[i].r);
		modify(1, s[i].l, s[i].r, 1);
		while( ST[1].Max >= m ){
			ans = min(ans, s[i].len - s[l].len);
			modify(1, s[l].l, s[l].r, -1);
			l++;
		}
	}
	printf("%d\n", ans == Inf ? -1 : ans);
} 