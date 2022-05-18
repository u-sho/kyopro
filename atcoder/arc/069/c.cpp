#include <bits/stdc++.h>
int main(){
    using namespace std;
    long long n,m;
    std::cin>>n>>m;

    long long ans =0LL;
    if(m/2<=n) ans = m/2;
    else {
        ans = n + (m-2*n)/4;
    }

    cout << ans << endl;

    return 0;
}