#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N;
    cin >> N;
    vector<uint> A(N), B(N);
    for (uint i = 0; i < N; i++) cin >> A[i] >> B[i];

    uint max_B_minus_A = 0U;
    for (uint i = 0; i < N; i++)
        max_B_minus_A = max(max_B_minus_A, B[i] - A[i]);

    uint64_t sum_of_A = reduce(A.begin(), A.end(), 0ULL);

    cout << sum_of_A + max_B_minus_A << '\n';

    return 0;
}
