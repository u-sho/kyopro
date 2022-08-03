#include <bits/stdc++.h>
// const std::string ans[2] = {"No\n", "Yes\n"};

int main() {
    using namespace std;
    long long x;
    cin >> x;
    long long ans = (x / 500LL) * 1000;
    ans += ((x % 500LL) / 5LL) * 5;
    cout << ans << endl;
    return 0;
}