#include <bits/stdc++.h>
int main(){
    constexpr long long MOD = 1'000'000'007; //'
    long long n;
    std::cin>>n;

    long long ans=1LL;
    for(int i=1; i<=n; i++){
        ans *= i;
        ans %= MOD;
    }

    std::cout<<ans<<std::endl;
    return 0;
}