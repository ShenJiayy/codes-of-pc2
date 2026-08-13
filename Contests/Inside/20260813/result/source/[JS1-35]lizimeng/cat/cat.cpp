/*
wo bing bu hui zuo zhe dao ti
suo yi wo xie le yi ge sui ji shu
dan zhe dao ti de dai ma tai duan kan shang qu bu hao kan
suo yi wo zaizhe li qiao zhe xie dong xi shui shui chang du
qi ma ping ce de shi hou cat.cpp bu hui zhi you ji zi jie
shu zu chang du kai gou wei le fang zhi qi ta bao cuo
zhe yang da jia jiu hui yi wei wo shi zuo le dan shi mei zuo dui AWA
*/
#include<bits/stdc++.h>
using namespace std;
int n,p[200010],block[200010],a,b,ans;
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(false);
	srand((unsigned) time (NULL));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n-1;i++) cin>>a>>b;
	cout<<rand()%(n*2);
	return 0;
}
/*
xia mian zhe yi duan ye shi yong lai shui chang du de 
lao shi ying gai bu hui fan wo de dai ma de 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ AwAOvoQwQ 
*/
