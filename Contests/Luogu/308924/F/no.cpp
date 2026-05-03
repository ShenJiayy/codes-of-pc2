#include<bits/stdc++.h>

using namespace std;
struct node{
	int w,c,d;
};
priority_queue<node>heap;
int n,a[200011]={0},vis[200011]={0},cnt=0,ans1[200011]={0},ans2[200011]={0},nxt[200011]={0},prv[200011]={0},nxtlaprv=1;
bool operator<(node a,node b){
	if(a.w==b.w)return a.c>b.c;
	else return a.w>b.w;
}
string s;
int main(){
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	s+='H';
	for(int i=1;i<n;i++){
		if(s[i-1]!=s[i])heap.push((node){abs(a[i]-a[i+1]),i,i+1});
	}
	for(int i=1;i<=n;i++){
		nxt[i]=i+1;
		prv[i]=i-1;
	}
	while(heap.empty()==0){
		node t=heap.top();
        heap.pop();
		int p=t.c,q=t.d;
		if(vis[p]==0&&vis[q]==0){
			nxt[prv[p]]=nxt[q];
			prv[nxt[q]]=prv[p];
			cnt+=1;
			ans1[cnt]=p,ans2[cnt]=q;
			vis[p]=1,vis[q]=1;
			if(vis[prv[p]]==0&&vis[nxt[q]]==0){
				if((s[prv[p]-1]+s[nxt[q]-1])==('G'+'B')){
                    heap.push((node){abs(a[prv[p]]-a[nxt[q]]),prv[p],nxt[q]});
                }
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<ans1[i]<<" "<<ans2[i]<<endl;
	}
	return 0;
}
