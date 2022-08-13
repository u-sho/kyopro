#include <bits/stdc++.h>
int main(){
    int t;
    std::cin >> t;
    while(t--){
        long long a,b,c,d;
        std::cin>>a>>b>>c>>d;
        long long x=b,y=c,z=c;
        if(x+y>z) std::cout << x << ' ' << y << ' ' << z << std::endl;
        else assert(false);
    }
    return 0;
}