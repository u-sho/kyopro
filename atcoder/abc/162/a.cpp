#include <bits/stdc++.h>
using ll = long long;

const std::string ans[2] = { "No\n", "Yes\n" };
constexpr ll MOD = 1'000'000'007;
// constexpr ll MOD = 998'244'353;
int main() {
    using namespace std;
    int n;
    cin >> n;
    cout << ans[(n/100==7 || (n/10)%10==7 || n%10==7)];
    return 0;
}