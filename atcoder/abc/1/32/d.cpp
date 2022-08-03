#include <iostream>
#include <algorithm>
using namespace std;

const long long MOD = 1'000'000'007;

long long N, K;

long long nCr(int n, int r) {
    if(n<r) return 0LL;
    if(n-r<r) r = n-r;
    if(r==0) return 1LL;
    if(r==1) return (long long)n;

    long long retval = 1LL;
    for(int i=0; i<r; i++){
        retval *= (long long)(n-i);
        retval /= (long long)(i+1);
        retval %= MOD;
    }

    return retval;
}

long long solve(int i){
    long long ans = nCr(N-K+1,i) * nCr(K-1,i-1);
    return ans%MOD;
}

int main(){
    cin >> N >> K;
    for (int i = 1; i <= K; i++){
        cout << solve(i) << endl;
    }
    return 0;
}