#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[250001],lst[250001];
map<int,int> kl;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n;
    {
        map<int,int> mp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!mp[a[i]]) mp[a[i]]=++cnt,kl[cnt]=a[i];
            a[i]=mp[a[i]];
        }
    }
    for(int i=1;i<=n;i++){
        if(lst[a[i]]){
            for(int j=lst[a[i]]+1;j<i;j++) lst[a[j]]=0,a[j]=a[i];
        }
        lst[a[i]]=i;
    }
    for(int i=1;i<=n;i++) cout<<kl[a[i]]<<'\n';
}
