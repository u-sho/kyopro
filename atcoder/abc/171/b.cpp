#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int &pi : p) cin >> pi;

    std::sort(p.begin(), p.end());
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += p.at(i);
    }

    cout << ans << '\n';
    return 0;
}