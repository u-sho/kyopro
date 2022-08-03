#include <iostream>
#include <numeric>
#include <vector>

int main() {
    using std::cin;
    using std::cout;
    using std::vector;

    int N;
    cin >> N;
    vector<int> a(N);
    for (int &ai : a) cin >> ai;

    int sum_a     = std::accumulate(a.begin(), a.end(), 0);
    int average_a = sum_a / N;
    // cout << average_a << std::endl;
    if (sum_a != average_a * N) {
        cout << "-1\n";
        return 0;
    }

    int ans = 0;
    vector<int> sub(N);
    sub.at(0) = average_a - a.at(0);
    for (int i = 1; i < N; ++i) {
        sub.at(i) = sub.at(i - 1) + average_a - a.at(i);
        if (sub.at(i - 1)) ++ans;
    }

    cout << ans << '\n';

    return 0;
}