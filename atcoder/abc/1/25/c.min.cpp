#include<iostream>
#include<atcoder/all>
using namespace std;int N,a,i;main(){cin>>N;atcoder::segtree<int,[](int n,int m){return gcd(n,m);},[](){return 0;}>A(N);for(;i<N;A.set(i++,a))cin>>a;for(a=0;i--;)a=max(a,gcd(A.prod(0,i),A.prod(i+1,N)));cout<<a;}
