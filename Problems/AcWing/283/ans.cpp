// #include <bits/stdc++.h>
// using namespace std;

// int a[105];
// char b[105];
// int dpmax[105][105];
// int dpmin[105][105];

// int main()
// {
//     int n; 
//     int ret = 0;
//     scanf("%d",&n);

//     for(int i = 1; i <= 2*n; ++i) {
//         if(i % 2 == 1) {

//             cin>>b[(i/2)+1];
//             b[(i/2)+1+n] = b[(i/2)+1];
//         } 
//         if(i % 2 == 0) {
//             cin>>a[i/2];
//             a[i/2+n] = a[i/2];
//         }
//     }

//     memset(dpmax,128,sizeof(dpmax));
//     memset(dpmin,0x3f3f,sizeof(dpmin));

//     for(int i = 1; i <= 2*n; ++i) {
//         dpmax[i][i] = a[i];
//         dpmin[i][i] = a[i];
//     }

//     for(int len = 1; len <= n; ++len)
//         for(int l = 1; l + len <= 2*n; ++l) {
//             int r = l + len;

//             for(int k = l; k < r; ++k) {
//                 if(b[k+1] == 't') {
//                     //cout<<"t"<<" ";
//                     dpmax[l][r] = max(dpmax[l][r],dpmax[l][k] + dpmax[k+1][r]);
//                     dpmin[l][r] = min(dpmin[l][r],dpmin[l][k] + dpmin[k+1][r]);
//                 } else {
//                     //cout<<"m"<<" ";
//                     dpmax[l][r] = max(dpmax[l][r],dpmax[l][k]*dpmax[k+1][r]);
//                     dpmax[l][r] = max(dpmax[l][r],dpmin[l][k]*dpmin[k+1][r]);
//                     dpmin[l][r] = min(dpmin[l][r],dpmin[l][k]*dpmin[k+1][r]);
//                     dpmin[l][r] = min(dpmin[l][r],dpmax[l][k]*dpmin[k+1][r]);
//                     dpmin[l][r] = min(dpmin[l][r],dpmin[l][k]*dpmax[k+1][r]);
//                 }
//             }
//             //cout<<l<<" "<<r<<" "<<dpmax[l][r]<<" "<<dpmin[l][r]<<" ";
//         }

//     for(int i = 1; i <= n; ++i) ret = max(ret,dpmax[i][i+n-1]);

//     printf("%d\n",ret);

//     //cout<<dpmax[2][5]<<" "<<a[2]<<" ";

//     for(int i = 1; i <= n; ++i) 
//         if(dpmax[i][i+n-1] == ret) printf("%d ",i);


//     return 0;
// }