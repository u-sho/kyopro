#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint64_t a, b;
    cin >> a >> b;

    uint32_t counter = 0U;

    do {
        // if (max(a, b) - min(a, b) == 1) {
        //     counter += min(a, b);
        //     break;
        // }
        uint64_t g  = gcd(a, b);
        a          -= g;
        b          -= g;
        ++counter;
    } while (a && b);

    cout << counter << "\n";

    return 0;
}
