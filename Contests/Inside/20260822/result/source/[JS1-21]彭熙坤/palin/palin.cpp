#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,T,a[MAXN],pos[MAXN],to[MAXN<<1],ans[MAXN*2];
char ans2[MAXN*2];
bool t[MAXN<<1],flag;
bool check(int x){
	if(x<1||x>n*2) return false;
	if(t[x]) return false;
	return true;
}
void print(int k,int l,int r){
	if(k>n*2){
		for(int i=1;i<=n*2;i++) printf("%c",ans2[i]);
		printf("\n");
		flag=true;
		return ;
	}
	if(a[l]==ans[k]){
		ans2[k]='L';
		print(k+1,l+1,r);
	}
	if(flag) return ;
	if(a[r]==ans[k]){
		ans2[k]='R';
		print(k+1,l,r-1);
	}
	return ;
}
void dfs(int k,int ch1,int ch2,int ch3,int ch4){
	if(k>n){
		flag=true;
		return ;
	}
	if(ch2<ch1&&ch2!=0) swap(ch1,ch2);
	if(ch1==0) swap(ch1,ch2);
	if(a[ch1]==a[ch3]&&ch1!=ch3){
		t[ch1]=t[ch3]=true;
		ans[k]=a[ch1];
		//ans2[k]='L';
		int tch1=0,tch2=0,tch3=0,tch4=0;
		if(check(ch1-1)) tch1=ch1-1;
		else if(check(ch1+1)) tch1=ch1+1;
		if(k==1){
			if(check(ch3-1)) tch2=ch3-1;
			if(check(ch3+1)) tch3=ch3+1;
			dfs(k+1,tch1,ch2,tch2,tch3);
		}
		else{
			if(check(ch3-1)) tch2=ch3-1;
			else if(check(ch3+1)) tch2=ch3+1;
			dfs(k+1,tch1,ch2,tch2,ch4);
		}
		t[ch1]=t[ch3]=false;
	}
	else if(a[ch1]==a[ch4]&&ch1!=ch4){
		swap(ch3,ch4);
		t[ch1]=t[ch3]=true;
		ans[k]=a[ch1];
		//ans2[k]='L';
		int tch1=0,tch2=0,tch3=0,tch4=0;
		if(check(ch1-1)) tch1=ch1-1;
		else if(check(ch1+1)) tch1=ch1+1;
		if(k==1){
			if(check(ch3-1)) tch2=ch3-1;
			if(check(ch3+1)) tch3=ch3+1;
			dfs(k+1,tch1,ch2,tch2,tch3);
		}
		else{
			if(check(ch3-1)) tch2=ch3-1;
			else if(check(ch3+1)) tch2=ch3+1;
			dfs(k+1,tch1,ch2,tch2,ch4);
		}
		t[ch1]=t[ch3]=false;
		swap(ch3,ch4);
	}
	if(flag) return ;
	if(a[ch2]==a[ch3]&&ch2!=ch3){
		swap(ch1,ch2);
		t[ch1]=t[ch3]=true;
		ans[k]=a[ch1];
		//ans2[k]='R';
		int tch1=0,tch2=0,tch3=0,tch4=0;
		if(check(ch1-1)) tch1=ch1-1;
		else if(check(ch1+1)) tch1=ch1+1;
		if(k==1){
			if(check(ch3-1)) tch2=ch3-1;
			if(check(ch3+1)) tch3=ch3+1;
			dfs(k+1,tch1,ch2,tch2,tch3);
		}
		else{
			if(check(ch3-1)) tch2=ch3-1;
			else if(check(ch3+1)) tch2=ch3+1;
			dfs(k+1,tch1,ch2,tch2,ch4);
		}
		t[ch1]=t[ch3]=false;
	}
	else if(a[ch2]==a[ch4]&&ch2!=ch4){
		swap(ch1,ch2);swap(ch3,ch4);
		t[ch1]=t[ch3]=true;
		ans[k]=a[ch1];
		//ans2[k]='R';
		int tch1=0,tch2=0,tch3=0,tch4=0;
		if(check(ch1-1)) tch1=ch1-1;
		else if(check(ch1+1)) tch1=ch1+1;
		if(k==1){
			if(check(ch3-1)) tch2=ch3-1;
			if(check(ch3+1)) tch3=ch3+1;
			dfs(k+1,tch1,ch2,tch2,tch3);
		}
		else{
			if(check(ch3-1)) tch2=ch3-1;
			else if(check(ch3+1)) tch2=ch3+1;
			dfs(k+1,tch1,ch2,tch2,ch4);
		}
		t[ch1]=t[ch3]=false;
	}
	return ;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++){
		memset(pos,0,sizeof(pos));
		flag=false;
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			scanf("%d",&a[i]);
			if(pos[a[i]]){
				to[i]=pos[a[i]];
				to[pos[a[i]]]=i;
			}
			else pos[a[i]]=i;
		}
		dfs(1,1,n*2,to[1],to[n*2]);
		if(flag){
//			int l=1,r=n*2;
//			for(int i=1;i<=n;i++){
//				if(a[l]==ans[i]){
//					printf("L");
//					l++;
//				}
//				else{
//					printf("R");
//					r--;
//				}
//			}
//			for(int i=n;i>=1;i--){
//				if(a[l]==ans[i]){
//					printf("L");
//					l++;
//				}
//				else{
//					printf("R");
//					r--;
//				}
//			}
//			printf("\n");
//			int l=1,r=n*2;
//			for(int i=1;i<=n;i++){
//				printf("%c",ans2[i]);
//				if(ans2[i]=='L') l++;
//				else r--;
//			}
//			for(int i=n;i>=1;i--){
//				if(a[l]==ans[i]){
//					printf("L");
//					l++;
//				}
//				else{
//					printf("R");
//					r--;
//				}
//			}
//			printf("\n");
			for(int i=1;i<=n;i++) ans[n*2+1-i]=ans[i];
			int l=1,r=n*2;
			flag=false;
			print(1,l,r);
		}
		else printf("-1\n");
	}
	return 0;
}
