#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main() {
    using lli = long long;
    lli n;
    cin >> n;

    vector<char> ans;
    while (n) {
        n--;
        ans.push_back('a' + n % 26LL);
        n /= 26LL;
    }
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans.at(i);
    }
    cout << '\n';
    return 0;
}