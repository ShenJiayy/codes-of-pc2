#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct qwq{//存储城市的结构体以及cmp
	int hi,id,pre,nxt;
}h[100005];
bool cmp(qwq x,qwq y){
	return x.hi<y.hi;
}
int choose(int a,int b,int i){//选择更优解
	if(!a)return h[b].id;
	if(!b)return h[a].id;
	if(h[i].hi-h[a].hi<=h[b].hi-h[i].hi)
	return h[a].id;
	else return h[b].id;
}
void del(int pos){//删除链表元素
	if(h[pos].nxt)h[h[pos].nxt].pre=h[pos].pre;
	if(h[pos].pre)h[h[pos].pre].nxt=h[pos].nxt;
}
int n,t;
int pos[100005],ga[100005],gb[100005];//一堆变量
int f[25][100005][2];
long long da[25][100005][2],db[25][100005][2],la,lb;
void calc(int s,long long x){//calc函数
	la=lb=0;
	int k=0;
	for(int i=t;i>=0;i--){
		if(f[i][s][k]&&da[i][s][k]+db[i][s][k]<=x){
			x-=da[i][s][k]+db[i][s][k];
			la+=da[i][s][k],lb+=db[i][s][k];
			if(!i)k^=1;
			s=f[i][s][k];
		}
	}
}
int main(){
//Part I——预处理ga和gb                                                   
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i].hi);
		h[i].id=i;
	}
	sort(h+1,h+1+n,cmp);
	for(int i=1;i<=n;i++){
		pos[h[i].id]=i;
		h[i].pre=i-1;
		h[i].nxt=i+1;
	}
	h[1].pre=h[n].nxt=0;
	for(int i=1;i<n;i++){
		int p=pos[i],p1=h[p].pre,p2=h[p].nxt;                                  
		if(p1&&(h[p].hi-h[p1].hi<=h[p2].hi-h[p].hi||!p2))      
		gb[i]=h[p1].id,ga[i]=choose(h[p1].pre,p2,p);
		else gb[i]=h[p2].id,ga[i]=choose(p1,h[p2].nxt,p);	
		del(p);
	}
//Part II——用倍增推出f,da,db                                                         
	for(int i=1;i<=n;i++){
		if(ga[i]){
			f[0][i][0]=ga[i];
			da[0][i][0]=abs(h[pos[i]].hi-h[pos[ga[i]]].hi);
			db[0][i][0]=0;	
		}
		if(gb[i]){
			f[0][i][1]=gb[i];
			da[0][i][1]=0;
			db[0][i][1]=abs(h[pos[i]].hi-h[pos[gb[i]]].hi);
		}	
	}
	t=(int)(log(1.0*n)/log(2)+1);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<=1;k++){
				int l=(i==1)?k^1:k;
				if(f[i-1][j][k])f[i][j][k]=f[i-1][f[i-1][j][k]][l];
				if(f[i][j][k]){
					da[i][j][k]=da[i-1][j][k]+da[i-1][f[i-1][j][k]][l];
					db[i][j][k]=db[i-1][j][k]+db[i-1][f[i-1][j][k]][l];
				}
			}
		}
	}
// Part III——计算calc得到答案                                  
	long long x;
	int s;
	scanf("%lld",&x);
	int p=0;
	long long ansa=1,ansb=0;
	for(int i=1;i<=n;i++){
		calc(i,x);
		if(!lb)la=1;
		if(la*ansb<lb*ansa||(la*ansb==lb*ansa&&h[pos[i]].hi>h[pos[p]].hi))
		ansa=la,ansb=lb,p=i;
	} 
	printf("%d\n",p);
	int m;
	scanf("%d",&m);
	while(m--){
		scanf("%d%lld",&s,&x);
		calc(s,x);
		printf("%lld %lld\n",la,lb);
	}
	return 0;
}
