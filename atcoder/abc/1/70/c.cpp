#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

using std::make_pair;
using std::pair;

using std::max;
using std::min;
using std::sort;

using std::cin;
using std::cout;

using std::vector;

int main() {
    int X, N;
    cin >> X >> N;
    vector<int> p;
    for (int i = 0; i < N; ++i) {
        int pi;
        cin >> pi;
        p.push_back(pi);
    }
    sort(p.begin(), p.end());

    int ans = 101;
    for (int i = 101; i >= 0; --i) {
        bool f = true;
        for (int j = 0; j < N; ++j) {
            if (i == p[j]) f = false;
        }
        if (!f) continue;
        if (llabs(i - X) <= llabs(ans - X)) ans = i;
    }

    cout << ans << '\n';

    return 0;
}