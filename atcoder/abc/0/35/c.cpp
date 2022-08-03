#include <algorithm>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;

int main() {
    int n, q;
    cin >> n >> q;

    std::vector<bool> range(n + 2);
    std::fill(range.begin(), range.end(), false);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        range.at(l)     = !range.at(l);
        range.at(r + 1) = !range.at(r + 1);
    }

    bool iswhite = false;
    for (int i = 1; i <= n; ++i) {
        if (range.at(i)) iswhite = !iswhite;
        cout << (iswhite ? '1' : '0');
    }
    cout << '\n';
    return 0;
}