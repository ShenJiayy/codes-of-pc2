#include<bits/stdc++.h>
using namespace std;
int T;
void solve(){
	int n;
    cin>>n;
    vector<int> vec(2*n+5,0);
    for(int i=1;i<=2*n;++i){
        cin>>vec[i];
    }
    if(n<=10){
        for(int i=0;i<(1<<(2*n));++i){
            int seq[25]={0};
            int l=1,r=2*n;
            string str="";
            for(int j=2*n-1;j>=0;--j){
                if(i&(1<<j)){
                    seq[2*n-1-j]=vec[r];
                    --r;
                    str+="R";
                }
                else{
                    seq[2*n-1-j]=vec[l];
                    ++l;
                    str+="L";
                }
            }
            bool flag=true;
            for(int j=0;j<n;++j){
                if(seq[j]!=seq[2*n-1-j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<str<<"\n";
                return;
            }
        }
        cout<<-1<<"\n";
        return;
    }
    else{
    	
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>T;
	while(T--) solve();
	return 0;
} 
