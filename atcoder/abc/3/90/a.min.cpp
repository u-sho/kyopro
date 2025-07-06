#include<bits/stdc++.h>
using v=std::array<int,4>;int main(){v A;for(int&a:A)std::cin>>a;puts(A==v{1,2,3,5}||A==v{1,2,4,3}||A==v{1,3,2,4}||A==v{2,1,3,4}?"Yes":"No");}