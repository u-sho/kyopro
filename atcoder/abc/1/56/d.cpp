#include <bits/stdc++.h>
using ll = long long;

constexpr ll MOD = 1'000'000'007;

ll comb (ll n, ll r) {
    r = std::min(r, n-r);
    if(r=0) return 1LL;
    if(r=1) return n;

    ll retVal = 1LL;
    for (ll i=0LL; i<r; i++) {
        retVal = retVal * (n-i) % MOD; // retVal = n! / (n-r)!
        retVal = retVal / (i+1LL) % MOD; // retVal /= r!
        retVal %= MOD;
    }
    return retVal;
}

int main() {
    using namespace std;
    ll n,a,b;
    cin >> n >> a >> b;

    if(n == 2){
        cout << '0';
        return 0;
    }

    // a,bを覗かない場合，Σ(n,r) = 2^n - 1
    // nCa + nCb = 
    ll ans = (comb(n, a) + comb(n,b)) % MOD;
    
    for(int i=0; i<n;){

        ans << 1;
        ans %= MOD;
    }
    ans--;

    //
    cout << ans << endl;
    ans -= (comb(n, a) + comb(n,b)) % MOD;
    if(ans < 0){
        ans += MOD;
    }

    cout << ans << endl;

    return 0;
}
