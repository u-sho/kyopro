#include <bits/stdc++.h>
using ll = long long;

const std::string ans[2] = { "No\n", "Yes\n" };
constexpr ll MOD = 1'000'000'007;
// constexpr ll MOD = 998'244'353;
int main() {
    using namespace std;
    int n,r;
    cin>>n>>r;
    int ir=r;
    if(n<10){
        ir+=100*(10-n);
    }
    cout << ir << endl;
    return 0;
}
