#include <cstdio>
const int base= 10000;
int two(int x){
    if(!x) return 1;
    int d= two(x/2);
    d=d *d%base;
    if(x&1) return d * 2%base;
    return d;
}
int f(int x){
    int rst=0, i,L;
    for(i=1,L=1;i<=x/10;i*=10,L++)
    rst=(rst+i%base*9 * L)% base;
    return (rst+(x-i+1)%base * L)% base;
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(n% base+2*(n-1)% base+(f(n)+ base-1)% base+two(n-1)*((n+f(n))% base)% base+ two(n)+ base-1)% base);
    return 0;
}