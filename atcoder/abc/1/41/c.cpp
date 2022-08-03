#include<iostream>
int i,j,n,k,q,a,p[100005];
int main(){
    std::cin>>n>>k>>q;
    for(;q>i++;)std::cin>>a,p[a]++;
    for(;++j<=n;)puts(k-q+p[j]>0?"Yes":"No");
    return 0;
}