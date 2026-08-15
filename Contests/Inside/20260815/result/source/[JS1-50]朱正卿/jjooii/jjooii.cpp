#include <bits/stdc++.h>
using namespace std;
long long n,k,ow[300000],jw[300000],iw[300000],oi,ji,ii,o2[300000],j2[300000],i2[300000],o3[300000],j3[300000],i3[300000],an=2147483647;
int main(){
	freopen("jjooii.in","r",stdin);
	freopen("jjooii.out","w",stdout); 
	cin>>n>>k;
	string kw;
	cin>>kw;
	long long i=1; 
	kw=" "+kw;
	while(1){
	//	cout<<i<<" ";
		if(kw[i]=='J'){
			ji++;
			if(ji!=1)j2[ji]=i-j3[ji-1]-(jw[ji-1]);
			j3[ji]=i;
			while(kw[i]=='J'&&i<kw.size()){
				i++;
				jw[ji]++;
			}
		}
		else if(kw[i]=='O'){
			oi++;
			if(oi!=1)o2[oi]=i-o3[oi-1]-ow[oi-1];
			o3[oi]=i;
			while(kw[i]=='O'&&i<kw.size()){
				i++;
				ow[oi]++;
			}
		//	cout<<i<<","<<o2[oi]<<' ';
		}
		else if(kw[i]=='I'){
			ii++;
			if(ii!=1)i2[ii]=i-i3[i-1]-iw[ii-1];
			i3[ii]=i;
			while(kw[i]=='I'&&i<kw.size()){
				i++;
				iw[ii]++;
			}
		}
//	/	/		cout<<kw.size()<<" ";
		if(i>=kw.size()){
			break;
		} 
	}
	j2[1]=o2[1]=i2[1]=0;
	for(long long i=1;i<=ji;i++)jw[i]+=jw[i-1],j2[i]+=j2[i-1];
	for(long long i=1;i<=oi;i++)ow[i]+=ow[i-1],o2[i]+=o2[i-1];
	for(long long i=1;i<=ii;i++)iw[i]+=iw[i-1],i2[i]+=i2[i-1];
//	/	/	cout<<ji<<' '<<oi<<' '<<ii<<'\n';
	for(long long i=1;i<=ji;i++){
		long long g=lower_bound(o3+1,o3+oi+1,j3[i])-o3;
		if(g>oi)continue;
		long long f=lower_bound(ow+1,ow+oi+1,k+ow[g-1])-ow;
		if(f>oi||o3[f]>i3[ii])continue;
		long long r=lower_bound(i3+1,i3+ii+1,o3[f])-i3;
		long long e=lower_bound(iw+1,iw+ii+1,k+iw[r-1])-iw;
		if(e>ii)continue;
		long long h=upper_bound(jw+1,jw+ji+1,jw[i]-k)-jw;
		if(jw[i]-jw[h-1]<k||h<1)continue;
	//	cout<<j2[i]-j2[h]<<' '<<o2[f]<<' '<<o2[g]<<' '<<o3[f]<<' '<<i3[r]-o3[f]-ow[f]+ow[f-1]<<" "<<o2[f]-o2[g]<<" ";
		an=min(j2[i]-j2[h]+o3[g]-j3[i]-(jw[i]-jw[i-1])+o2[f]-o2[g]+i3[r]-o3[f]-ow[f]+ow[f-1]+i2[e]-i2[r],n);
	//	cout<<i<<" ";
	} 
	if(an==2147483647){
		cout<<-1;
		return 0;
	}
	cout<<an;
	return 0;
}
