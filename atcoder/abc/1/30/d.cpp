#include <iostream>
#include <numeric>
#include <vector>

int main() {
    using namespace std;

    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long& a : A) cin >> a;

    vector<long long> b(N);
    partial_sum(A.begin(), A.end(), b.begin());
    b.insert(b.begin(), 0LL);

    // しゃくとり法でK未満の部分列を数える
    long long less_than_k = 0LL;
    for (int l = 1, r = 1; l <= N && r <= N;) {
        long long sum = b.at(r) - b.at(l - 1);
        if (sum < K) {
            less_than_k++;
            if (N != r)
                r++;
            else
                l++;
        } else {
            l++;
            if (l > r) r++;
        }
    }

    // 部分列として有りうるのは，Σ{i|i∈[1,n]}comb(n,i) = 2^n - 1
    // ans = 2^n - 1 - less_tahan_k
    unsigned long long ans = (1 << N) - (1LL + less_than_k);

    cout << ans << '\n';

    return 0;
}
