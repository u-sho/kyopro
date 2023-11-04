#include <iostream>
using namespace std;

uint64_t power(const uint64_t &n, const uint64_t &p) {
    uint64_t res = 1ULL;
    for (uint64_t i = 1ULL; i <= p; i++) res *= n;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint64_t B;
    cin >> B;

    for (uint64_t A = 1ULL; A < 16ULL; A++) {
        if (power(A, A) != B) continue;
        cout << A << '\n';
        return 0;
    }
    cout << "-1\n";

    return 0;
}