#include <bits/stdc++.h>
// const std::string ans[2] = {"No\n", "Yes\n"};

int main() {
    using namespace std;
    long long n,a,b;
    cin >> n >>a>>b;
    long long ans = (n / (a+b)) * a;
    ans += ((n % (a+b)) <a )?(n % (a+b)):a;
    cout << ans << endl;
    return 0;
}