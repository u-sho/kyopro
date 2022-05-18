#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
const long long MOD = 1'000'000'007;  //'

int main() {
    size_t N;
    cin >> N;
    vector<long long> A(N);
    for (long long &Ai : A) cin >> Ai;

    vector<long long> A_partial(N);
    partial_sum(A.begin(), A.end(), A_partial.begin());

    long long sum = 0LL;
    for (size_t i = 0; i < N - 1UL; i++) {
        // A_{i+1} から A_N までの総和
        long long sum_Aj_N = A_partial.at(N - 1UL) - A_partial.at(i);
        sum_Aj_N %= MOD;

        sum += sum_Aj_N * A.at(i);
        sum %= MOD;
    }

    cout << sum << "\n";

    return 0;
}
