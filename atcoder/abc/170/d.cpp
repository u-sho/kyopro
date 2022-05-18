#include <algorithm>
#include <iostream>
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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A.at(i);
    sort(A.begin(), A.end());

    vector<bool> warikireru(1000006);
    std::fill(warikireru.begin(), warikireru.end(), false);
    warikireru.at(1) = true;

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (warikireru.at(A.at(i))) continue;
        for (int j = 1; j * A.at(i) <= 1000000; ++j) {
            warikireru.at(j * A.at(i)) = true;
        }
        if (i == N - 1 || A.at(i) != A.at(i + 1)) ++ans;
    }

    cout << ans << '\n';
    return 0;
}