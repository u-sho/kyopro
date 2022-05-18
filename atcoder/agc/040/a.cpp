#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string S;
    cin >> S;
    int a[500005];
    fill(a, a+500005, 0);
    long long ans=0LL;
    for(int i=0; i<S.length(); i++) {
        if (S[i] == '<'){
            a[i+1] = a[i]+1;
        }
    }
    for(int i=S.length()-1; i>=0; i--) {
        if (S[i]=='>') {
            a[i] = max(a[i+1] + 1,a[i]);
        }
    }
    for(int i=0; i<=S.length(); i++) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}