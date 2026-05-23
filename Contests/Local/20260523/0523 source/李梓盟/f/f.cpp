#include<bits/stdc++.h>
using namespace std;
int n,boat[3510],flag=1;
int main(){
    freopen("f.in","r",stdin);
    freopen("f.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>boat[i];
        if(boat[i]!=i) flag=0;
    }
    if(flag) cout<<(n+1)/2;
	else cout<<-1;
    return 0;
}

